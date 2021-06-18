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
    //UI������ �� �־���..
    cout << "���� ������ �ִ� ���� ��ȭ �ܰ� : " << Player.InchantPt << endl;
    cout << "��ȭ �ܰ迡 ���� �Ǹ� �ݾ� : " << InchanPrice[Player.InchantPt] << endl;
    cout << "1. �Ǹ�" << endl;
    cout << "2. ���" << endl;
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
