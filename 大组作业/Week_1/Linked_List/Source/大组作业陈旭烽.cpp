#include <stdio.h>
#include <stdlib.h>

// ��������ṹ��
struct Node {
    int data;
    struct Node* next;
};
typedef struct Node Node;

// ˫������ṹ��
struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
};
typedef struct DNode DNode;

// ��������ڵ�
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

// ����˫��ڵ�
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

// ��ͷ�����뵥��ڵ�
Node* prepend(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// ��β�����뵥��ڵ�
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

// ��β������˫��ڵ�
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

// ��ӡ��������
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// ��ӡ˫������
void printDList(DNode* head) {
    DNode* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// �����������ż����
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

// Ѱ���м�ڵ�
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

// �ж������Ƿ�ɻ�
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

// ��ת�����ǵݹ飩
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

// ��ת�����ݹ飩
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
    printf("             ���ѡ��              \n");
    printf(" 1������/�½�������  2������/�½�˫������    \n");
    printf(" 3����ӡ��������     4����ӡ˫������    \n");
    printf(" 5��Ѱ���м�ڵ㡣     6���ж��Ƿ�ɻ�    \n");
    printf(" 7����ת�����ݹ飩�� 8����ת�����ǵݹ飩\n");
    printf(" 9����ż��ת         \n");
    printf(" 0���˳�  \n");
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
			    //���ÿպ󴴽����ع� 
                head1 = NULL;
                printf("��ѡ������ͷ������ķ�ʽ����������β����(1��ʾ��ͷ��������������Ϊβ��)\n");
                int sign;
                scanf("%d", &sign);
                printf("�����������ֵ������0��ʾ�������룩\n");
                int temp;
                scanf("%d", &temp);
                //��ͷ��ķ�ʽ���д��� 
                if (sign == 1) {
                    while (temp != 0) {
                        head1 = prepend(head1, temp);
                        printf("��������룺");
                        scanf("%d", &temp);
                    }
                } //��β��ķ�ʽ���д��� 
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
                printf("�����������ֵ������0��ʾ�������룩\n");
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
                    printf("�м�ڵ��ֵΪ��%d\n", temp1->data);
                }
                break;
            case 6:
                if (head1 != NULL) {
                    if (hasCycle(head1)) {
                        printf("�����д��ڻ�\n");
                    } else {
                        printf("�����в����ڻ�\n");
                    }
                }
                break;
            case 7:
                head1 = reverseList2(head1);
                printf("��ת�������\n");
                printList(head1);
                break;
            case 8:
                head1 = reverseList1(head1);
                printf("��ת�������\n");
                printList(head1);
                break;
            case 9:
                if (head1 != NULL) {
                    swapOddEven(head1);
                    printf("��ż�����������\n");
                    printList(head1);
                }
                break;
            case 0:
                printf("�������˳�\n");
                break;
            default:
                printf("��Чѡ��������ѡ��\n");
        }
    }

    return 0;
}

