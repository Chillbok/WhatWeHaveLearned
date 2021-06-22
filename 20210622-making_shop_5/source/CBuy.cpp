#include "main.h"
#include "CBuy.h"

void CBuy::Initialize()
{
}


tagPlayer CBuy::BuyProcess(tagPlayer Player, tagItem* Item)
{
	int UserInput = 0;
	int i;

	cout << "===========" << endl << 
		"아이템 구매" << endl <<
		"===========" << endl;
	cout << endl;
	cout << "구매할 아이템 선택" << endl;
	cout << "현재 보유 금액: " << Player.Money << endl;
	cout << "1. " << Item[0].Name << "\t/" << Item[0].Price << "골드" << endl;
	cout << "2. " << Item[1].Name << "\t\t/" << Item[1].Price << "골드" << endl;
	cout << "3. " << Item[2].Name << "\t\t/" << Item[2].Price << "골드" << endl;
	cin >> UserInput;
	//유저가 3개 중 1개를 선택할 것이다.
	//현재 유저가 보유하고 있는 돈이 선택한 아이템의 구매가 가능한 정도의 돈인가?
	
	if(Player.Money >= Item [UserInput - 1].Price)
	{
		for(i = 0; i < INVEN_END; i++)//인벤토리가 비어있다.
		{
			Player.Inventory[i] = Userinput - 1;
			Player.Money -= Item[Userinput - 1].Price;
			break;

			if(Player.Inventory[i] == INVEN_END)//인벤토리가 비어있다.
			{
				Player.Inventory[i] = UserInput - 1;
				Player.Money -= Item[UserInput - 1].Price;
				break;
			}
			/*
			if (i == (INVEN_END - 1))
			{
				cout << "가방 꽉찼다." << endl;
			}
			*/
			if(Player.Inventory[INVEN_END - 1] != INVEN_END)
			{
				cout << "가방 꽉찼다." << endl;
				break;
			}
		}
	}
	else//돈이 부족해서 구매가 불가능하다
	{
		cout << "꺼져라 거지새끼야" << endl;
	}
	
	system("pause");

	return Player;
}



tagPlayer CBuy::Management(tagPlayer Player, tagItem* Item)
{
	Initialize();
	Player = BuyProcess(Player, Item);

	return Player;
}
