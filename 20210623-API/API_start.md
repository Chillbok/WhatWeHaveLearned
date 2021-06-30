# 1. 코드 옮기기

---

```C++
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            //메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            EndPaint(hWnd, &ps);
        }
        break;
        ...
    }
}
```

여기에서 `case WM_PAINT`조건 안에 있는 `PAINTSTRUCT ps;`와 `HDC hdc = BeginPaint(hWnd, &ps);`를 옮겨준다.

옮기는 위치는 `LRESULT CALLBACK WndProc()` 함수 바로 아래이다. 다음과 같이 옮겨준다:

```C++
LRESULT CALLBACK WndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc;
    ...
}
```


# 정리한 내용

---

> <span style="color:red">**아래 내용은 외우도록 하자.**</span>
> 1. *선택되어있는 DC는 편집, 생성, 삭제가 불가능하다.*
> 2. *이미지를 출력하기 전 해당 이미지의 DC를 선택해준다.*
> 3. *이미지를 출력한다.*
> 4. *출력 후 메모리를 해제한다.*

# `DC`

---

`DC`라는 것은 `Device Context`의 약자이다.
API에서는 GDI 모듈이라는 것에 의해 그림 파일이나 점과 선과 면을 출력할 수 있다.

> GDI는 `G`rapic `D`evice `I`nterface의 약자이다.

## `HDC`

---

`DC` 핸들에 대한 구조체. `HDC`에서의 `H`는 핸들을 의미한다.

출력에 관련된 모든 정보를 가지고 있는 구조체이다.

예를 들어 일정 길이의 선을 그린다고 가정해보자. 선의 시작점과 선의 끝점의 좌표만 알면 바로 구할 수 있는가?

**아니다.** 선 하나를 그리기 위해서는 굉장히 많은 정보가 필요하다.

시작점 좌표, 끝점 좌표, 선 모양, 길이, 각도, 굵기, 색상, 이 여러가지 요소들을 설정해주어야만 마침내 선을 그릴 수 있는 것이다.

`hdc`는 이런 "*출력*"에 대한 정보를 모두 포함하고 있는 아주 중요한 구조체이다. 

hdc를 사용하면, 시작점 좌표와 끝점 좌표만 사용해서 선을 그릴 수 있다.

```C++
//static POINT aa = {aa.x, aa.y};
static POINT aa = {0,0};//이전 cp값(커서 포인트)를 받아온다.

//MoveToEx(/*어디에 작성할지*/, /*x좌표*/, /*y좌표*/, /*이전 커서 위치(극소수의 상황을 제외하고는 알 이유가 없기 때문에 보통 NULL을 작성한다)*/);
MoveToEx(BackDC, 100,100, &aa);//시작점 위치 선언하는 함수
//LineTo(/*작성할 화면*/, /*x좌표*/, /*y좌표*/);
LineTo(BackDC, 200,100);//끝점 위치 선언하는 함수
```

`DC` 안에 이런 정보에 대한 Default값들이 설정되어있기 때문에, 일반적인 상황에서는 그냥 사용하되, `DC` 안에 들어있는 선의 기본 정보(검은색, 두께 1, 실선)가 아닌 다른 값을 사용하고 싶은 경우에만 그 값들을 변경시키면 된다.

만약에 `MoveToEx` 함수를 제외하고 LineTo만 작성한다면, 시작점은 자동으로 `(0,0)`으로 선언된다.

<br>

## `HPEN`

---

```C++
//DC들과 동일하게 Mypen과 Oldpen을 모두 구현시켜주어야 한다.
HPEN MyPen, OldPen;
MyPen = CreatePen(PS_DASHDOTDOT, 5, RGB(255,-,-));
OldPen = (HPEN)SelectObject(BackDC, MyPen);
```

<br>

## `HFONT`

---

```C++
HFONT MyFont, OldFont;
MyFont = CreateFont();
```

<br>

## 예시

---

```C++
//DC들과 동일하게 Mypen과 Oldpen을 모두 구현시켜주어야 한다.
HPEN MyPen, OldPen;
MyPen = CreatePen(PS_DASHDOTDOT, 5, RGB(255,-,-));
OldPen = (HPEN)SelectObject(BackDC, MyPen);

MoveToEx(BackDC, 100,100, NULL);
LineTo(BackDC, 200,100);

SelectObject(BackDC, OldPen);
DeleteObject(MyPen);
```






















관련된 구조체로 `HBITMAP`이 있다.

우리가 찍고 싶은 이미지는 `MyBitmap`에 담겨있는 이미지.
초기 상태의 `MyBitmap`은 편집이 불가능한 상태.
`MyBitmap`을 편집하기 위해서 -> `OldBitmap`을 선택한다.(1번에 1개만 선택 가능)

`OldBitmap`을 선택함으로써 `MyBitmap`에 대한 편집이 가능해졌다.
`MyBitmap`에 파일에 대한 정보를 담는다.

```C++
MyBitmap = (HBITMAP)LoadImage(NULL, TEXT("ship.bmp"),
        IMAGE_BITMAP, 0,0, LR_LOADFROMFILE | LRCREATEDIBSECTION);
```

현재 선택은 무엇으로 되어있는가?
    -> `OldBitmap`이 선택되어있는 상태.
```C++
SelectObject(ShipDC, MyBitmap);
```

`MyBitmap` 정보가 담긴 `ShipDC`를 `BackDC`에 출력해준다.

```C++
BitBlt(BackDC, 0,0,30,32, ShipDC, 0,0, SRCCOPY);

DeleteObject(SelectObject(BackDC, OldBitmap));
DeleteObject(MyBitmap);
DeleteDC(BackDC);
DeleteDC(ShipDC);
```


