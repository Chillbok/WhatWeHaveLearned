#include <iostream>
#include "stdio.h"
#include "windows.h"

using namespace std;
int main()
{
	int nNumber[24];//24개의 nNumber 변수들
	int nInsideNumber = 0;//[] 안에 들어가는 숫자
	int nLineNumber = 0;//현재 줄에 몇 개의 글자가 들어갔는가?
	int nInsideNumPlus = 0;//nLineNumber + 1


	nInsideNumber = 0;
	nInsideNumPlus = 1;
	nLineNumber = 1;
	

	nNumber[nInsideNumber] = nInsideNumPlus;
	while (nInsideNumber < 25)
	{
		if (nLineNumber < 6)//만약 현재 줄에 있는 글자 수가 6보다 작다면
		{
			cout << nInsideNumPlus;//nLineNumber + 1 출력
			cout << "\t";//tab 키 누르기
			nLineNumber++;//LineNumber + 1
		}
		else if (nLineNumber == 6)//만약 현재 줄 글자 수가 6이 된다면
		{
			cout << endl;//줄 바꾸기
			nLineNumber = 1;//줄에 들어간 글자 수 초기화
			continue;//건너뛰어서 while 문 새로 시작하기
		}
		nInsideNumber++;//[] 안에 들어가는 숫자 + 1
		nInsideNumPlus++;//([] 안에 들어가는 숫자 + 1) + 1

	}
	

	return 0;
}
