#pragma once

#define MAX_INCHANT 20

class CSell
{
private:
    void Initialize();
    tagPlayer SellProcess(tagPlayer Player);
    int bayeoll_InchantPrice[MAX_INCHANT] = {};

public:
    tagPlayer Management(tagPlayer Player);
};