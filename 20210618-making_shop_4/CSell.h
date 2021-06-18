#pragma once

#define MAXINCHAN 20

class CSell
{
private:
    void Initialize();
    tagPlayer SellProcess(tagPlayer Player);
    int InchanPrice[MAXINCHAN] = {};

public:
    tagPlayer Management(tagPlayer Player);
};

