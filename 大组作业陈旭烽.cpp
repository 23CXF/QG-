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

// 创建单向节点
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 创建双向节点
DNode* createDNode(int data) {
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// 在头部插入单向节点
Node* prepend(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// 在尾部插入单向节点
void append(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// 在尾部插入双向节点
void appendDNode(DNode** head, int data) {
    DNode* newNode = createDNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        DNode* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

// 打印单向链表
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// 打印双向链表
void printDList(DNode* head) {
    DNode* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// 单向链表的奇偶交换
void swapOddEven(Node* head) {
    Node* odd = head;
    Node* even = head->next;

    while (even && even->next) {
        int temp = odd->data;
        odd->data = even->data;
        even->data = temp;

        odd = odd->next->next;
        even = even->next->next;
    }
}

// 寻找中间节点
Node* findMiddle(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// 判断链表是否成环
int hasCycle(Node* head) {
    if (head == NULL || head->next == NULL) {
        return 0;
    }
    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return 1;
        }
    }
    return 0;
}

// 反转链表（非递归）
Node* reverseList1(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// 反转链表（递归）
Node* reverseList2(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* reversed = reverseList2(head->next);
    head->next->next = head;
    head->next = NULL;
    return reversed;
}

void select() {
    printf("*******************************************\n");
    printf("             请君选择：              \n");
    printf(" 1：创建/新建单链表。  2：创建/新建双向链表    \n");
    printf(" 3：打印单向链表。     4：打印双向链表    \n");
    printf(" 5：寻找中间节点。     6：判断是否成环    \n");
    printf(" 7：反转链表（递归）。 8：反转链表（非递归）\n");
    printf(" 9：奇偶反转         \n");
    printf(" 0：退出  \n");
    printf("*******************************************\n");
}

int main() {
    Node* head1 = NULL;
    DNode* head2 = NULL;
    int flag = -1;

    while (flag != 0) {
        select();
        scanf("%d", &flag);

        switch (flag) {
            case 1:{
			    //先置空后创建或重构 
                head1 = NULL;
                printf("请选择是在头部插入的方式创建还是在尾部：(1表示在头部，其他数字则为尾部)\n");
                int sign;
                scanf("%d", &sign);
                printf("请输入链表的值（输入0表示结束输入）\n");
                int temp;
                scanf("%d", &temp);
                //以头插的方式进行创建 
                if (sign == 1) {
                    while (temp != 0) {
                        head1 = prepend(head1, temp);
                        printf("请继续输入：");
                        scanf("%d", &temp);
                    }
                } //以尾插的方式进行创建 
				else {
                    while (temp != 0) {
                        append(&head1, temp);
                        scanf("%d", &temp);
                    }
                }
            }
                break;
            case 2:{
                head2 = NULL;
                printf("请输入链表的值（输入0表示结束输入）\n");
                int temp1=0;
                scanf("%d", &temp1);
                while (temp1 != 0) {
                    appendDNode(&head2, temp1);
                    scanf("%d", &temp1);
                }
                break;
            }
            case 3:{
                printList(head1);
                break;
            }
            case 4:
                printDList(head2);
                break;
            case 5:
                if (head1 != NULL) {
                    Node* temp1 = findMiddle(head1);
                    printf("中间节点的值为：%d\n", temp1->data);
                }
                break;
            case 6:
                if (head1 != NULL) {
                    if (hasCycle(head1)) {
                        printf("链表中存在环\n");
                    } else {
                        printf("链表中不存在环\n");
                    }
                }
                break;
            case 7:
                head1 = reverseList2(head1);
                printf("反转后的链表：\n");
                printList(head1);
                break;
            case 8:
                head1 = reverseList1(head1);
                printf("反转后的链表：\n");
                printList(head1);
                break;
            case 9:
                if (head1 != NULL) {
                    swapOddEven(head1);
                    printf("奇偶交换后的链表：\n");
                    printList(head1);
                }
                break;
            case 0:
                printf("程序已退出\n");
                break;
            default:
                printf("无效选择，请重新选择\n");
        }
    }

    return 0;
}

