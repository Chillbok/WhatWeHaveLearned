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
		"������ ����" << endl <<
		"===========" << endl;
	cout << endl;
	cout << "������ ������ ����" << endl;
	cout << "���� ���� �ݾ�: " << Player.Money << endl;
	cout << "1. " << Item[0].Name << "\t/" << Item[0].Price << "���" << endl;
	cout << "2. " << Item[1].Name << "\t\t/" << Item[1].Price << "���" << endl;
	cout << "3. " << Item[2].Name << "\t\t/" << Item[2].Price << "���" << endl;
	cin >> UserInput;
	//������ 3�� �� 1���� ������ ���̴�.
	//���� ������ �����ϰ� �ִ� ���� ������ �������� ���Ű� ������ ������ ���ΰ�?
	
	if(Player.Money >= Item [UserInput - 1].Price)
	{
		for(i = 0; i < INVEN_END; i++)//�κ��丮�� ����ִ�.
		{
			Player.Inventory[i] = Userinput - 1;
			Player.Money -= Item[Userinput - 1].Price;
			break;

			if(Player.Inventory[i] == INVEN_END)//�κ��丮�� ����ִ�.
			{
				Player.Inventory[i] = UserInput - 1;
				Player.Money -= Item[UserInput - 1].Price;
				break;
			}
			/*
			if (i == (INVEN_END - 1))
			{
				cout << "���� ��á��." << endl;
			}
			*/
			if(Player.Inventory[INVEN_END - 1] != INVEN_END)
			{
				cout << "���� ��á��." << endl;
				break;
			}
		}
	}
	else//���� �����ؼ� ���Ű� �Ұ����ϴ�
	{
		cout << "������ ����������" << endl;
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
