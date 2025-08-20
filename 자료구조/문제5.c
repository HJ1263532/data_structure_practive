#include<stdio.h>
//queue 문제. 원형 queue문제.
#define SIZE 6
int queue[SIZE];//저장 할 배열
int front = -1, rear = -1;

int checkFull(){
    //가득 찼는지, 혹은 위배?? 되었는지 확인
    //enqueue여부 확인을 위해 존재함
    if ((front == rear + 1) || (front == 0 && rear == SIZE - 1))
    {
        return 1;
    }
    return 0;
}

int checkEmpty(){
    //queue에 아무것도 없는지 확인
    //dequeue가능 여부 확인
    if (front == -1){
        return 1;
    }
    return 0;
}

void enqueue(int value){
    if (checkFull())
        //rear,front 확인하고 위배시 1을 받아 true됨.
        printf("Overflow condition\n");
    else {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % SIZE;
        //enqueue는 front 상관 없음. rear을 한 칸 뒤로 보내주는 부분.
        queue[rear] = value;
    }
}

int dequeue(){
    int variable;
    if (checkEmpty()) {//큐 확인.
        printf("Underflow condition\n");
        return -1;
    }
    else {
        variable = queue[front];//값 저장.
        if (front == rear) {//배열 공간은 남음. 단 값은 없음.
            front = rear = -1;
        }//이 식 만족시 처음 상태로 되돌아간다고 생각하면 됨
        else {
            front = (front + 1) % SIZE;
            // dequeue는 rear와 상관 없음. front를 한 칸 뒤로 보내줌.
            //값 없어짐. 없어진 부분값은 variable에 저장됨.
        }
        return variable;
    }
}

void display() {
    int i;
    if (checkEmpty())//큐에 정보가 없으면...
        printf("Nothing to dequeue\n");
    else{
        for (i = front; i != rear; i = (i + 1) % SIZE)
        //i는 front 부터 rear가 될 때 까지
        //i=(i+1)%SIZE는 하나씩 다음 노드로 하기. 원형 큐 이므로 
        //front보다 rear이 작을 수 있음.
        {
            printf("%d \n", queue[i]);
        }
        printf("%d \n", queue[i]);//rear번째의 queue값 출력
    }
}

int main(){
    enqueue(15);
    enqueue(20);
    display();

    dequeue();  //15뺌
    display();  //20만 남음

    dequeue();  //20뺌
    dequeue();  //값이 없음. Underflow condition
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    enqueue(7);   //값이 6보다 많음. Overflow condition
    //displau전에 Overflow표시. 왜? enqueue에 Overflow 메시지가 있으니까
    display();

    return 0;
}
