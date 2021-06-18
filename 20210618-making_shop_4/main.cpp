#include "main.h"
#include "CInchant.h"
#include "CSell.h"

tagPlayer Player;

//�ʱ�ȭ �Լ�
void Initialize()
{
    Player.Money = 10000; //�ʱ� �Ӵ�
    for(int i = 0; i < INVEN_END; i++)
    {
	    Player.Inventory[i] = INVEN_NULL;
	    Player.InchantPt[i] = 0;
    }


















    Player.InchantPt = 0; //ó�� ������ �ִ� ������ ��ġ
}

//���� �Լ�
void Management()
{
    //������� ������ �����̳� ��Ȳ�� ����
    //�˸��� ����� ȣ��.
    //������ ���ο��� �ϴ��� ���⼭ �Ҳ��� ���
    bool GameEnd = false;

    //�����׺�
    Openning();

    //���ΰ��Ӻ�
    while(true)
    {
        GameEnd = MainGame();
        if(GameEnd == true) break;
    }
       
    //����
    EndGame();
}

int main()
{
    //Ŭ���� : ������Ʈ - ����, �Ǹ� , ��ȭŬ����
    Management();

    return 0;
}

void Openning()
{
    cout << "Ÿ��Ʋ ȭ����" << endl;
    //�� �ϰ���� ����� �˾Ƽ��� �ٸ��
    system("pause");  
}

bool MainGame()
{
    Initialize();
    bool GameEnd = false;
    CInchant Inchant;
    CSell    Sell;
    CBuy     Buy;
    
    int nUserInput = 0;

    while(true)
    {
        //���ΰ��� ȭ���� �˾Ƽ��� �ٹ̱���........
        system("cls");
        cout << "1. ����" << endl;
        cout << "2. ��ȭ" << endl;
        cout << "3. ����" << endl;
        cin >> nUserInput;

        if(nUserInput == 1) // ����
        {       
            Player = Sell.Management(Player);
        }
        else if(nUserInput == 2) //��ȭ
        {
            Player = Inchant.Management(Player);
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
    }
    //�������� �����ϰ� �ϰ�
    //1. ����
    //   -> ���� Ŭ������ �Ŵ�����Ʈ �Լ� ȣ��
    //      ������ ������ ����� ����, 
    //      ������ ���������� �ٽ��ѹ� �������� ���
    //      ������ ���������� �ٽ��ѹ� ������ ������ �ް�.
    //      1. ����
    //         ���Ÿ� ����������, ���� ȭ���� ���.
    //         -> ���� Ŭ������ ���� �Լ� ȣ��.
    //      2. �Ǹ�
    //         �ǸŸ� ����������, �Ǹ� ȭ���� ���.
    //         -> ���� Ŭ������ �Ǹ� �Լ� ȣ��.
    //2. ��ȭ
    //   -> ��ȭ Ŭ������ �Ŵ�����Ʈ �Լ� ȣ��
    

    //      ��ȭ�� ���� ������ ��ȭ ȭ���� ���.


    //����� ���õ� ����� �����ߴ�.(���� Ʈ���Ű� �ִٴ� ���)
    //if (�� Ʈ���Ű� ������ �Ǹ�) GameEnd = true;

    

    return GameEnd;
}

void EndGame()
{
    cout << "���� ����" << endl;
    Sleep(300);
}

