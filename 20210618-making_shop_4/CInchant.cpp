#include "main.h"
#include "CInchant.h"

void CInchant::Initialize()
{
    int i;
    int InchantPer = 52; //��ȭ Ȯ�� ���ذ� �˾Ƽ��� �����ض�.
                         //�������� �� �ȶ߰�, �������� �߶�.

    for(i = 0; i < MAXINCHAN; i++)
    {
        InchanPer[i] = 1000 - (i * InchantPer);
    }
}

void CInchant::InchantTitle()
{
    cout << "-------------��ȭ ȭ��-----------" << endl;
}

tagPlayer CInchant::PlayInchant(tagPlayer Player)
{
    while(true)
    {
        //������ ���� �ϰ���...
        system("cls");
        cout << "���� ���� ��� : " << Player.Money << endl;
        cout << "���� �������� ��ȭ ���� : " << Player.InchantPt << endl;
        cout << "���� �������� ��ȭ ���� Ȯ�� : " << (float)(InchanPer[Player.InchantPt]/10) << "%" << endl;

        //��ȭ �ϸ� ��.
        //�� ��� ����ָ� ��.
        int StartIn = 0;
        int RandomValue = 0;
        cout << "1. ��ȭ ����" << endl;
        cout << "2. ��ȭ ����" << endl;
        cin >> StartIn;
        if(StartIn == 1)
        {
            srand((unsigned int)time(NULL));
            //1~1000
            //InchanPer[inchancnt]
            RandomValue = rand() % 1000 + 1;
            if(InchanPer[Player.InchantPt] >= RandomValue)
            {
                //��ȭ�� ����
                Player.InchantPt++;
                Player.Money -= 1000;
                cout << "��ȭ�� ���� �Ͽ����ϴ� 1�� ����"<<endl;
                cout << "��尡 1000�� �Һ� �Ǿ����ϴ�."<<endl;
            }        
            else
            {
                RandomValue = rand() % 100;

                if( RandomValue < 1)
                {
                    //1�� Ȯ���� ��ȭ�� ���н� ����� 
                    Player.InchantPt = 0;
                    cout << "��ȭ�� ����� �Ͽ����ϴ� ��ȭ�ʱ�ȭ"<<endl;
                }               
                else
                {
                    //��ȭ�� ����
                    Player.InchantPt--;
                    if(Player.InchantPt < 0) Player.InchantPt = 0;
                    cout << "��ȭ�� ���� �Ͽ����ϴ� 1�� ����"<<endl;
                    
                }
                Player.Money -= 1000;
                cout << "��尡 1000�� �Һ� �Ǿ����ϴ�."<<endl;
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

tagPlayer CInchant::Management(tagPlayer Player)
{
    //��ȭ�� ���� �͸� ����
    //cout << "����� ��þƮ�� ���� �Լ�" << endl;

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
            Player = PlayInchant(Player);
        }
        else if(nUserInput == 2)
        {
            break;   
        }
    }
    
    return Player;
}