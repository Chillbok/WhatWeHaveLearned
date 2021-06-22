#include "main.h"
#include "CSell.h"

void CSell::Initialize()
{
	int i;
	for(i = 0; i < MANXINCHAN; i++)
	{
		InchanPrice[i] = (i * 300) * 4;
	}
}

tagPlayer CSell::SellProcess(tagPlayer Player, tagItem* Item)
{
	int UserInput = 0;
	//UI같은 것을 좀 넣어주자.
	cout << "현재 가지고 있는 무기 강화 단계: " << Player.InchantPt[0] << endl;
	cout << "강화 단계에 따른 판매 금액: " << InchanPrice[Player.InchantPt[0]] << endl;
	cout << "1. 판매" << endl;
	cout << "2. 취소" << endl;
	cin >> UserInput;

	if(UserInput == 1)
	{
		Player.Money += InchanPrice[Player.InchantPt[0]];
		Player.InchantPt[0] = 0;
	}

	return Player;
	
}

tagPlayer CSell::Management(tagPlayer Player, tagItem* Item)
{
	Initialize();

	Player = SellProcess(Player, Item);

	return Player;
}
