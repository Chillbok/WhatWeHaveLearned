//열거문
/*
구조체랑 굉장히 자주 연관되어 사용되는 것(경험 상)
*/
#include <iostream>
#include <string>

/*
int main()
{
    struct tagPlayer
    {
        string Name;
        int Age;
    }

    tagPlayer Player[4];//0 ~ 3번까지의 플레이어
    
    enum NAME{NAME_FIGHTER, NAME_MAGITIAN, NAME_PRIST, NAME_THIEF};//열거형 생성
    
    //enum 문은 enum을 제외한 모든 것들을 대문자로 쓰는 것이 원칙

    Player[NAME_FIGHTER].Name = "a";
    Player[NAME_MAGITIAN].Name = "b";
    Player[NAME_PRIST].Name = "c";
    Player[NAME_THIEF].Name = "d";

    return 0;
}
*/




int main()
{
    //switch case와도 많이 연계되어 사용된다.
    //

    enum NAME Name;
    Name = NAME_FIGHTER;

    switch (Name)
    {
        case NAME_FIGHTER:


        break;
    }











    return 0;
}
