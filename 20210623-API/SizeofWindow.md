# 윈도우 창 사이즈 설정하기

---

이미지를 움직일 때마다 배경화면이 깜박이는 문제가 발생한다. 어떻게 해결할까?

`BOOL InitInstance()` 함수의 `HWND hWnd = CreateWindowW()` 매크로를 확인하자.

```C++
HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW, CW_USERDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
```

조금 위로 올려보면 `MyRegisterClass`라는 클래스를 확인할 수 있을 것이다. `CreateWindowW` 매크로의 `szWindowClass`는 여기에서 정보를 가져온다.

그 옆에 있는 `szTitle`은 포인터이다. `WCHAR szTitle[MAX_LOADSTRING]`의 형태로, 코드 맨 위쪽에 선언되어 있다. 제목 표시줄 텍스트이다.

`CW_USEDEFALUT, 0, CW_USEDEFAULT, 0`은 창의 사이즈를 적는 곳이다. 예를 들어, 1920 X 1080 사이즈로 창을 출력하고 싶다면, `0, 0, 1920, 1080`을 해당 자리에 입력하면 된다.

<br>
<br>

# 시작

---

## 1. 윈도우 창 사이즈 선언
---

코드에서 헤더 파일들을 포함하는 곳, `#include`를 통해 선언한 곳 바로 아래에 두 해상도를 선언한다. 사용하는 예약어는 `#define`이다.

```C++
#include "framework.h"
#include "API_day2.h"

#define WindowX 1024//생성되는 윈도우의 X축 해상도
#define WindowY 768//생성되는 윈도우의 Y축 해상도
```

<br>

## 2. 윈도우 창 사이즈 설정

---

선언한 이름에서 알 수 있듯이, `WinsizeX`와 `WinsizeY`는 각각 프로그램 디버깅 시 생성될 윈도우 창의 크기를 의미한다.

단, 주의해야 할 점이 있다. 이 사이즈는 *창 배경화면 뿐만이 아니라 리본 메뉴도 포함*이라는 것이다. 따라서 제대로 된 해상도에 맞는 크기를 만들고 싶다면, 리본 메뉴를 비롯한 화면에 포함되지 않는 프로그램 외적 요소의 크기를 더한 만큼의 사이즈를 빼야한다.

`BOOL InitInstance(HINSTANCE hInstancer, int nCmdShow)` 바로 아래에 만들도록 하자.

```C++
int WinsizeX, WinsizeY;//
WindowX = WinsizeX + GetSystemMetrics(SW_CXDLGFRAME) * 2;
WindowY = WinsizeY + GetSystemMetrics(SM_CYMENU) + GetSystemMetrics(SM_CYCAPTION);
```

여기에서 `GetSystemMetrics()`의 소괄호 부분에 포함시킨 `SW_CMDLGFRAME` 부분과 `SM_CYMENU`, `SM_CYCAPTION`는 리본 메뉴, 스크롤 바 등을 포함한 출력되는 배경 외적 요소들이다.
