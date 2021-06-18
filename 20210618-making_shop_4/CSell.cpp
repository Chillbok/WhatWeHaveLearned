#include "main.h"
#include "CSell.h"

void CSell::Initialize()
{
    int i;
    
    for(i = 0; i < MAXINCHAN; i++)
    {
        InchanPrice[i] = (i * 300) * 4;
    }
}

tagPlayer CSell::SellProcess(tagPlayer Player)
{
    int UserInput = 0;
    //UI같은걸 좀 넣어줘..
    cout << "현재 가지고 있는 무기 강화 단계 : " << Player.InchantPt << endl;
    cout << "강화 단계에 따른 판매 금액 : " << InchanPrice[Player.InchantPt] << endl;
    cout << "1. 판매" << endl;
    cout << "2. 취소" << endl;
    cin >> UserInput;

    if(UserInput == 1)
    {
        Player.Money += InchanPrice[Player.InchantPt];
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
