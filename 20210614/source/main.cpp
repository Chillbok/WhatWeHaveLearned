#include "main.h"
#include "CLT.h"

int main()
{
    /*
    1.2.3.4 를 입력받고
    1.2.3.4. 각각 클래스 만들어서
    1. LT
    2. LB
    3. RT
    4. RB
    유저가 입력한 숫자에 따라서 각각의 형태를 출력하는 형태
    */

    CLT printlt;

    int userinput;
    for (;;)
    {
        cout << "1. LT" << endl;
        cout << "2. LB" << endl;
        cout << "3. RT" << endl;
        cout << "4. RB" << endl;
        cout << "선택해라: ";
        cin >> userinput;

        system("cls");

        switch (userinput)
        {
        case 1:
            printlt.PrintLT();
            break;
        case 2:
            printlt.PrintLB();
            break;
        case 3:
            printlt.PrintRT();
            break;
        case 4:
            printlt.PrintRB();
            break;
        }
        if (userinput == 5)
        {
            break;
        }
    }
}