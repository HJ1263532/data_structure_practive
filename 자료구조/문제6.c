#include <stdio.h>
#include <stdlib.h>
//깊이 우선 탐색
#define NODE 10
int adj[NODE][NODE];
int vsize;
char vdata[NODE];
int visited[NODE];

void init() {//adj배열 초기화
    vsize = 0;
    for (int i = 0; i < NODE; i++)
        for (int j = 0; j < NODE; j++)
            adj[i][j] = 0;
}

int is_full() {
    //가득차지 않았다면 true
    if (vsize > NODE) return 1;
    else return 0;
}

void insert_vertex(char name) {
    if (is_full() == 1) {//그냥 is_full()하면 문제 생김?-> x
        printf("Error: 정점 개수 초과\n");
    }
    else//가득 차있는 상태가 아니라면 vdata 배열에 name추가하고 index++
        vdata[vsize++] = name;
}

void insert_edge(int u, int v, int value) {
    adj[u][v] = value;//1행 목록=1열 목록.u행 v열
    adj[v][u] = value;//이거 뭐하는 행렬?
}

void DFS_search(int n) {//탐색코드
    visited[n] = 1;//방문여부. 근데 무슨 배열임??
    printf("%c ", vdata[n]);//name저장한 arr
    for (int i = 0; i < vsize; i++)//index 최대 개수
        if ((adj[n][i] != 0) && (visited[i] == 0))
            DFS_search(i);
}
//8까지 vsize 존재
int main(void) {
    init();//초기화. vsize는 0
    for (int i = 0; i < 8; i++)//8칸
        insert_vertex('A' + i);//ABCDEFGH
    //0>A,1>B...7>H, 8/9/=null??
    insert_edge(0, 1, 1);
    insert_edge(0, 2, 1);
    insert_edge(1, 3, 1);
    insert_edge(2, 3, 1);
    insert_edge(2, 4, 1);
    insert_edge(3, 5, 1);
    insert_edge(4, 6, 1);
    insert_edge(4, 7, 1);
    insert_edge(6, 7, 1);

    DFS_search(0);
    /*
       |  0  1  2  3  4  5  6  7  8  9
       -------------------------------
    0  |  0  1  1  0  0  0  0  0  0  0
    1  |  1  0  0  1  0  0  0  0  0  0
    2  |  1  0  0  1  1  0  0  0  0  0
    3  |  0  1  1  0  0  1  0  0  0  0
    4  |  0  0  1  0  0  0  1  1  0  0
    5  |  0  0  0  1  0  0  0  0  0  0
    6  |  0  0  0  0  1  0  0  1  0  0
    7  |  0  0  0  0  1  0  1  0  0  0
    8  |  0  0  0  0  0  0  0  0  0  0
    9  |  0  0  0  0  0  0  0  0  0  0

	            adj[][]
    vdata[7]=[A, B, C, D, E, F, G, H]
    visited[11111OOOOO]
    n= 01324673
    ABDCEGH
    -> 재귀 함수의 성질을 봤을 때 if문에 해당하는 부분이 없으면 return하며 이전 부분으로 돌아감.
    돌아가서 조건에 부합하는 것이 있는지 확인.
    ->F
    */

    printf("\n");

    return 0;

}
