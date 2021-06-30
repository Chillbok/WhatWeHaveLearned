# API에서 스프라이트 이미지 이용해서 애니메이션 연출하기

---

## 선언

---

`case WM_PAINT:` 바로 아래에 작성한다.

```C++
case WM_PAINT:
    {
        BackDC = CreateCompatibleDC(hdc);
        CharacterDC = CreateCompatibleDC(hdc);//이렇게 CharacterDC라는 DC를 선언해준다.
        BgDC = CreateCompatibleDC(hdc);
        BackBitmap = CreateCompatibleBitmap(hdc, WINDOW_X, WINDOW_Y);
        OldBitmap = (HBITMAP)SelectObject(BackDC, BackBitmap);
    }
```   

그리고, 초기화시킬 때 지우고 다시 작성하도록 하기 위해서 `DeleteDC`를 사용하도록 하자.

`case WM_PAINT:` 항목의 맨 아래, `EndPaint(hWnd, &ps);`의 바로 위에 작성한다.

```C++
case WM_PAINT:
{
    //...

    DeleteObject(MyBitmap);
    DeleteDC(CharacterDC);
    EndPaint(hWnd, &ps);
}
break;
```

<br>

### `case WM_PAINT`

---

<br>
<br>

# 전체 코드

---

```C++
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc = {};
    HDC BackDC = {};
    HDC BgDC = {};//배경화면
    HDC CharacterDC = {};//캐릭터

    HBITMAP BackBitmap;//더블 버퍼링용 비트맵
    HBITMAP OldBitmap;//오래된 비트맵
    HBITMAP MyBitmap;

    static POINT ptCharPos;

    switch (message)
    {
    case WM_TIMER:
        switch(wParam)
        {
        case 0:
            break;
        case 1:
            iframe++;
            break;
        }
        break;
    case WM_CREATE:
        SetTimer(hWnd, 0, 17, NULL);//0.017초마다 자동 갱신
        ptCharPos.x = 608;
        ptCharPos.y = 454;

        rt.left = 0;
        rt.top = 0;
        rt.right = WINDOW_X;
        rt.bottom = WINDOW_Y;

        break;
    case WM_KEYDOWN:
        switch(wParam)
        {
        case VK_UP:
            {
                ptCharPos.y -= 10;
            }
            break;
        case VK_DOWN:
            {
                ptCharPos.y += 10;
            }
            break;
        case VK_LEFT:
            {
                ptCharPos.x -= 10;
            }
            break;
        case VK_RIGHT:
            {
                ptCharPos.x += 10;
            }
            break;
        }
        InvalidateRect(hWnd, NULL);
        break;
    case WM_COMMAND:
        {
            int wnId = LOWORD(wParam);

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
            //TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...

            //DC 생성
            BackDC = CreateCompatibleDC(hdc);
            BgDC = CreateCompatibleDC(hdc);
            CharacterDC = CreateCompatibleDC(hdc);
            BackBitmap = CreateCompatibleBitmap(hdc, WINDOW_X, WINDOW_Y);
            OldBitmap = (HBITMAP)SelectObject(BackDC, BackBitmap);

            BITMAP MyBitmap, OldBitmap, BackBitmap;

            RECT rt = {0,0,WINDOW_X,WINDOW_Y};
            //HBITMAP 생성
            BackBitmap = CreateCompatibleBitmap(hdc, WINDOW_X, WINDOW_Y);
            OldBitmap = (HBITMAP)SelectObject(BackDC, BackBitmap);
            //이건 그냥 배경이 백버퍼 썼을 때 검은 게 싫어허 하얗게 찍으려고 넣은 것이다.
            //즉, 없어도 된다.
            FillRect(BackDC, &rt, (HBRUSH)GetStockObject(WHITE_BRUSH));

            SelectObject(BgDC, MyBitmap);
            BitBlt(BackDC, 0,0, WINDOW_X, WINDOW_Y, BgDC, 0,0, SRCCOPY);

            MyBitmap = (HBITMAP)LoadImage(NULL, TEXT("character.bmp"), IMAGE_BITMAP, 0,0,LR_LOADFROMFILE | LR_CREATEDIBSECTION);

            SelectObject(CharacterDC, MyBitmap);
            BitBlt(BackDC, ptCharPos.x, ptCharPos.y, 64, 96,
                    CharacterDC, 0,0,32,48, RGB(255,0,255));

            //BackDC의 것을 메인 DC로 복사한다.
            BitBlt(hdc, 0,0,32,48, BackDC, 0,0,SRCCOPY);

            DeleteObject(MyBitmap);
            DeleteDC(CharacterDC);
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        KillTimer(hWnd, 0);
        KillTimer(hWnd, 1);
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}
```
