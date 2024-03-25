#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    void *data;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} Queue;

void initQueue(Queue *queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

void enqueue(Queue *queue, void *data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

void *dequeue(Queue *queue) {
    if (queue->front == NULL) {
        fprintf(stderr, "Queue is empty.\n");
        exit(EXIT_FAILURE);
    }

    Node *temp = queue->front;
    void *data = temp->data;

    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    return data;
}

void destroyQueue(Queue *queue) {
    Node *current = queue->front;
    Node *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    queue->front = NULL;
    queue->rear = NULL;
}

int isEmpty(Queue* queue) {
    return (queue->front == NULL);
}

void printQueue(Queue* queue, void (*printElement)(void*)) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    Node* tempNode = queue->front;
    printf("Queue: ");

    while (tempNode != NULL) {
        printElement(tempNode->data);
        tempNode = tempNode->next;
    }

    printf("\n");
}

void printInt(void* data) {
    int* num = (int*)data;
    printf("%d -> ", *num);
}

void printDouble(void* data) {
    double* num = (double*)data;
    printf("%f -> ", *num);
}

void printChar(void* data) {
    char* c = (char*)data;
    printf("%c -> ", *c);
}

void menu(){
    printf("Please input your choice:\n");
    printf("1: Integer\n");
    printf("2: Char\n");
    printf("3: Double\n");
    printf("4: Exit\n");
}

int main() {
    int flag;
    Queue intQueue, charQueue, doubleQueue;
    initQueue(&intQueue);
    initQueue(&charQueue);
    initQueue(&doubleQueue);

    menu();
    scanf("%d", &flag);
    while(flag != 4){
        switch(flag){
            case 1: {
                int num;
                printf("Enter an integer: (if input 0 will break and printf the queue)");
                scanf("%d", &num);
                while(num != 0){
                    int *ptr = (int *)malloc(sizeof(int));
                    *ptr = num;
                    enqueue(&intQueue, ptr);
                    scanf("%d", &num);
                }
                printf("Integers in the queue: ");
                printQueue(&intQueue, printInt);
                break;
            }
            case 2: {
                char c;
                printf("Enter a character: (if input '0' will break and printf the queue)");
                scanf(" %c", &c);
                while(c != '0'){
                    char *ptr = (char *)malloc(sizeof(char));
                    *ptr = c;
                    enqueue(&charQueue, ptr);
                    scanf(" %c", &c);
                }
                printf("Characters in the queue: ");
                printQueue(&charQueue, printChar);
                break;
            }
            case 3: {
                double d;
                printf("Enter a double:(if input 0 will break and printf the queue) ");
                scanf("%lf", &d);
                while(d != 0.0){
                    double *ptr = (double *)malloc(sizeof(double));
                    *ptr = d;
                    enqueue(&doubleQueue, ptr);
                    scanf("%lf", &d);
                }
                printf("Doubles in the queue: ");
                printQueue(&doubleQueue, printDouble);
                break;
            }
            default:
                destroyQueue(&intQueue);
                destroyQueue(&charQueue);
                destroyQueue(&doubleQueue);
                return 0;
        }

        menu();
        scanf("%d", &flag);
    }

    destroyQueue(&intQueue);
    destroyQueue(&charQueue);
    destroyQueue(&doubleQueue);

    return 0;
}

