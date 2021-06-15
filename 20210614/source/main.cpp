#include "main.h"

int main()
{
	/*
	1, 2, 3, 4를 입력받고, 1, 2, 3, 4 각각 클래스 만들어서
	1. LT = 왼쪽 위 별 1개
	2. LB = 왼쪽 아래 별 1개
	3. RT = 오른쪽 위 별 1개
	4. RB = 오른쪽 아래 별 1개
	유저가 입력한 숫자에 따라서 각각의 형태를 출력하는 형태
	*/
	CLT printlt;
	
	int userinput;
	for (;;)
	{
		cout << "===========================" << endl;
		cout << "1. LT = 왼쪽 위 별 1개"		<< endl;
		cout << "2. LB = 왼쪽 아래 별 1개"	<< endl;
		cout << "3. RT = 오른쪽 위 별 1개"	<< endl;
		cout << "4. RB = 오른쪽 아래 별 1개"	<< endl;
		cout << "선택해라: ";
		cin >> userinput;

		system("cls");

		if (userinput == 1)
		{
			printlt.PrintLT();
		}
		else if (userinput == 2)
		{
			printlt.PrintLB();
		}
		else if (userinput == 3)
		{
			printlt.PrintRT();
		}
		else if (userinput == 4)
		{
			printlt.PrintRB();
		}
		else
		{
			for (;;)
			{
				cout << "잘못 입력하셨습니다." << endl;
				cout << "다시 입력하시겠습니까?" << endl;
				cout << "아니면 이대로 끝내시겠습니까?" << endl;
				cout << "1. 계속하기" << endl;
				cout << "2. 끝내기" << endl;
				cout << "--> ";
				userinput = 0;
				cin >> userinput;
				cout << endl;

				if (userinput == 1)
				{
					break;
				}
				else if (userinput == 2)
				{
					break;
				}
				else
				{
					cout << "잘못 입력하셨습니다." << endl;
					cout << "다시 입력하세요." << endl;
					system("cls");
					continue;
				}
			}
			if (userinput == 1)
			{
				system("cls");
				continue;
			}
			else if (userinput == 2)
			{
				system("cls");
				break;
			}
		}
	}
}