#pragma once
#include "main.h"

#define MAXINCHANT 20

enum GRADE {GRADE_GREEN, GRADE_BLUE, GRADE_PURPLE, GRADE_EXOTIC, GRADE_END};

class CInchant
{
private:
    //맥강이 얼마인지(무한이든 아니든 상관 X)
    int MaxInchant[GRADE_END] = {5, 10, 10, 15};

    int PlayerMoney;
    int PlayerInchancnt;
    
    //강화 확률: 배열을 이용해서 만들면 쉬움
    int InchantPersent[MAXINCHANT];
    void Initialize();
    void InchantTitle();
    void PlayInchant(int Money, int Inchancnt);

public:
    void Management(int Money, int Inchancnt);

};