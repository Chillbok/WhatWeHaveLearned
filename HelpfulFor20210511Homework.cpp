#include <iostream>
#include "stdio.h"
#include "windows.h"
#include "time.h"//있어야 랜덤 변수 사용 가능

using namespace std;
int main()
{
	srand(time(NULL));

	int nNumber[25];//변수 Number 25개
	int nInsideNum;//대괄호 안에 들어가는 숫자
	int nNumberStock;
	int nLastLineNum;

	nNumberStock = 1;//나오는 숫자는 총 25개이므로, 1에서부터 시작
	nInsideNum = 0;//0 ~ 24이므로, 0부터 시작
	nNumber[nInsideNum] = rand() % 25 + 1;
	for (;;)
	{
		for (nNumberStock = 0; nNumberStock < 26; nNumberStock++)
		{
			for (nLastLineNum = 0; nLastLineNum < nInsideNum; nLastLineNum++)
			{
				if (nNumber[nInsideNum] == nNumber[nLastLineNum])
				{
					nInsideNum--;
				}
			}
		}
		if (nInsideNum == 25)
			break;
	}



	return 0;
}
