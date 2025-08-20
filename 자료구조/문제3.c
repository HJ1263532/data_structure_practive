#include <stdio.h>
#include <stdlib.h>
//스텍문제. lifo임.
void push(int);
int pop();
void print_s();
typedef struct node {
	int data;//들어갈 데이터
	struct node* next;//다음 노드 가리키는 포인터
}stack;

//top은 stack형의 구조체를 가리킬 뿐인 포인터. 구조체가 아니다.
stack* top = NULL;

int main() {
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	print_s();

	pop();
	pop();
	print_s();
}

void push(int data) {
	//동적 할당.
	stack* new_node = (stack*)malloc(sizeof(stack));
	/*stack 타입의 포인터 mew_node선언.
	new_node는 나중에 stack 구조체가 저장될 메모리 주소를 가르키게 될 포인터
	malloc이 반환하는 void*를 stack*타입으로 캐스팅 해주는 부분.(생략 가능)
	*/
	if (new_node == NULL) {
		printf("stack is full!");
		exit(1);//이거 무슨 코드임??
	}
	new_node->data = data;
	new_node->next = top;
	top = new_node;//top은 마지막에 들어온 데이터를 가리킴(맨 앞 노드)
}
int pop() {
	stack* del;
	int value;
	if (top == NULL) {
		printf("stack is empty!");
		exit(1);
	}
	value = top->data;
	del = top;
	top = top->next;//-> 1개만 있지 않는 이상 항상 null이 아님
	free(del);
	return value;
}
void print_s() {
	stack* i;
	stack* count = top;
	i = count;//i=top;
	while (i != NULL) {//i가 움직임. top 변화 없음
		printf("%d \n", i->data);
		i = count->next;
		count = count->next;//이거 count 왜 만들어줌??
	}
	printf("\n");
}
