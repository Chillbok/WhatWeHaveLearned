#include "main.h"
#include "CInchant.h"
#include "CSell.h"

tagPlayer Player;

//초기화 함수
void Initialize()
{
    Player.Money = 10000; //초기 머니
    Player.InchantPt = 0;//처음 가지고 있는 아이템 수치

}

//관리 함수
void Management()
{
    /*
    순서대로 유저의 선택이나 상황에 따라서
    알맞은 장면을 호출한다.
    예전에 메인 함수에서 하던 것을 이 함수에서 실행한다.
    */
    bool GameEnd = false;//게임 끝을 결정짓는 참/거짓 변수

    //오프닝부
    Opening();

    //메인 게임부
    while(true)
    {
        GameEnd = MainGame();
        if(GameEnd == true) break;
    }

    //종료
    EndGame();
}

//메인 함수
int main()
{
    //클래스-상점 파트: 구매, 판매, 강화
    Management();

    return 0;
}

void Turning_Pages()
{
    system("pause");
    system("cls");
}

void Opening()
{
    cout << "===========================" << endl;
    cout << "상점에 오신 것을 환영합니다." << endl;
    cout << "===========================" << endl;

    system("pause");
}

bool MainGame()
{
    Initialize();
    bool GameEnd = false;
    CInchant    Inchant;
    CSell       Sell;

    int nUserInput = 0;

    while(true)
    {
        //메인 게임 화면은 알아서 꾸미기
        system("cls");
        cout << "1. 상점" << endl;
        cout << "2. 강화" << endl;
        cout << "3. 종료" << endl;
        cin >> nUserInput;

        if(nUserInput == 1)//상점
        {
            Player = Sell.Management(Player);
        }
        else if(nUserInput == 2)//강화
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
            cout << "없는 선택지를 선택" << endl;
            Sleep(300);
        }
    }

    return GameEnd;
}




void EndGame()
{
    cout << "게임 종료" << endl;
    Sleep(300);
}