#include "CInchant.h"

void CInchant::Initialize()
{
    int i;

    for (i = 0; i < MAXINCHANT; i++)
    {
        InchantPersent[i] = 1000 - (i * 52);
    }
}

void InchantTitle()
{
    cout << "이곳은 가진 장비를 강화하는 곳입니다." << endl;
    cout << "==================================" << endl;
}

void CInchant::Management(int Money, int inchancnt)
{
    //강화에 대한 것만 관리
    //cout << "여기는 인챈트의 관리 함수" << endl;

    PlayerMoney = Money;
    PlayerInchancnt = inchancnt;

    InchantTitle();

    int nUserInput = 0;

    while(true)
    {
        system("cls");
        InchantTitle();
        cout << "무엇을 하시겠습니까?" << endl;
        cout << "하고 싶은 행동의 번호를 적어주세요." << endl;
        cout << "1. 강화 시도" << endl;
        cout << "2. 강화 취소" << endl;
        cout << "--> " << endl;
        cin >> nUserInput;
        system("cls");
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


void CInchant::PlayInchant(int Money, int Inchancnt)//강화 받는 함수
{
    cout << "현재 당신의 돈: " << Money << endl;
    cout << "현재 아이템의 강화 상태: " << endl;
    cout << "현재 아이템의 인챈트 성공 확률: " << endl;
    system("pause");
}

int Asking_Inchanting(int nUserInput)
{
    while(true)
    {
        cout << "무엇을 하시겠습니까?" << endl;
        cout << "하고 싶은 행동의 번호를 적어주세요." << endl;
        cout << "1. 강화 시도" << endl;
        cout << "2. 강화 종료" << endl;
        cout << "--> " << endl;
        cin >> nUserInput;
        system("cls");

        if (nUserInput == 1)//강화 시도하고 그 결과를 출력하는 함수를 호출
        {
            cout << "강화 시도(구현 예정)" << endl;
        }
        else if (nUserInput == 2)//강화를 하지 않고 다시 메인 화면으로 돌아가기
        {
            cout << "강화 취소(구현 예정)" << endl;
        }
        else
        {
            cout << "잘못 입력하셨습니다." << endl;
            cout << "다시 입력하세요." << endl;
            system("cls");
            continue;
        }
    }
    return nUserInput;
}