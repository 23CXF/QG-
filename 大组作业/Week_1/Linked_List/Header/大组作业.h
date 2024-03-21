#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

// 单向链表结构体
struct Node {
    int data;
    struct Node* next;
};
typedef struct Node Node;

// 双向链表结构体
struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
};
typedef struct DNode DNode;

Node* createNode(int data);
DNode* createDNode(int data);
Node* prepend(Node* head, int data);
void append(Node** head, int data);
void appendDNode(DNode** head, int data);
void printList(Node* head);
void printDList(DNode* head);
void swapOddEven(Node* head);
Node* findMiddle(Node* head);
int hasCycle(Node* head);
Node* reverseList1(Node* head);
Node* reverseList2(Node* head);
void select();

#endif 
