#include "main.h"
#include "CInchant.h"

void CInchant::Initialize()
{
	int i;
	int InchantPer = 52;//강화 확률 기준값(높을수록 잘 안 뜨고, 낮을수록 잘 뜬다.)

	for(i = 0; i < MAXINCHAN; i++)
	{
		InchanPer[i] = 1000 - (i * InchantPer);
	}
	//등급에 따라 다르게 설정되게
	//이차원 배열
}

void CInchant::InchantTitle()
{
	cout << "강화 화면" << endl;
}

tagPlayer CInchant::PlayInchant(tagPlayer Player, tagItem* Item)
{
	while(true)
	{
		//지지고 볶고 하겠지...
		system("cls");
		cout << "현재 남은 골드: " << Player.Money << endl;
		
		/*
		 강화할 아이템 선택
		 */
		cout << "현재 아이템의 강화 상태: " << Player.InchantPt[0] << endl;
		cout << "현재 아이템의 강화 성공 확률: " << (float)(InchanPer[Player.InchantPt[0]]/10) << endl;

		//강화하면 된다. 그리고, 그 결과를 찍어주면 된다.
		int StartIn = 0;
		int RandomValue = 0;
		cout << "1. 강화 시작" << endl;
		cout << "2. 강화 중지" << endl;
		cin >> StartIn;
		if(StartIn == 1)
		{
			srand((unsigned int)time(NULL));
			//1 ~ 1000
			//InchanPer[inchancnt]
			RandomValue = rand() % 1000 + 1;
			if(InchanPer[Player.InchantPt[0]] >= RandomValue)
			{
				//강화가 성공
				Player.InchantPt[0]++;
				Player.Money -= 1000;
				cout << "강화가 성공하였습니다. 1강 증가" << endl;
				cout << "골드가 1000원 소비되었습니다." << endl;
			}
			else
			{
				RandomValue = rand() % 100;

				if(RandomValue < 1)
				{
					//1퍼센트 확률로 강화가 실패시 대실패
					Player.InchantPt[0] = 0;
					cout << "강화가 대실패하였습니다." << endl;
					cout << "강화를 초기화합니다." << endl;
				}
				else
				{
					//강화가 실패
					Player.InchantPt[0]--;
					if(Player.InchantPt[0] < 0) Player.InchantPt[0] = 0;
					cout << "강화가 실패하였습니다." << endl;
					cout << "1강 감소되었습니다." << endl;
				}
				Player.Money -= 1000;
				cout << "골드가 1000원 소비되었습니다." << endl;
			}
			system("pause");
		}
		else if(StartIn == 2)
		{
			break;
		}
		else
		{
			cout << "잘못 입력함" << endl;
		}
	}
	return Player;
}

tagPlayer CInchant::Management(tagPlayer Player, tagItem* Item)//인챈트의 관리함수
{
	//강화에 대한 것들만 관리한다.
	Initialize();
	
	int nUserInput = 0;

	while(true)
	{
		system("cls");
		InchantTitle();
		cout << "1. 강화 시도" << endl;
		cout << "2. 강화 종료" << endl;
		cin >> nUserInput;

		if(nUserInput == 1)
		{
			Player = PlayInchant(Player, Item);
		}
		else if(nUserInput == 2)
		{
			break;
		}
	}
	return Player;
}
