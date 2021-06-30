# API에서의 입출력

---

<br>
<br>

# 입력

---

`LRESULT CALLBACK WndProc()` 함수의 `switch(message)` 조건문에 새로운 조건을 선언한다: `case WM_KEYDOWN:`

키보드 키 입력을 받을 때에는 `lParam`이 아닌 `wParam`을 받는다는 사실을 잊지 말도록 하자.

2가지 방법이 있다.

---

## 첫번째: `if`문

---

```C++
switch (message)
{
case WM_KEYDOWN:
    if(GetAsyncKeyState(VK_UP) & 0x8000)//0x8000 = 16진수
    {
    }
    if(GetAsyncKeyState(VK_DOWN) & 0x8000)
    {
    }
    if(GetAsyncKeyState(VK_LEFT) & 0x8000)
    {
    }
    if(GetAsyncKeyState(VK_RIGHT) & 0x8000)
    {
    }
}
```

<br>

## 두번째: `switch`문

---

```C++
case WM_KEYDOWN:
{
    switch(wParam)
    {
    case VK_UP:
        break;
    case VK_DOWN:
        break;
    case VK_LEFT:
        break;
    case VK_RIGHT:
        break;
    }
}
break;
```

---

해야 할 일을 순서에 따라 나열하면 다음과 같다:

> 1. 좌표를 바꿔준다
> 2. 화면을 갱신한다

또한, 화면이 깜박거리는 현상을 방지하기 위해서, 우리는 백버퍼(또는 더블버퍼링)를 사용해야 한다.

이제부터는 캐릭터를 움직이는 방법에 대해 서술한다.

<br>
<br>

# 물체 움직이기

---


## 변수 선언

---

`switch (message)` 바로 위에 변수를 추가해주자. 변수는 다음과 같이 선언한다:

```C++
static POINT ptCharPos;
```

선언한 변수는 `switch (message)` 조건문에 새로운 조건 `case WM_CREATE:`을 만듦으로써 값을 대입한다.

다음과 같이 대입한다:

```C++
case WM_CREATE:
    ptCharPos.x = 608;
    ptCharPos.y = 454;
    break;
```

<br>

## `case WM_KEYDOWN` 대입

---

```C++
case WM_KEYDOWN:
    switch(wParam)
    {
    case VK_UP:
        ptCharPos.y -= 1;
        break;
    case VK_DOWN:
        ptCharPos.y += 1;
        break;
    case VK_LEFT:
        ptCharPos.x -= 1;
        break;
    case VK_RIGHT:
        ptCharPos.x += 1;
        break;
    }
    break;
```

<br>

## 화면 갱신

---


