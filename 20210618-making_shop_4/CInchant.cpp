#include "main.h"
#include "CInchant.h"

void CInchant::Initialize()
{
    int i;
    int InchantPer = 52; //강화 확률 기준값 알아서들 조작해라.
                         //높을수록 잘 안뜨고, 낮을수록 잘뜸.

    for(i = 0; i < MAXINCHAN; i++)
    {
        InchanPer[i] = 1000 - (i * InchantPer);
    }
}

void CInchant::InchantTitle()
{
    cout << "-------------강화 화면-----------" << endl;
}

tagPlayer CInchant::PlayInchant(tagPlayer Player)
{
    while(true)
    {
        //지지고 볶고 하겠지...
        system("cls");
        cout << "현재 남은 골드 : " << Player.Money << endl;
        cout << "현재 아이템의 강화 상태 : " << Player.InchantPt << endl;
        cout << "현재 아이템의 강화 성공 확률 : " << (float)(InchanPer[Player.InchantPt]/10) << "%" << endl;

        //강화 하면 됨.
        //그 결과 찍어주면 됨.
        int StartIn = 0;
        int RandomValue = 0;
        cout << "1. 강화 시작" << endl;
        cout << "2. 강화 중지" << endl;
        cin >> StartIn;
        if(StartIn == 1)
        {
            srand((unsigned int)time(NULL));
            //1~1000
            //InchanPer[inchancnt]
            RandomValue = rand() % 1000 + 1;
            if(InchanPer[Player.InchantPt] >= RandomValue)
            {
                //강화가 성공
                Player.InchantPt++;
                Player.Money -= 1000;
                cout << "강화가 성공 하였습니다 1강 증가"<<endl;
                cout << "골드가 1000원 소비 되었습니다."<<endl;
            }        
            else
            {
                RandomValue = rand() % 100;

                if( RandomValue < 1)
                {
                    //1퍼 확률로 강화가 실패시 대실패 
                    Player.InchantPt = 0;
                    cout << "강화가 대실패 하였습니다 강화초기화"<<endl;
                }               
                else
                {
                    //강화가 실패
                    Player.InchantPt--;
                    if(Player.InchantPt < 0) Player.InchantPt = 0;
                    cout << "강화가 실패 하였습니다 1강 감소"<<endl;
                    
                }
                Player.Money -= 1000;
                cout << "골드가 1000원 소비 되었습니다."<<endl;
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

tagPlayer CInchant::Management(tagPlayer Player)
{
    //강화에 대한 것만 관리
    //cout << "여기는 인첸트의 관리 함수" << endl;

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
            Player = PlayInchant(Player);
        }
        else if(nUserInput == 2)
        {
            break;   
        }
    }
    
    return Player;
}