#pragma once

#define MAX_INCHANT 20

class CInchant
{
private:
    //강화 확률: 배열을 이용해서 만든다.
    int bayeoll_InchanPer[MAX_INCHANT];
    void Initialize();
    void InchantTitle();
    tagPlayer PlayInchant(tagPlayer Player);

public:
    tagPlayer Management(tagPlayer Player);
};