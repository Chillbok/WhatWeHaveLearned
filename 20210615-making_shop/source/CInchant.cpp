#include "CInchant.h"

void CInchant::Initialize()
{
    int i;

    for (i = 0; i < MAX_INCHANT; i++)
    {
        InchanPer[i] = 1000 - (1 * 52);
    }
}


void CInchant::InchantTitle()
{
    cout << "----------------------------" << endl;
    cout << "강화 화면" << endl;
    cout << "----------------------------" << endl;
}


void CInchant::PlayInchant(int Money, int Inchancnt)
{
    while (true)
    {
        system("cls");
        cout << "현재 남은 골드: " << Money << endl;
        cout << "현재 아이템의 강화 상태: " << Inchancnt << endl;
        cout << "현재 아이템의 강화 성공 확률: " << (float)(InchanPer[Inchancnt] / 10) << "%" << endl;

        //강화하면 된다.
        //그 결과를 찍어주면 된다.
        int StartIn, RandomValue = {};
        cout << "1. 강화 시작" << endl;
        cout << "2. 강화 중지" << endl;
        cin >> StartIn;
        if (StartIn == 1)
        {
            srand((unsigned int)time(NULL));
            //1 ~ 1000
            //InchanPer[Inchancnt]
            RandomValue = rand() % 1000 + 1;
            if (InchanPer[Inchancnt] >= RandomValue)
            {
                //강화가 성공
                Inchancnt++;
                Money -= 1000;
                cout << "1강 증가." << endl;
                cout << "강화가 성공하였씁니다." << endl;
                cout << "골드가 1000원 소비되었습니다." << endl;
            }
            else
            {
                RandomValue = rand() % 5;

                if (RandomValue < 1)
                {
                    //1퍼센트 확률로 강화 실패 시 대실패
                    Inchancnt = 0;
                    cout << "강화가 대실패하였습니다." << endl;
                    cout << "강화 초기화" << endl;
                }
                else
                {
                    //강화가 실패
                    Inchancnt--;
                    if (Inchancnt < 0) Inchancnt = 0;
                    cout << "강화가 실패했습니다." << endl;
                    cout << "1강 감소" << endl;
                }
                Money -= 1000;
                cout << "골드가 1000원 소비되었습니다." << endl;
            }
            system("pause");
        }
        else if (StartIn == 2) break;
        else cout << "잘못 입력함" << endl;
    }
}


void CInchant::Management(int Money, int Inchancnt)
{
    //강화에 대한 것만 관리
    //cout << "여기는 인챈트의 관리 함수" << endl;

    PlayerMoney = Money;
    PlayerInchancnt = Inchancnt;

    Initialize();

    int nUserInput = 0;

    while (true)
    {
        system("cls");
        InchantTitle();
        cout << "1. 강화 시도" << endl;
        cout << "2. 강화 종료" << endl;
        cin >> nUserInput;

        if (nUserInput == 1)
        {
            PlayInchant(PlayerMoney, PlayerInchancnt);
        }
        else if (nUserInput == 2)
        {
            break;
        }
    }
}