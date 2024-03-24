#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 20

typedef struct {
    int shu[MAX];
    int top;
} shu;//����һ���ܹ��������ֵĽṹ�� 

typedef struct {
    char fu[MAX];
    int top;
} fu;//����һ���ܹ�������ŵĽṹ�� 

void spush(shu *s, int x) {
    if (s->top == MAX - 1) {
        printf("��������");
        exit(0);
    } else {
        s->shu[++(s->top)] = x;
    }
}//������ѹ���Ӧ��ջ 

void fpush(fu *n, char op) {
    if (n->top == MAX - 1) {
        printf("��������");
        exit(0);
    } else {
        n->fu[++(n->top)] = op;
    }
}//������ѹ���Ӧ��ջ 

void spop(shu *s, int *num) 
{
    if (s->top == -1) {
        printf("��������");
        exit(0);
    } else {
        *num = s->shu[s->top--];
    }
}//ȡ������ջ�Ķ�Ԫ�� 

void fpop(fu *n, char *op) {
    if (n->top == -1) {
        printf("��������");
        exit(0);
    } else {
        *op = n->fu[n->top--];
    }
}//ȡ������ջ�Ķ�Ԫ�� 

int priority(char op) //�����ж��ַ����ȼ� 
{
    switch (op) 
	{
        case '+':
        case '-':
            return 1;//+-Ϊ1 
        case '*':
        case '/':
            return 2;//*/���� 
    }
    return -1;
}

int getnum(int a, int b, char op) //С�ͼ����� 
{
    switch (op) //�жϷ��� 
	{
        case '+': return a + b;
        case '-': return a - b;
        case '*':return a * b;
        case '/': if (b == 0)
			{   
				printf("��������Ϊ0��"); 
                exit(0); // ��ʾ����Ϊ0�����
            } 
			else 
			{
                return a / b;
            }
        default:printf("��������ȷ�ķ���^_^");exit(0);//�����쳣���ŵ���� 
        
    }
    return 0; 
}

void count(shu *s, fu *n) //���н�ȡ������ջ��ͷ����Ԫ���ٽ����������ջ��ת��Ϊ��׺���ʽ�ĺ��� 
{
    char op;
    int number, a, b;
    fpop(n, &op);
    spop(s, &a);
    spop(s, &b);
    number = getnum(b, a, op);
    spush(s, number);
}

int main() 
{
    int result;
    char ch[MAX];
    shu s;
    fu n;
    s.top = -1;
    n.top = -1;//��ʼ�� 
    printf("����������Ҫ����ı��ʽ��");
    scanf("%s", ch);
    while(1){
    int i=0,length=strlen(ch);//����i������ch��ÿһ���ַ� 
    while (i<length) 
	{
        if (ch[i] >= '0' && ch[i] <= '9')//���ַ�Ϊ����ʱֱ��ѹ������ջ 
		{
            spush(&s, ch[i] - '0');
            i++;
        } 
		else if (n.top == -1 || ch[i] == '(' || priority(ch[i]) > priority(n.fu[n.top])) 
		{
            fpush(&n, ch[i]);
            i++;
        } 
		else if (ch[i] == ')' && n.fu[n.top] == '(') //������������ʱ�ҷ���ջ��Ϊ������ʱ��������ȡ����������ch�������õ�����ch����ʱ���������� 
		{
            fpop(&n, &ch[i]);
            i++;
        } 
		else //���������Ҫ���м�����ջ�ĺ��Ĳ��� 
		{
            count(&s, &n);
        }
    }
    while (n.top != -1) //�������շ���ջ����ʣ����ž�Ҫ����������ȥֱ������ջջ�� 
	{
        count(&s, &n);
    }
    result = s.shu[s.top];
     //���������� 

        printf("���Ϊ��%d\n", result);
         printf("�����Ƿ������(1������0����)");
    	scanf("%d", &result);
    	if(result==0){
    		printf("�������");
    		break;
		}
	}

    return 0;
}
