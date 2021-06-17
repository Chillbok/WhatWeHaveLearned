#include "main.h"
#include "CInchant.h"

void CInchant::Initialize()
{
    int i;
    /*강화 확률 기준값은 알아서 조작하자.
    높을수록 잘 안뜨고, 낮을수록 잘 뜬다.*/
    int int_InchantPer = 52;

    for (i = 0; i < MAX_INCHANT; i++)
    {
        bayeoll_InchanPer[i] = 1000 - (i * int_InchantPer);
    }
}



void CInchant::InchantTitle()
{
    cout << "==========================================" << endl;
    cout << "                   상점                    " << endl;
    cout << "==========================================" << endl;
    cout << "상점에 오신 것을 환영합니다." << endl;
}



tagPlayer CInchant::PlayInchant(tagPlayer Player)
{
    while(true)
    {
        system("cls");
        cout << "현재 남은 골드: " << Player.Money << endl;
        cout << "현재 아이템의 강화 상태: " << Player.InchantPt << endl;
        cout << "현재 아이템의 강화 성공 확률: " << (float)(bayeoll_InchanPer[Player.InchantPt]/10) << endl;
        cout << endl << endl;
        cout << "==========================================" << endl;
        cout << "[상인]" << endl;
        cout << "성공할 확률은 이렇습니다. 계속하시겠습니까?" << endl;
        cout << "==========================================";

        Turning_Pages();

        //강화하면 된다. 그리고 그 결과를 찍어주면 된다.
        int StartIn, RandomValue, SeeResult = {};
        cout << "1. 강화 시작" << endl;
        cout << "2. 강화 중지" << endl;
        cin >> StartIn;
        if(StartIn == 1)
        {
            srand((unsigned int)time(NULL));
            //1 ~ 1000
            //bayeoll_InchanPer[inchancnt]
            RandomValue = rand() % 1000 + 1;
            if(bayeoll_InchanPer[Player.InchantPt] >= RandomValue)
            {
                //강화가 성공
                Player.InchantPt++;
                Player.Money -= 1000;
                cout << "==========================================" << endl;
                cout << "[상인]" << endl;
                cout << "축하합니다. 다행히 아무 문제도 일어나지 않았" << endl;
                cout << "습니다. 결과는 성공적입니다." << endl;
                cout << "==========================================" << endl;
                
                Turning_Pages();

                cout << "==========================================" << endl;
                cout << "[상인]" << endl;
                cout << "골드는 1000원 소비되었습니다. 결과를 확인하시겠습니까?" << endl;
                cout << endl;
                cout << "==========================================" << endl;
                cout << "1. 예" << endl;
                cout << "2. 아니요" << endl;
                cout << "--> ";
                cin >> SeeResult;

                Turning_Pages();

                while(true)
                {
                    if(SeeResult == 0)
                    {
                        cout << "==========================================" << endl;
                        cout << "[상인]" << endl;
                        cout << "손님? 죄송하지만 뒤쪽에 기다리시는 손님들이 많" << endl;
                        cout << "습니다. 빨리 말해주셔야 합니다." << endl;
                        cout << "==========================================" << endl;

                        Turning_Pages();

                        continue;
                    }
                    else if(SeeResult == 1)
                    {
                        cout << "==========================================" << endl;
                        cout << "[상인]" << endl;
                        cout << "네, 알겠습니다. 지금 영수증과 명세서를 드리겠" << endl;
                        cout << "습니다." << endl;
                        cout << "==========================================" << endl;
                        
                        Turning_Pages();

                        break;
                    }
                    else if(SeeResult == 2)
                    {
                        cout << "==========================================" << endl;
                        cout << "[상인]" << endl;
                        cout << "알겠습니다. 좋은 하루 되시길 빌겠습니다." << endl;
                        cout << "상점을 이용해주셔서 감사합니다." << endl;
                        cout << "==========================================" << endl;

                        Turning_Pages();

                        break;
                    }
                    else
                    {
                        cout << "==========================================" << endl;
                        cout << "[상인]" << endl;
                        cout << "손님? 죄송하지만 뒤쪽에 기다리시는 손님들이 많" << endl;
                        cout << "습니다. 빨리 말해주셔야 합니다." << endl;
                        cout << "==========================================" << endl;

                        Turning_Pages();

                        continue;
                    }
                }
                if(SeeResult == 1)
                {
                    cout << "==========================================" << endl;
                    cout << "지불 골드: " << 1000 << endl;
                    cout << "현재 남은 골드: " << Player.Money << endl;
                    cout << "현재 아이템의 강화 상태: " << Player.InchantPt << endl;
                    cout << "==========================================" << endl;
                }
            }
            else
            {
                RandomValue = rand() % 100;

                if(RandomValue < 1)
                {
                    //1퍼센트 확률로 강화가 실패 시 대실패
                    Player.InchantPt = 0;
                    cout << "==========================================" << endl;
                    cout << "[상인]" << endl;
                    cout << "죄송합니다." << endl;
                    cout << "강화가 완전히 실패하였습니다." << endl;
                    cout << "==========================================" << endl;

                    Turning_Pages();

                    cout << "==========================================" << endl;
                    cout << "[상인]" << endl;
                    cout << "무기가 완전히 파괴될 뻔 했지만, 다행히 부서지" << endl;
                    cout << "지는 않았습니다. 하지만 처음부터 다시 강화" << endl;
                    cout << "==========================================" << endl;

                    Turning_Pages();

                    cout << "==========================================" << endl;
                    cout << "[상인]" << endl;
                    cout << "하셔야 합니다." << endl;
                    cout << endl;
                    cout << "==========================================" << endl;

                    Turning_Pages();
                }
                else{
                    //강화가 실패
                    Player.InchantPt--;
                    if (Player.InchantPt < 0) Player.InchantPt = 0;
                    
                    cout << "==========================================" << endl;
                    cout << "[상인]" << endl;
                    cout << "죄송합니다. 강화가 실패하였습니다." << endl;
                    cout << "무기가 다행히 부서지지는 않았지만, 강화 단계" << endl;
                    cout << "==========================================" << endl;

                    Turning_Pages();

                    cout << "==========================================" << endl;
                    cout << "[상인]" << endl;
                    cout << "가 한 단계 낮아졌습니다." << endl;
                    cout << endl;
                    cout << "==========================================" << endl;

                    Turning_Pages();
                }
                Player.Money -= 1000;
                cout << "==========================================" << endl;
                cout << "[상인]" << endl;
                cout << "1000골드 소비되었습니다." << endl;
                cout << endl;
                cout << "==========================================" << endl;

                Turning_Pages();
            }
        }
        else if(StartIn == 2) break;
        else
        {
            cout << "==========================================" << endl;
            cout << "[상인]" << endl;
            cout << "네, 알겠습니다. 그럼 뭘 하시겠습니까?" << endl;
            cout << endl;
            cout << "==========================================" << endl;

            Turning_Pages();
        }
    }

    return Player;
}



tagPlayer CInchant::Management(tagPlayer Player)
{
    //여기에서는 강화에 대한 것만 관리한다.
    //cout << "여기는 인챈트의 관리 함수" << endl;

    int nUserInput = 0;

    while(true)
    {
        system("cls");
        InchantTitle();

        cout << "1. 강화 시도" << endl;
        cout << "2. 강화 종료" << endl;
        cin >> nUserInput;

        if(nUserInput == 1) Player = PlayInchant(Player);
        else if(nUserInput == 2) break;
    }
    return Player;
}