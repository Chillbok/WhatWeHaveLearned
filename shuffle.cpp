#include <iostream>
#include "time.h"

using namespace std;

int main()
{
    srand(time(NULL));

    int i, j;

    int Number[9];//숫자들: Number[0] ~ Number[지정한 숫자 - 1]
    int Dest;//도착
    int Sour;//출발
    int Temp;//임시

    for (i = 0; i < 500/*아무 숫자나 가능(몇 번 섞을 것인가?*/; i++)
    {
        /*Dest --> Temp, Sour --> Dest, Temp --> Sour*/

        Dest = rand() % 9/*위의 Number[]변수에서 대괄호 안에 넣은 숫자*/;
        sour = rand() % 9/*위의 Number[]변수에서 대괄호 안에 넣은 숫자*/;
        Temp = 0;//임시값이기 때문에 딱히 아무것도 넣을 필요 없음

        Temp = Number[Dest];
        Number[Dest] = Number[Sour];
        Number[Sour] = Temp;
    }


    return 0;
}