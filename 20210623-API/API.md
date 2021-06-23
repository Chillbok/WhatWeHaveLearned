# API

***

<br>
<br>

# 목차

***

<details>
<summary>눌러서 목차 열기</summary>

</details>

<br>
<br>

# 1. API란?

***

> Application Programming Interface

클래스와 비슷한 개념이다.

API 안에는 다양한 함수들이 존재한다.

## 1.1. API가 프로그램에서 가지는 의미는?

***

게임을 만들 때에는 DirectX(이것도 클래스)를 사용한다.

DX 안은 여러개의 API들로 이루어져있는데, 이 API들은 MFC에 의해 묶여진다.

> MFC: Microsoft Foundation Class

<br>
<br>

# 2. 입출력하는 위치

---

입출력을 하는 곳은 `case WM_PAINT`이다.

이렇게 구성되어 있다:

```C++
case WM_PAINT:
{
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hWnd, &ps);
    //TODO: 여기에 hdc를 사용하는 그리기 소스를 추가합니다...
    EndPaint(hWnd, &ps);
}
```

<br>
<br>

# 3. API에서의 입출력

---

## 3.1. `TextOut`

---

API에서 출력을 할 때에는 여러가지 방법이 있다.

그 중 첫번째 방법은 바로 `TextOut`를 사용하는 것이다.

다음은 예시이다:

```C++
TextOut(HDC hdc, int X, int Y, LPCWSTR lpstring, int c);
```

**여기에서 hdc는, 화면 출력에 대한 정보를 담고 있는 구조체이다.**

출력에 필요한 정보를 가져올 수 있는 데이터 구조체이다.

**int 형태의 변수인 X와 Y는 텍스트가 출력될 위치이다.**

**lstring은 출력될 문구이다.**

**c는 몇 바이트(byte)를 출력할 것인지를 적는 곳이다.**

이제 실전에서 응용해보도록 하자.

### 3.1.1. 응용

---

지금까지 배운 것을 바탕으로, 아래처럼 작성해보자.

코드는 앞에서 말했다시피, `case WM_PAINT:`의 `//TODO:` 아래에 작성하도록 한다.

```C++
TextOut(hdc, 100, 100, "Hello World", 10);
```

하지만 위와 같이 작성했을 때에는 제대로 작성되지 않을 것이다. 그 이유는 바로 `"Hello World"`에 있다.

`C++`를 비롯한 C언어 계열에서, 딱히 자료형을 지정해주지 않는 한 ""는 `const char*` 자료형의 형태로 출력된다. 따라서 이 경우에는, `"Hello World"`는 `TEXT("")`를 이용해서 출력해야 한다.

이것을 적용한다면 아래와 같이 변한다:

```C++
TextOut(hdc, 100, 100, TEXT("Hello World"), 10);
```

<br>

## 3.2. `TCHAR const *str =`

---

```C++
TCHAR* str = TEXT("Hello World");
```

위처럼 작성할 때에는, "Hello World`가 결과적으로 출력된다.

이전에, 솔루션 속성에서 \[구성 설정 -> 고급 -> 문자 집합\] 문자 집합 설정을 "유니코드 문자 집합 사용"으로 바꾸었을 것이다. 참고로, 기본 설정은 "멀티바이트 문자 집합 사용"이다.

그렇다면, 둘의 차이는 무엇인가? 바로 문자를 몇 `byte`로 받아들이냐의 차이이다.

다음 표를 보라.

|문자 집합 형식|영어(byte)|한글(byte)|
|:---:|:---:|:---:|
|멀티바이트|1|2|
|유니코드|2|2|

위 표에서 알 수 있다시피, 멀티바이트는 영어와 한글을 받아들이는 `byte` 수가 다르지만, 유니코드는 무조건 2 `byte`로 받아들인다.

따라서 효율 면에서 따져본다면 멀티바이트 문자 집합이 훨씬 좋을 것이다. 그렇다면 어째서 유니코드를 사용하는가?

주석을 달아야 하기 때문이다. 자세한 점은 이후에 기회가 있다면 설명하겠지만, 만약 유니코드가 아닌 방식을 사용하는 경우, 한글 주석을 달았을 때, 파일을 옮기는 등의 행위를 하는 경우 한글이 모두 깨진 상태로 나올 수 있다.

따라서, 유니코드로 설정을 미리 바꿔놓는 것이 좋을 것이다.

하지만, 가끔 멀티바이트 문자 집합을 사용해야 하는 경우가 있다. 그런 경우에는, `tchar`를 사용해주도록 한다.

`tchar`는 유니코드 내에서 멀티바이트를 지원하도록 하는 예약어이다. 해당하는 헤더파일을 `#include`를 통해 선언해주어야 하지만, 기본적으로 비주얼 스튜디오 2019 기준으로는 솔루션 생성 시 기본적으로 선언해주기 때문에 아직은 딱히 신경 쓸 필요는 없다.

사용법은 맨 처음 작성한 것과 같다.

```C++
TCHAR const *str = TEXT("Hello World");
```

위와 같이 작성했을 때, 결과적으로 `Hello World`가 출력되게 된다.

단, 여기에서 `const`를 추가해 상수 취급을 하는 것을 잊지 말도록 하자.


<br>

## 3.3. `LPCWSTR`/`LPCTSTR`

---

`LPCWSTR`의 `W`: Wide
`LPCTSTR`의 `T`: `tchar`의 `t`

API에서 출력을 하기 위한 세번째 방법은 바로 `LPCWSTR(LPCTSTR)`을 사용하는 것이다.