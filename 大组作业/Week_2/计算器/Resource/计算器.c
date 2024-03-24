#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 20

typedef struct {
    int shu[MAX];
    int top;
} shu;//定义一个能够储存数字的结构体 

typedef struct {
    char fu[MAX];
    int top;
} fu;//定义一个能够储存符号的结构体 

void spush(shu *s, int x) {
    if (s->top == MAX - 1) {
        printf("输入有误");
        exit(0);
    } else {
        s->shu[++(s->top)] = x;
    }
}//将数字压入对应的栈 

void fpush(fu *n, char op) {
    if (n->top == MAX - 1) {
        printf("输入有误");
        exit(0);
    } else {
        n->fu[++(n->top)] = op;
    }
}//将符号压入对应的栈 

void spop(shu *s, int *num) 
{
    if (s->top == -1) {
        printf("输入有误");
        exit(0);
    } else {
        *num = s->shu[s->top--];
    }
}//取出数字栈的顶元素 

void fpop(fu *n, char *op) {
    if (n->top == -1) {
        printf("输入有误");
        exit(0);
    } else {
        *op = n->fu[n->top--];
    }
}//取出符号栈的顶元素 

int priority(char op) //用于判断字符优先级 
{
    switch (op) 
	{
        case '+':
        case '-':
            return 1;//+-为1 
        case '*':
        case '/':
            return 2;//*/优先 
    }
    return -1;
}

int getnum(int a, int b, char op) //小型计算器 
{
    switch (op) //判断符号 
	{
        case '+': return a + b;
        case '-': return a - b;
        case '*':return a * b;
        case '/': if (b == 0)
			{   
				printf("除数不能为0！"); 
                exit(0); // 表示除数为0的情况
            } 
			else 
			{
                return a / b;
            }
        default:printf("请输入正确的符号^_^");exit(0);//出现异常符号的情况 
        
    }
    return 0; 
}

void count(shu *s, fu *n) //进行将取出数字栈的头两个元素再进行运算后入栈是转化为后缀表达式的核心 
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
    n.top = -1;//初始化 
    printf("请输入您想要计算的表达式：");
    scanf("%s", ch);
    while(1){
    int i=0,length=strlen(ch);//利用i来检索ch的每一个字符 
    while (i<length) 
	{
        if (ch[i] >= '0' && ch[i] <= '9')//当字符为数字时直接压入数字栈 
		{
            spush(&s, ch[i] - '0');
            i++;
        } 
		else if (n.top == -1 || ch[i] == '(' || priority(ch[i]) > priority(n.fu[n.top])) 
		{
            fpush(&n, ch[i]);
            i++;
        } 
		else if (ch[i] == ')' && n.fu[n.top] == '(') //当遇到右括号时且符号栈顶为左括号时将左括号取出，但由于ch不会再用到就用ch来临时储存左括号 
		{
            fpop(&n, &ch[i]);
            i++;
        } 
		else //其他情况均要进行计算入栈的核心操作 
		{
            count(&s, &n);
        }
    }
    while (n.top != -1) //可能最终符号栈里有剩余符号就要继续操作下去直到符号栈栈空 
	{
        count(&s, &n);
    }
    result = s.shu[s.top];
     //最终输出结果 

        printf("结果为：%d\n", result);
         printf("请问是否继续：(1继续，0结束)");
    	scanf("%d", &result);
    	if(result==0){
    		printf("程序结束");
    		break;
		}
	}

    return 0;
}
