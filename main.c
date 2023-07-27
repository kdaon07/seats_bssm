#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

typedef struct {        // ����ü
    int data[16];
    int top;
} Stack;

int a = 0;
Stack jh;

void change(int a, int b)
{
    int i, j;
    for (i = 0; i <= 16; i++)       // ��ġ ã��
        if (jh.data[i] == a)
            break;

    for (j = 0; j <= 16; j++)
        if (jh.data[j] == b)
            break;

    int temp = jh.data[j];      // �� ���� ����
    jh.data[j] = jh.data[i];
    jh.data[i] = temp;
    system("cls");      // ȭ�� �ʱ�ȭ
    printf("\n================�ڸ� ��ġǥ================\n\n");
    printf("\t\t   ĥ��\n\n");
    for (int i = 0; i < 16; i++)    // �������� ���� �ڸ� ǥ��
    {
        printf("\t%2d ", jh.data[i]);
        if((i+1)%4==0) printf("\n\n");
    }
}

int dup(int d)      // �ߺ� Ȯ��
{
    for (int i = 0; i <= jh.top; i++)
    {
        if (jh.data[i] == d)        // �ߺ� Ȯ��
            return 1;
    }
    return 0;
}

void init_stack(Stack *s)       // �ʱ�ȭ
{
    s->top = -1;
}

void push(Stack *s, int item)
{
    if (dup(item)) a--;     // �ߺ��̸� �ݺ��� �ѹ��� �ݺ�
    else s->data[++(s->top)] = item;        //���� ����
}

void rd()
{
    for (a = 0; a < 16; a++)
    {
        int rad = rand() % 16 + 1;      // ������ ������ ����
        push(&jh, rad);     // Ǫ��
    }
}

int main()
{
    int ch[2];
reset:      // goto reset
    system("cls");
    init_stack(&jh);        // ���� �ʱ�ȭ
    srand(time(NULL));      // ���� �ʱ�ȭ
    rd();       // ���� �Լ� ����
    printf("\n================�ڸ� ��ġǥ================\n\n");
    printf("\t\t   ĥ��\n\n");
    for (int i = 0; i < 16; i++)    // �������� ���� �ڸ� ǥ��
    {
        Sleep(500);
        printf("\t%2d ", jh.data[i]);
        if((i+1)%4==0) printf("\n\n");
    }
    while(1)
    {
        printf("�ڸ��� �ٲܷ��� ��ȣ 2���� �Է����ּ��� : ");
        scanf("%d", &ch[0]);
        if(ch[0] == 0) break;       // ����
        if(ch[0] == -1) goto reset;     // �ѹ� �� �̱�
        scanf("%d", &ch[1]);
        change(ch[0], ch[1]);       // �Լ� ȣ��
    }
    return 0;
}
