#pragma once
#include "main.h"

#define MAX_INCHANT 20

class CInchant
{
private:
    int PlayerMoney;
    int PlayerInchancnt;

    //강화 확률: 배열을 이용해서 만든다.
    int InchanPer[MAX_INCHANT];
    void Initialize();
    void InchantTitle();
    void PlayInchant(int Money, int Inchancnt);

public:
    void Management(int Money, int Inchancnt);
};