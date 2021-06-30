# API���� ��������Ʈ �̹��� �̿��ؼ� �ִϸ��̼� �����ϱ�

---

## ����

---

`case WM_PAINT:` �ٷ� �Ʒ��� �ۼ��Ѵ�.

```C++
case WM_PAINT:
    {
        BackDC = CreateCompatibleDC(hdc);
        CharacterDC = CreateCompatibleDC(hdc);//�̷��� CharacterDC��� DC�� �������ش�.
        BgDC = CreateCompatibleDC(hdc);
        BackBitmap = CreateCompatibleBitmap(hdc, WINDOW_X, WINDOW_Y);
        OldBitmap = (HBITMAP)SelectObject(BackDC, BackBitmap);
    }
```   

�׸���, �ʱ�ȭ��ų �� ����� �ٽ� �ۼ��ϵ��� �ϱ� ���ؼ� `DeleteDC`�� ����ϵ��� ����.

`case WM_PAINT:` �׸��� �� �Ʒ�, `EndPaint(hWnd, &ps);`�� �ٷ� ���� �ۼ��Ѵ�.

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

# ��ü �ڵ�

---

```C++
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc = {};
    HDC BackDC = {};
    HDC BgDC = {};//���ȭ��
    HDC CharacterDC = {};//ĳ����

    HBITMAP BackBitmap;//���� ���۸��� ��Ʈ��
    HBITMAP OldBitmap;//������ ��Ʈ��
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
        SetTimer(hWnd, 0, 17, NULL);//0.017�ʸ��� �ڵ� ����
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
            //TODO: ���⿡ hdc�� ����ϴ� �׸��� �ڵ带 �߰��մϴ�...

            //DC ����
            BackDC = CreateCompatibleDC(hdc);
            BgDC = CreateCompatibleDC(hdc);
            CharacterDC = CreateCompatibleDC(hdc);
            BackBitmap = CreateCompatibleBitmap(hdc, WINDOW_X, WINDOW_Y);
            OldBitmap = (HBITMAP)SelectObject(BackDC, BackBitmap);

            BITMAP MyBitmap, OldBitmap, BackBitmap;

            RECT rt = {0,0,WINDOW_X,WINDOW_Y};
            //HBITMAP ����
            BackBitmap = CreateCompatibleBitmap(hdc, WINDOW_X, WINDOW_Y);
            OldBitmap = (HBITMAP)SelectObject(BackDC, BackBitmap);
            //�̰� �׳� ����� ����� ���� �� ���� �� �Ⱦ��� �Ͼ�� �������� ���� ���̴�.
            //��, ��� �ȴ�.
            FillRect(BackDC, &rt, (HBRUSH)GetStockObject(WHITE_BRUSH));

            SelectObject(BgDC, MyBitmap);
            BitBlt(BackDC, 0,0, WINDOW_X, WINDOW_Y, BgDC, 0,0, SRCCOPY);

            MyBitmap = (HBITMAP)LoadImage(NULL, TEXT("character.bmp"), IMAGE_BITMAP, 0,0,LR_LOADFROMFILE | LR_CREATEDIBSECTION);

            SelectObject(CharacterDC, MyBitmap);
            BitBlt(BackDC, ptCharPos.x, ptCharPos.y, 64, 96,
                    CharacterDC, 0,0,32,48, RGB(255,0,255));

            //BackDC�� ���� ���� DC�� �����Ѵ�.
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
