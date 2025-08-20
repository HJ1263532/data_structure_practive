#include <stdio.h>
#include <stdlib.h>
//넓이 우선 탐색. 아래 표 참고
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 20

int adj_matrix[MAX_VERTICES + 1][MAX_VERTICES + 1];
int visited[MAX_VERTICES + 1];

void graph_init(){//adj_matrix초기화
    int vi, vo;
    for (vi = 0; vi < MAX_VERTICES; vi++) {
        for (vo = 0; vo < MAX_VERTICES; vo++) {
            adj_matrix[vi][vo] = 0;
        }
        visited[vi] = 0;
    }
}

void insert_edge(int u, int v){
    // 간선 정보 u->v
    adj_matrix[u][v] = 1;
}

// 간단 queue
typedef int element;//??
int front, rear;
element queue[MAX_VERTICES + 2];

void init(){//front,rear 설정
    front = rear = 0;
}

int is_empty(){
    //queue가 비어있으면 1, 안 비어있으면 0을 리턴함.
    return (front == rear);
}

void enqueue(element item){
    rear++;
    queue[rear] = item;
}

element dequeue(){
    front++;
    return queue[front];
}

void bfs_list(int v){
    int w;
    init();
    visited[v] = TRUE;//1
    printf("%d ", v);
    enqueue(v);

    while (!is_empty()) {//front와 rear이 같지 않을 때를 말함
        v = dequeue();//front=9 v=3
        for (w = 0; w < MAX_VERTICES; w++) {
            if (adj_matrix[v][w] == 1 && !visited[w]) {
                visited[w] = TRUE;
                printf("%d ", w);
                enqueue(w);//rear=10
            }
        }
    }
}

int main()
{
    int i;

    graph_init();

    insert_edge(1, 9);//1행9열은 1
    insert_edge(1, 5);
    insert_edge(1, 2);
    insert_edge(2, 3);
    insert_edge(3, 4);
    insert_edge(5, 8);
    insert_edge(5, 6);
    insert_edge(6, 7);
    insert_edge(9, 10);
    /*
          0  1  2  3  4  5  6  7  8  9  10
    ---------------------------------------
    0 |   0  0  0  0  0  0  0  0  0  0  0
    1 |   0  0  1  0  0  1  0  0  0  1  0
    2 |   0  0  0  1  0  0  0  0  0  0  0
    3 |   0  0  0  0  1  0  0  0  0  0  0
    4 |   0  0  0  0  0  0  0  0  0  0  0
    5 |   0  0  0  0  0  0  1  0  1  0  0
    6 |   0  0  0  0  0  0  0  1  0  0  0
    7 |   0  0  0  0  0  0  0  0  0  0  0
    8 |   0  0  0  0  0  0  0  0  0  0  0
    9 |   0  0  0  0  0  0  0  0  0  0  1
    10|   0  0  0  0  0  0  0  0  0  0  0

    해당 문제의 키는 front 값에 맟추어 dequeue에서 return받는 값을 v로 지정하는 것
    v=1->2->5->9->3->6->8->10->4->7
    queue=[null, 1, 2, 5, 9, 3, 6, 8, 10, 4, 7 ]
    w=2 5 9 3 6 8 10 4 7
    결과 : 1 2 5 9 3 6 8 10 4 7
    */

    bfs_list(1);
}
