#include "main.h"
#include "CInchant.h"
#include "CSell.h"
#include "CBuy.h"

tagPlayer Player;
tagItem Item[3];

//�ʱ�ȭ �Լ�
void Initialize()
{
	Player.Money = 1000;//�ʱ� �Ӵ�
	for(int i = 0; i < INVEN_END; i++)
	{
		Player.Inventory[i] = INVEN_END;
		Player.InchantPt[i] = 0;
	}
	Item[0].Name = "��������";
	Item[0].Grade = GRADE_NORMAL;
	Item[0].Price =  500;

	Item[1].Name = "������";
	Item[1].Grade = GRADE_MAGIC;
	Item[1].Price = 1000;

	Item[2].Name = "���ǰ�";
	Item[2].Grade = GRADE_LEGENO;
	Item[2].Price = 10000;
}

//�����Լ�
void Management()
{
	//������� ������ �����̳� ��Ȳ�� ���� �˸��� ����� ȣ��.
	//������ ���� �Լ����� �ϴ� ���� ���⿡�� �� �Ŷ� �̾߱��̴�.
	bool GameEnd = false;

	//�����׺�
	Opening();

	//���ΰ��Ӻ�
	while(true)
	{
		GameEnd = MainGame();
		if(GameEnd == true) break;
	}
	
	//����
	EndGame();
}

//�����Լ�
int main()
{
	//Ŭ����:������Ʈ - ����, �Ǹ�, ��ȭŬ����
	Management();

	return 0;
}


void Opening()
{
	cout << "Ÿ��Ʋ ȭ����" << endl;
	//�� �ϰ���� ����� �˾Ƽ��� �ٸ��
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
		//���� ���� ȭ���� �˾Ƽ��� �ٹ̰�...
		system("cls");
		cout << "1. ����" << endl;
		cout << "2. ��ȭ" << endl;
		cout << "3. ����" << endl;
		cin >> nUserInput;
		system("cls");

		if(nUserInput == 1)//����
		{
			cout << "1. ����" << endl;
			cout << "2. �Ǹ�" << endl;
			cout << "3. ����" << endl;
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
		else if(nUserInput == 2) //��ȭ
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
			cout << "���� �������� ����" << endl;
			Sleep(300);
		}
		
		cout << Item[Player.Inventory[INVEN_0].Name << endl;
		cout << Item[Player.Inventory[INVEN_T].Name << endl;
		cout << Item[Player.Inventory[INVEN_THR].Name << endl;
		system("pause");
	}

	//�������� �����ϰ� �ϰ�
	//1. ����
	//	1. ����
	//	2. �Ǹ�
	//2. ��ȭ
	
	return GameEnd;
}

void EndGame()
{
	cout << "���� ����" << endl;
	Sleep(300);
}
