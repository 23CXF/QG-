#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 20

typedef struct {
    int shu[MAX];
    int top;
} shu;

typedef struct {
    char fu[MAX];
    int top;
} fu;

void spush(shu *s, int x);

void fpush(fu *n, char op);

void spop(shu *s, int *num);

void fpop(fu *n, char *op);

int priority(char op);

int getnum(int a, int b, char op);

void count(shu *s, fu *n);

int main();

