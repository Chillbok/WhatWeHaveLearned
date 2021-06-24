# 1. 코드 옮기기

---

> 옮길 코드: `PAINTSTRUCT ps;`, `HDC = BeginPaint(hWnd, &ps);`
> 위치: `LRESULT CALLBACK WndProc()`/바로 아래

<br>
<br>

# 2. 헤더파일 추가하기

---

> 수정할 파일: `framework.h`
> 추가할 파일: `string`

맨 마지막 줄에 추가!

```C++
#include <string>
```

<br>
<br>

# 3. 지역변수 추가

---

> **작성 위치:** `LRESULT CALLBACK WndProc()`/바로 아래

```C++
PAINTSTRUCT ps;
HDC hdc = BeginPaint(hWnd, &ps);

static RECT rect;
RECT Mousept;

POINT pt;
```

<br>
<br>

# X와 Y좌표 위치 대입

---

> **작성 위치:** `LRESULT CALLBACK WndProc()`/`switch(message)`/`case WM_LBUTTONDOWN:`

```C++
case WM_LBUTTONDOWN:
    pt.x = LOWORD(lParam);
    pt.y = HIWORD(lParam);
```

# `if(IntersectRect(&rcTemp, &rect, &Mousept) == true)`

---

소괄호 안에 첫번째로 적은 RECT와 두번째로 적은 RECT의 교집합을 확인하는 함수.

겹치면 true, 겹치지 않으면 false를 반환한다.
