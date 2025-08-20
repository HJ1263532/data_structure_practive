#include <stdio.h>
#define SIZE 100
/*
큐 문제
큐는 한 쪽에서 삽입이, 다른 한 쪽에서는 삭제가 이뤄지는 선입선출(First In First Out)형식의 선형 자료구조이다.
삭제연산만 수행되는 곳을 보통 front, 삽입 연산만 수행되는 곳을 보통 rear라고 함.
rear에서 이루어지는 삽입 연산을 enQueue, front 에서 이루어지는 삭제 연산을 dnQueue라고 함.
입력>> 1->2->3
출력>>1->2->3
*/

//전방선언
void enqueue(int n);
int dequeue();
void show();

int inp_arr[SIZE];//size는 100
int Rear = -1;
int Front = -1;
int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    show();

    dequeue();
    dequeue();
    show();
}
void enqueue(int n)
{
    if (Rear == SIZE - 1)//index 넘침
        printf("Overflow \n");
    else
    {
        if (Front == -1)
            Front = 0;//처음 인덱스의 위치 지정.>> 그럼 front를 처음부터 0부터 하면 안 됨??
        Rear = Rear + 1;//뒤로 가며 값을 넣을 부분을 지정하는 것
        inp_arr[Rear] = n;
    }
}
int dequeue()
{
    if (Front == -1 || Front > Rear){
        printf("Underflow \n");
        return;
    }
    else{
        Front = Front + 1;//앞의 부분을 지우는 것. index가 뒤로 가야함.
        return inp_arr[Front - 1];//표현하며 지움
    }
}

void show(){
    if (Front == -1)//queue 시작 안 했을 때
        printf("Empty Queue \n");
    else {
        for (int i = Front; i <= Rear; i++)
            printf("%d \n", inp_arr[i]);
        printf("\n");
    }
}
