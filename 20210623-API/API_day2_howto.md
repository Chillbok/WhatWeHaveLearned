# 1. �ڵ� �ű��

---

> �ű� �ڵ�: `PAINTSTRUCT ps;`, `HDC = BeginPaint(hWnd, &ps);`
> ��ġ: `LRESULT CALLBACK WndProc()`/�ٷ� �Ʒ�

<br>
<br>

# 2. ������� �߰��ϱ�

---

> ������ ����: `framework.h`
> �߰��� ����: `string`

�� ������ �ٿ� �߰�!

```C++
#include <string>
```

<br>
<br>

# 3. �������� �߰�

---

> **�ۼ� ��ġ:** `LRESULT CALLBACK WndProc()`/�ٷ� �Ʒ�

```C++
PAINTSTRUCT ps;
HDC hdc = BeginPaint(hWnd, &ps);

static RECT rect;
RECT Mousept;

POINT pt;
```

<br>
<br>

# X�� Y��ǥ ��ġ ����

---

> **�ۼ� ��ġ:** `LRESULT CALLBACK WndProc()`/`switch(message)`/`case WM_LBUTTONDOWN:`

```C++
case WM_LBUTTONDOWN:
    pt.x = LOWORD(lParam);
    pt.y = HIWORD(lParam);
```

# `if(IntersectRect(&rcTemp, &rect, &Mousept) == true)`

---

�Ұ�ȣ �ȿ� ù��°�� ���� RECT�� �ι�°�� ���� RECT�� �������� Ȯ���ϴ� �Լ�.

��ġ�� true, ��ġ�� ������ false�� ��ȯ�Ѵ�.
