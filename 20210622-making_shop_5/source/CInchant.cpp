#include "main.h"
#include "CInchant.h"

void CInchant::Initialize()
{
	int i;
	int InchantPer = 52;//��ȭ Ȯ�� ���ذ�(�������� �� �� �߰�, �������� �� ���.)

	for(i = 0; i < MAXINCHAN; i++)
	{
		InchanPer[i] = 1000 - (i * InchantPer);
	}
	//��޿� ���� �ٸ��� �����ǰ�
	//������ �迭
}

void CInchant::InchantTitle()
{
	cout << "��ȭ ȭ��" << endl;
}

tagPlayer CInchant::PlayInchant(tagPlayer Player, tagItem* Item)
{
	while(true)
	{
		//������ ���� �ϰ���...
		system("cls");
		cout << "���� ���� ���: " << Player.Money << endl;
		
		/*
		 ��ȭ�� ������ ����
		 */
		cout << "���� �������� ��ȭ ����: " << Player.InchantPt[0] << endl;
		cout << "���� �������� ��ȭ ���� Ȯ��: " << (float)(InchanPer[Player.InchantPt[0]]/10) << endl;

		//��ȭ�ϸ� �ȴ�. �׸���, �� ����� ����ָ� �ȴ�.
		int StartIn = 0;
		int RandomValue = 0;
		cout << "1. ��ȭ ����" << endl;
		cout << "2. ��ȭ ����" << endl;
		cin >> StartIn;
		if(StartIn == 1)
		{
			srand((unsigned int)time(NULL));
			//1 ~ 1000
			//InchanPer[inchancnt]
			RandomValue = rand() % 1000 + 1;
			if(InchanPer[Player.InchantPt[0]] >= RandomValue)
			{
				//��ȭ�� ����
				Player.InchantPt[0]++;
				Player.Money -= 1000;
				cout << "��ȭ�� �����Ͽ����ϴ�. 1�� ����" << endl;
				cout << "��尡 1000�� �Һ�Ǿ����ϴ�." << endl;
			}
			else
			{
				RandomValue = rand() % 100;

				if(RandomValue < 1)
				{
					//1�ۼ�Ʈ Ȯ���� ��ȭ�� ���н� �����
					Player.InchantPt[0] = 0;
					cout << "��ȭ�� ������Ͽ����ϴ�." << endl;
					cout << "��ȭ�� �ʱ�ȭ�մϴ�." << endl;
				}
				else
				{
					//��ȭ�� ����
					Player.InchantPt[0]--;
					if(Player.InchantPt[0] < 0) Player.InchantPt[0] = 0;
					cout << "��ȭ�� �����Ͽ����ϴ�." << endl;
					cout << "1�� ���ҵǾ����ϴ�." << endl;
				}
				Player.Money -= 1000;
				cout << "��尡 1000�� �Һ�Ǿ����ϴ�." << endl;
			}
			system("pause");
		}
		else if(StartIn == 2)
		{
			break;
		}
		else
		{
			cout << "�߸� �Է���" << endl;
		}
	}
	return Player;
}

tagPlayer CInchant::Management(tagPlayer Player, tagItem* Item)//��æƮ�� �����Լ�
{
	//��ȭ�� ���� �͵鸸 �����Ѵ�.
	Initialize();
	
	int nUserInput = 0;

	while(true)
	{
		system("cls");
		InchantTitle();
		cout << "1. ��ȭ �õ�" << endl;
		cout << "2. ��ȭ ����" << endl;
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
