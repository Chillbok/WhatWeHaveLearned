셔플을 돌리고
0 ~ 번 방까지 있는 애들만 사용하면
9개짜리 배열을 만든 다음에
{
    int Number[9];
}
1 ~ 9까지 숫자를 넣어
{
    int i;
    for (i = 0; i < 9; i++)//i = 0 ~ 8까지 9번이 돈다.
    {
        Number[i] = i + 1;
    }
}
셔플을 돌리자
{
    srand(time(NULL));

    for(i = 0; i < 1; i++)
    {
        int Dest, Sour;
        int Temp;//임시
        Dest = rand() % 9;
        Sour = rand() % 9;

        Temp = Number[Dest];
        Number[Dest] = Number[Sour];
        Number[Sour] = Temp;
    }

    //유저에게 공개할 것이 아니기 때문에 공개 X
}