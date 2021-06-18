#include "main.h"
#include "CInchant.h"
#include "CSell.h"

tagPlayer Player;

//초기화 함수
void Initialize()
{
    Player.Money = 10000; //초기 머니
    for(int i = 0; i < INVEN_END; i++)
    {
	    Player.Inventory[i] = INVEN_NULL;
	    Player.InchantPt[i] = 0;
    }


















    Player.InchantPt = 0; //처음 가지고 있는 아이템 수치
}

//관리 함수
void Management()
{
    //순서대로 유저의 선택이나 상황에 따라서
    //알맞은 장면을 호출.
    //예전에 메인에서 하던걸 여기서 할꺼란 얘기
    bool GameEnd = false;

    //오프닝부
    Openning();

    //메인게임부
    while(true)
    {
        GameEnd = MainGame();
        if(GameEnd == true) break;
    }
       
    //종료
    EndGame();
}

int main()
{
    //클래스 : 상점파트 - 구매, 판매 , 강화클래스
    Management();

    return 0;
}

void Openning()
{
    cout << "타이틀 화면임" << endl;
    //뭐 하고싶은 사람은 알아서들 꾸며라
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
        //메인게임 화면은 알아서들 꾸미구여........
        system("cls");
        cout << "1. 상점" << endl;
        cout << "2. 강화" << endl;
        cout << "3. 종료" << endl;
        cin >> nUserInput;

        if(nUserInput == 1) // 상점
        {       
            Player = Sell.Management(Player);
        }
        else if(nUserInput == 2) //강화
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
    //유저에게 선택하게 하고
    //1. 상점
    //   -> 상점 클래스의 매니지먼트 함수 호출
    //      유저의 선택의 결과에 따라서, 
    //      상점을 선택했으면 다시한번 선택지가 뜬다
    //      상점을 선택했으면 다시한번 유저의 선택을 받고.
    //      1. 구매
    //         구매를 선택했으면, 구매 화면이 뜬다.
    //         -> 상점 클래스의 구매 함수 호출.
    //      2. 판매
    //         판매를 선택했으면, 판매 화면이 뜬다.
    //         -> 상점 클래스의 판매 함수 호출.
    //2. 강화
    //   -> 강화 클래스의 매니지먼트 함수 호출
    

    //      강화를 선택 했으면 강화 화면이 뜬다.


    //종료와 관련된 명령을 실행했다.(무언가 트리거가 있다는 얘기)
    //if (그 트리거가 충족이 되면) GameEnd = true;

    

    return GameEnd;
}

void EndGame()
{
    cout << "게임 종료" << endl;
    Sleep(300);
}

