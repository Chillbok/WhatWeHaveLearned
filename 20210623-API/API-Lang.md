# API에서의 입출력(기본)

---

<br>
<br>

# 목차

---

<details>
<summary>눌러서 목차 펼치기</summary>

</details>

<br>
<br>

# 입력

---

nvalidateRect(hWnd, NULL, true)

출력할 창인 hWnd를 NULL을 통해 초기화한다.


VK

---

버추얼 키. 화살표 키를 이용한다.
종류:

D:\이준호\GitFiles\WhatWeHaveLearned\20210623-API

1. `hdc` = 화면 출력과 관련된 구조체.
    - 어떤 윈도우를 출력할 것인가?
2. `hWnd` = 화면 선택과 관련된 구조체. h는 HANDLE의 h이다. 데이터 타입은 윈도우 핸들이다.
3. `w`(헝가리안법): 해당 글자가 헝가리안법 형식으로 붙는다면 키보드의 입력과 관련된 변수이다.
    - 대표적인 예시로 `wParam`이 있다.
4. `l`(헝가리안법): 해당 글자가 헝가리안법 형식으로 붙는다면 마우스의 입력과 관련된 변수이다.
    - 대표적인 예시로 `lParam`이 있다.

<br>

---

**이 점을 알아두자:**

|<span style="color:red">프로그램은 해당 변수들을 통해 받은 입력 정보를 바탕으로 프로그램을 실행한다.</span>|
|:---:|

<br>

## 키보드와 마우스

---

|항목|내용|
|:---:|:---|
|중요 예약어|`wParam`, `lParam`|
|작성하는 곳|`LRESULT CALLBACK WndProc()`/`switch(message)`/맨 앞쪽|

### `static /*변수*/;`

---

**형태:**

```C++
static int x, y;//1회가 종료되면 값이 초기화될 지역변수들

switch (message)
{
case WM_CREATE://변수 대입
    x = 100;
    y = 100;
    break;

case WM_KEYDOWN://입력받고, 입력받았을 시 반응
    switch(wParam)
    //wParam일 경우에는 마우스 버튼과 키보드 입력
    //lParam일 경우에는 마우스 움직임 입력
    {
    case VK_UP://방향키(위)
    //VK_DOWN(방향키 아래), VK_LEFT(방향키 왼쪽), VK_RIGHT(방향키 오른쪽)
        {

        }
    }

```C++
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM, lParam)
{
    switch(message)//1회가 종료되면, 이 안의 지역변수들의 값은 초기화된다.
    {
    case WM_CREATE:

        break;
    
    case WM_LBUTTONDOWN:
        {
            hdc = BeginPaint(hWnd, &ps);

            Rectangle(hdc, 200, 200, 300, 300);

            EndPaint(hWnd &ps);
        }

        break;

    //이하 생략
    }
}
```
---




# `wParam`

---

버튼 처리와 관련된 정보를 받는다.

주의할 점은, 마우스의 "**버튼**"도 이 "**정보**"에 해당한다.


# `lParam`

---

`Long Parameter` => `lParam`

마우스의 움직임과 관련된 정보를 받는다.

주의할 점은, 앞서 말했듯이 마우스의 버튼을 클릭하는 것은 `wParam`에 포함되는 것이고, `lParam`에 포함되지는 않는다는 것이다.

`lParam`에는 마우스 위치에 대한 정보가 들어온다. 화면 상에서 마우스를 움직일 때에는 X 좌표, Y 좌표, 총 2가지가 존재한다. 하지만, `lParam`에 들어가는 정보는 하나뿐이다. 따라서, `lParam`에 들어가는 값은 X 좌표와 Y 좌표가 혼용되는 것이다.

## X 좌표와 Y 좌표의 혼동

---

|Full Name|Using Name|bit|byte|
|:---:|:---:|---:|---:|
|WORD Parameter|wParam|32|8|
|Long Parameter|lParam|32|8|

`lParam`은 `wParam`의 2배라고 생각하면 이해하기 쉽다. 다만, `wParam`이 2개 들어간 것이 `lParam`이 아니라는 것은 반드시 명심하도록 하자.

|wParam의 경우||
|:---:|:---|
|WORD|FF FF FF FF FF FF FF FF|

|lParam의 경우||
|LOWORD|FF FF FF FF FF FF FF FF|
|HIWORD|FF FF FF FF FF FF FF FF|

위에서 볼 수 있듯이, `lParam`은 `wParam`에 비해 양이 2배이다. 앞부분에 `LOWORD`가 들어가고, 뒷부분에 `HIWORD`가 들어간다.

`LOWORD`는 X좌표를, `HIWORD`는 Y좌표를 의미한다.




# `WM_MOUSEMOVE`

---

`lParam`은 마
