#include "main.h"
#include "CSell.h"

void CSell::Initialize()
{
    int i;

    for(i = 0; i < MAX_INCHANT; i++)
    {
        bayeoll_InchantPrice[i] = (i * 300) * 4;
    }
}

tagPlayer CSell::SellProcess(tagPlayer Player)
{
    int nUserInput = 0;
    //UI같은 것들을 좀 넣어주자
    cout << "현재 가지고 있는 무기 강화 단계: " << endl;
    cout << "강화 단계에 따른 판매 금액: " << endl;
    cout << "==========================================" << endl;
    cout << "1. 판매" << endl;
    cout << "2. 취소" << endl;
    cin >> nUserInput;

    if(nUserInput == 1)
    {
        Player.Money += bayeoll_InchantPrice[Player.InchantPt];
        Player.InchantPt = 0;
    }

    return Player;
}



tagPlayer CSell::Management(tagPlayer Player)
{
    Initialize();
    Player = SellProcess(Player);

    return Player;
}