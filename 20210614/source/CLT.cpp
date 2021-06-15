#include "CLT.h"
//클래스에 작성된 함수는 main.cpp의 main 함수에서 호출한다.

char chStar[6] = "*****";
char chSpace[5] = "    ";
int i, j = {};

void CLT::PrintLT()
{
	for (i = 0; i < 5; i++)
	{
		cout << &chStar[4 - i];
		cout << endl;
	}
}

void CLT::PrintLB()
{
	for (i = 0; i < 5; i++)
	{
		cout << &chStar[i];
		cout << endl;
	}
}

void CLT::PrintRT()
{
	for (i = 0; i < 5; i++)
	{
		cout << &chSpace[i] << chStar[4 - i];
		cout << endl;
	}
}

void CLT::PrintRB()
{
	for (i = 0; i < 5; i++)
	{
		cout << &chSpace[4 - i] << chStar[i];
		cout << endl;
	}
}