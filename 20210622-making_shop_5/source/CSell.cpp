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
	//UI���� ���� �� �־�����.
	cout << "���� ������ �ִ� ���� ��ȭ �ܰ�: " << Player.InchantPt[0] << endl;
	cout << "��ȭ �ܰ迡 ���� �Ǹ� �ݾ�: " << InchanPrice[Player.InchantPt[0]] << endl;
	cout << "1. �Ǹ�" << endl;
	cout << "2. ���" << endl;
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
