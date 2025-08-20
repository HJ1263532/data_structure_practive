#include < stdio.h > 
#include < stdlib.h >
//구조체를 이용한 queue문제. FIFO임
struct node {
    int data;
    struct node* next;
};
struct node* front = NULL;
struct node* rear = NULL;

void enqueue(int value) {//노드니까 overflow 없음
    struct node* ptr;//ptr 포인터 생성
    ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = value;
    ptr->next = NULL;
    if ((front == NULL) && (rear == NULL)) {
        front = rear = ptr;//처음??일 떄. ptr로 1번째 기준 생성
    }
    else {
        rear->next = ptr;//n번째의 next는 prt
        rear = ptr;//n+1번째 노드를 ptr로 함.
    }
}

int dequeue() {//첫번째 노드 해제해주는 부분.
    if (front == NULL) {
        printf("\nUnderflow\n");
        return -1;
    }
    else {
        struct node* temp = front;//맨 앞에 있는 노드를 받음.
        int temp_data = front->data;
        front = front->next;
        free(temp);//front 옮긴 후 front 앞 노드 해제.
        return temp_data;//이 temp_data 어디에 쓰려고 리턴함??
    }
}

void display() {
    struct node* temp;
    if ((front == NULL) && (rear == NULL)) {
        printf("\nQueue is Empty\n");
    }
    else {
        temp = front;//첫 번째 노드부터
        while (temp) {//temp!=NULL
            printf("%d \n", temp->data);
            temp = temp->next;//다음 노드로 넘어감
        }
        printf("\n");
    }
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display();

    dequeue();
    dequeue();
    display();
    
    return 0;
}
