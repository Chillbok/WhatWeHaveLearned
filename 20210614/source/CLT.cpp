#include "CLT.h"

//클래스에 작성된 함수는 main.cpp의 main 함수에서 호출한다.



void CLT::PrintLT()
{
    //여기에서 LT패턴 입출력
    int i, j = {};
    char nStar[6] = "*****";
    char nSpace[5] = "    ";

    for (i = 0; i < 5; i++)
    {
        cout << &nStar[4 - i];
        cout << endl;
    }
}

void CLT::PrintLB()
{
    int i, j = {};
    char nStar[6] = "*****";
    char nSpace[5] = "    ";
    for (i = 0; i < 5; i++)
    {
        cout << &nStar[i] << endl;
    }
}

void CLT::PrintRT()
{
    int i, j = {};
    char nSpace[5] = "    ";
    char nStar[6] = "*****";

    for (i = 0; i < 5; i++)
    {
        cout << &nSpace[i] << &nStar[4 - i] << endl;
    }
}

void CLT::PrintRB()
{
    int i, j = {};
    char nSpace[5] = "    ";
    char nStar[6] = "*****";

    for (i = 0; i < 5; i++)
    {
        cout << &nSpace[4 - i] << &nStar[i] << endl;
    }
}