#include <stdio.h>
#include <stdlib.h>
//이진 탐색 트리(Binary Search Tree. BST)문제
//root가 무엇인지 잘 판단해서 생각해야함.
typedef struct NodeStruct{
    int value;
    struct NodeStruct* leftChild;
    struct NodeStruct* rightChild;
} Node; //Type의 일종.
Node* root = NULL;
//Node구조체를 가리킬 수 있는 포인터.
//이 상태에서는 struct의 요소를 가지지 않음

Node* BST_insert(Node* root, int value){
    if (root == NULL){
        //아래와 같이 동적할당을 해 주면 struct의 부분?? 기능??을 사용 가능
        root = (Node*)malloc(sizeof(Node));
        root->leftChild = root->rightChild = NULL;
        root->value = value;
        return root;
    }else{
        if (root->value > value)
            root->leftChild = BST_insert(root->leftChild, value);
        else
            root->rightChild = BST_insert(root->rightChild, value);
    }
    return root;
}
//이 함수는 재귀 함수이므로 항상 맨 처음의 root를 반환.(5를 가진 노드)

Node* findMinNode(Node* root){
    Node* tmp = root;
    while (tmp->leftChild != NULL)
        tmp = tmp->leftChild;

    return tmp;
}

Node* BST_delete(Node* root, int value){
    //마지막에 남는 값은 결국 root==NULL에 해당되기에 NULL 처리가 됨.
    Node* tNode = NULL;
    if (root == NULL)
        return NULL;

    if (root->value > value)
        root->leftChild = BST_delete(root->leftChild, value);
    else if (root->value < value)
        root->rightChild = BST_delete(root->rightChild, value);
    else{
        if (root->rightChild != NULL && root->leftChild != NULL){
            // 자식 노드가 둘 다 있을 경우
            tNode = findMinNode(root->rightChild);
            root->value = tNode->value;
            root->rightChild = BST_delete(root->rightChild, tNode->value);
        }else{
            tNode = (root->leftChild == NULL) ? root->rightChild : root->leftChild;
            free(root);
            return tNode;
        }
    }
    return root;
}

Node* BST_search(Node* root, int value){
    if (root == NULL)
        return NULL;

    if (root->value == value) 
        return root;
    else if (root->value > value)
        return BST_search(root->leftChild, value);
    else
        return BST_search(root->rightChild, value);
}

void BST_print(Node* root){
    if (root == NULL)
        return;

    printf("%d ", root->value);

    BST_print(root->leftChild);
    BST_print(root->rightChild);
}

int main(){
    Node* result;//Node를 가리킬 수 있는 포인터 변수

    root = BST_insert(root, 5);// ->root = NULL->Null < -| 5 | ->Null
    root = BST_insert(root, 3);// -> 3 < -| 5 | ->Null
    root = BST_insert(root, 7);// -> 3 < -| 5 | ->7
    root = BST_insert(root, 1);// -> 3 < -| 5 | ->7 / 1 < -| 3 | ->Null
    root = BST_insert(root, 9);// -> 3 < -| 5 | ->7 / 1 < -| 3 | ->Null / Null < -| 7 | ->9
    root = BST_insert(root, 6);// -> 3 < -| 5 | ->7 / 1 < -| 3 | ->Null / 6 < -| 7 | ->9
        /*
                5 < -root
               / \
              3   7
             /   /  \
            1   5    9
        */
    root = BST_delete(root, 7);// -> 3 < -| 5 | ->7 / 1 < -| 3 | ->Null / 6 < -| 7 | ->9 | tNod : 6 < -| 7 | ->9 / Null < -| 9 | ->Null = > 6 < -| 9 | ->Null()
    //->결국... -> 3 < -| 5 | ->9 / 1 < -| 3 | ->Null / 6 < -| 9 | ->Null

    result = BST_search(root, 9);// -> 3 < -| 5 | ->9 / 1 < -| 3 | ->Null / 6 < -| 9 | ->Null | result = 6 < -| 9 | ->Null

    if (result != NULL) printf("%d \n", result->value);// ->9

    BST_print(root);//->root: 3 < -| 5 | ->7 / 1 < -| 3 | ->Null / 6 < -| 9 | ->Null 
    //결과값 출력: 5 3 1 9 3
}
