#pragma once

#define MAXINCHAN 20

class CInchant
{
private:
    
    //��ȭ Ȯ�� : �迭�� �̿��ؼ� �����.
    int InchanPer[MAXINCHAN];
    void Initialize();
    void InchantTitle();
    tagPlayer PlayInchant(tagPlayer Player);

public:
    tagPlayer Management(tagPlayer Player);

};

