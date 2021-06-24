# API������ �����(�⺻)

---

<br>
<br>

# ����

---

<details>
<summary>������ ���� ��ġ��</summary>

</details>

<br>
<br>

# �Է�

---

nvalidateRect(hWnd, NULL, true)

����� â�� hWnd�� NULL�� ���� �ʱ�ȭ�Ѵ�.


VK

---

���߾� Ű. ȭ��ǥ Ű�� �̿��Ѵ�.
����:

D:\����ȣ\GitFiles\WhatWeHaveLearned\20210623-API

1. `hdc` = ȭ�� ��°� ���õ� ����ü.
    - � �����츦 ����� ���ΰ�?
2. `hWnd` = ȭ�� ���ð� ���õ� ����ü. h�� HANDLE�� h�̴�. ������ Ÿ���� ������ �ڵ��̴�.
3. `w`(�밡���ȹ�): �ش� ���ڰ� �밡���ȹ� �������� �ٴ´ٸ� Ű������ �Է°� ���õ� �����̴�.
    - ��ǥ���� ���÷� `wParam`�� �ִ�.
4. `l`(�밡���ȹ�): �ش� ���ڰ� �밡���ȹ� �������� �ٴ´ٸ� ���콺�� �Է°� ���õ� �����̴�.
    - ��ǥ���� ���÷� `lParam`�� �ִ�.

<br>

---

**�� ���� �˾Ƶ���:**

|<span style="color:red">���α׷��� �ش� �������� ���� ���� �Է� ������ �������� ���α׷��� �����Ѵ�.</span>|
|:---:|

<br>

## Ű����� ���콺

---

|�׸�|����|
|:---:|:---|
|�߿� �����|`wParam`, `lParam`|
|�ۼ��ϴ� ��|`LRESULT CALLBACK WndProc()`/`switch(message)`/�� ����|

### `static /*����*/;`

---

**����:**

```C++
static int x, y;//1ȸ�� ����Ǹ� ���� �ʱ�ȭ�� ����������

switch (message)
{
case WM_CREATE://���� ����
    x = 100;
    y = 100;
    break;

case WM_KEYDOWN://�Է¹ް�, �Է¹޾��� �� ����
    switch(wParam)
    //wParam�� ��쿡�� ���콺 ��ư�� Ű���� �Է�
    //lParam�� ��쿡�� ���콺 ������ �Է�
    {
    case VK_UP://����Ű(��)
    //VK_DOWN(����Ű �Ʒ�), VK_LEFT(����Ű ����), VK_RIGHT(����Ű ������)
        {

        }
    }

```C++
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM, lParam)
{
    switch(message)//1ȸ�� ����Ǹ�, �� ���� ������������ ���� �ʱ�ȭ�ȴ�.
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

    //���� ����
    }
}
```
---




# `wParam`

---

��ư ó���� ���õ� ������ �޴´�.

������ ����, ���콺�� "**��ư**"�� �� "**����**"�� �ش��Ѵ�.


# `lParam`

---

`Long Parameter` => `lParam`

���콺�� �����Ӱ� ���õ� ������ �޴´�.

������ ����, �ռ� ���ߵ��� ���콺�� ��ư�� Ŭ���ϴ� ���� `wParam`�� ���ԵǴ� ���̰�, `lParam`�� ���Ե����� �ʴ´ٴ� ���̴�.

`lParam`���� ���콺 ��ġ�� ���� ������ ���´�. ȭ�� �󿡼� ���콺�� ������ ������ X ��ǥ, Y ��ǥ, �� 2������ �����Ѵ�. ������, `lParam`�� ���� ������ �ϳ����̴�. ����, `lParam`�� ���� ���� X ��ǥ�� Y ��ǥ�� ȥ��Ǵ� ���̴�.

## X ��ǥ�� Y ��ǥ�� ȥ��

---

|Full Name|Using Name|bit|byte|
|:---:|:---:|---:|---:|
|WORD Parameter|wParam|32|8|
|Long Parameter|lParam|32|8|

`lParam`�� `wParam`�� 2���� �����ϸ� �����ϱ� ����. �ٸ�, `wParam`�� 2�� �� ���� `lParam`�� �ƴ϶�� ���� �ݵ�� ����ϵ��� ����.

|wParam�� ���||
|:---:|:---|
|WORD|FF FF FF FF FF FF FF FF|

|lParam�� ���||
|LOWORD|FF FF FF FF FF FF FF FF|
|HIWORD|FF FF FF FF FF FF FF FF|

������ �� �� �ֵ���, `lParam`�� `wParam`�� ���� ���� 2���̴�. �պκп� `LOWORD`�� ����, �޺κп� `HIWORD`�� ����.

`LOWORD`�� X��ǥ��, `HIWORD`�� Y��ǥ�� �ǹ��Ѵ�.




# `WM_MOUSEMOVE`

---

`lParam`�� ��
