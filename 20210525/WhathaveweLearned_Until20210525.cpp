#include <iostream>//C++에서 입출력을 하기 위한 라이브러리
#include <string>//C에서 입출력을 하기 위한 라이브러리
#include "Windows.h"
#include <time.h>
using namespace std;



void SangNumber()
{
    #define NUMBER 100
    /*
    define 문에는 ";"가 붙지 않는다.
    */

    //NUMBER = 10000
    /*
    위처럼 그대로 사용할 경우, 에러가 발생하게 된다.
    #define을 통해 선언한 값은 함부로 바꾸려고 해서는 안된다.
    바꾸기 위해서는 0으로 초기화한 다음에 사용해야 한다.
    */
    cout << NUMBER;
}




int main()
{

    return 0;
}
