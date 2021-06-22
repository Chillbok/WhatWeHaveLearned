#include "main.h"
#include "CInchant.h"
#include "CSell.h"
#include "CBuy.h"

tagPlayer Player;
tagItem Item[3];

//초기화 함수
void Initialize()
{
	Player.Money = 1000;//초기 머니
	for(int i = 0; i < INVEN_END; i++)
	{
		Player.Inventory[i] = INVEN_END;
		Player.InchantPt[i] = 0;
	}
	Item[0].Name = "개쓰레기";
	Item[0].Grade = GRADE_NORMAL;
	Item[0].Price =  500;

	Item[1].Name = "쓰레기";
	Item[1].Grade = GRADE_MAGIC;
	Item[1].Price = 1000;

	Item[2].Name = "집판검";
	Item[2].Grade = GRADE_LEGENO;
	Item[2].Price = 10000;
}

//관리함수
void Management()
{
	//순서대로 유저의 선택이나 상황에 따라서 알맞은 장면을 호출.
	//예전에 메인 함수에서 하던 것을 여기에서 할 거란 이야기이다.
	bool GameEnd = false;

	//오프닝부
	Opening();

	//메인게임부
	while(true)
	{
		GameEnd = MainGame();
		if(GameEnd == true) break;
	}
	
	//종료
	EndGame();
}

//메인함수
int main()
{
	//클래스:상점파트 - 구매, 판매, 강화클래스
	Management();

	return 0;
}


void Opening()
{
	cout << "타이틀 화면임" << endl;
	//뭐 하고싶은 사람은 알아서들 꾸며라
	system("pause");
}

bool MainGame()
{
	Initialize();
	bool GameEnd = false;
	Cinchant Inchant;
	CSell Sell;
	CBuy Buy;

	int nUserInput = 0;

	while(true)
	{
		//메인 게임 화면은 알아서들 꾸미고...
		system("cls");
		cout << "1. 상점" << endl;
		cout << "2. 강화" << endl;
		cout << "3. 종료" << endl;
		cin >> nUserInput;
		system("cls");

		if(nUserInput == 1)//상점
		{
			cout << "1. 구매" << endl;
			cout << "2. 판매" << endl;
			cout << "3. 종료" << endl;
			cin >> nUserInput;
			system("cls");

			if(nUserInput == 1)
			{
				Player = Buy.Management(Player, Item);
			}
			if (nUserInput == 2)
			{
				Player = Sell.Management(Player, Item);
			}
			else break;
		}
		else if(nUserInput == 2) //강화
		{
			Player = Inchant.Management(Player, Item);
		}
		else if(nUserInput == 3)
		{
			GameEnd = true;
			break;
		}
		else
		{
			cout << "없는 선택지를 선택" << endl;
			Sleep(300);
		}
		
		cout << Item[Player.Inventory[INVEN_0].Name << endl;
		cout << Item[Player.Inventory[INVEN_T].Name << endl;
		cout << Item[Player.Inventory[INVEN_THR].Name << endl;
		system("pause");
	}

	//유저에게 선택하게 하고
	//1. 상점
	//	1. 구매
	//	2. 판매
	//2. 강화
	
	return GameEnd;
}

void EndGame()
{
	cout << "게임 종료" << endl;
	Sleep(300);
}
