#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

typedef struct {        // 구조체
    int data[16];
    int top;
} Stack;

int a = 0;
Stack jh;

void change(int a, int b)
{
    int i, j;
    for (i = 0; i <= 16; i++)       // 위치 찾기
        if (jh.data[i] == a)
            break;

    for (j = 0; j <= 16; j++)
        if (jh.data[j] == b)
            break;

    int temp = jh.data[j];      // 값 서로 변경
    jh.data[j] = jh.data[i];
    jh.data[i] = temp;
    system("cls");      // 화면 초기화
    printf("\n================자리 배치표================\n\n");
    printf("\t\t   칠판\n\n");
    for (int i = 0; i < 16; i++)    // 랜덤으로 나온 자리 표시
    {
        printf("\t%2d ", jh.data[i]);
        if((i+1)%4==0) printf("\n\n");
    }
}

int dup(int d)      // 중복 확인
{
    for (int i = 0; i <= jh.top; i++)
    {
        if (jh.data[i] == d)        // 중복 확인
            return 1;
    }
    return 0;
}

void init_stack(Stack *s)       // 초기화
{
    s->top = -1;
}

void push(Stack *s, int item)
{
    if (dup(item)) a--;     // 중복이면 반복문 한번더 반복
    else s->data[++(s->top)] = item;        //스택 저장
}

void rd()
{
    for (a = 0; a < 16; a++)
    {
        int rad = rand() % 16 + 1;      // 변수에 랜던값 저장
        push(&jh, rad);     // 푸쉬
    }
}

int main()
{
    int ch[2];
reset:      // goto reset
    system("cls");
    init_stack(&jh);        // 스택 초기화
    srand(time(NULL));      // 랜덤 초기화
    rd();       // 랜덤 함수 시작
    printf("\n================자리 배치표================\n\n");
    printf("\t\t   칠판\n\n");
    for (int i = 0; i < 16; i++)    // 랜덤으로 나온 자리 표시
    {
        Sleep(500);
        printf("\t%2d ", jh.data[i]);
        if((i+1)%4==0) printf("\n\n");
    }
    while(1)
    {
        printf("자리를 바꿀려면 번호 2개를 입력해주세요 : ");
        scanf("%d", &ch[0]);
        if(ch[0] == 0) break;       // 종료
        if(ch[0] == -1) goto reset;     // 한번 더 뽑기
        scanf("%d", &ch[1]);
        change(ch[0], ch[1]);       // 함수 호출
    }
    return 0;
}
