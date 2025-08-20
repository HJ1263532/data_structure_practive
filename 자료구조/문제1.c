#include<stdio.h>

#define SIZE 100
/*
스택 문제
스택이란 한쪽에서만 자료를 넣고 뺄 수 있는 후입 선출(Last In First Out) 형식의
선형 자료 구조이다.
입력>> 1->2->3
출력>> 3->2->1
*/

int stack[SIZE], choice, top;
void push(int x);
int pop(void);
void display(void);
int main() {

    top = -1; //top 설정

    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    display();

    pop();
    pop();

    display();

    return 0;

}

void push(int x)//데이터 삽입
{
    if (top >= SIZE - 1)//index의 끝 번호임
        printf("\n\tSTACK is over flow");
    else
    {
        top++;
        stack[top] = x;
    }
}
int pop()//데이터 삭제
{
    if (top <= -1) {//아무것도 없거나, 없는데 뺄 때
        printf("\n\t Stack is under flow");
    }
    else {
        top--;
        return stack[top + 1];
    }
}

void display()//배열 출력인듯
{
    int i;
    if (top >= 0)
    {
        for (i = top; i >= 0; i--)
            printf("%d \n", stack[i]);
        printf("\n");
    }
    else
    {
        printf("\n The STACK is empty");
    }
}
