#include <iostream>
#inclde <string>
#include <Windows.h>
#include "time.h"

using namespace std;



void C_and_Cpp_both()//C와 C++에서 모두 사용하는 것들
{
  /*
  이스케이프 시퀸스: 역슬래시하고 쓰는 것들

  대표적인 예시: \t, \n, \v, ...
  */
  //\t
  /*
  tab을 사용해주는 이스케이프 시퀸스이다.
  */
  cout << "\" << "t 예시: " << endl;
  cout << "안녕하세요\t저는" << endl;
  cout << "/t사람입니다." << endl << endl;
  cout << "======================" << endl << endl;

  //\n 예시
  /*
  줄을 바꾸어주는 이스케이프 시퀸스이다.
  endl과 같은 용도로 사용된다.
  */
  cout << "안녕하세요.\n저는\n사람입니다." << endl;
}

void Input_in_C()//C에서의 입력
{
  /*
  입력: scanf("서식문자", 입력받을 내용의 주소값);
  출력은 안에 값이 이미 있기 때문에 얼마만큼을(크기)
  출력하면 되는가에 대해서 미리 알 수 있다.

  입력을 받을 때는 유저가 얼마만큼을 입력할지를 가늠할 수가 없다.

  아이디 만들때 --> 2 ~ 8글자
  */
  int num;//입력받아서 담아둘 변수.
  //
  scanf("%d", &num);

  printf("%d", num);
}

int main()
{
  C_and_Cpp_both();

  return 0;
}
