#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef char Element;

Element data[MAX_STACK_SIZE];
int top;

Element Reverse_str[MAX_STACK_SIZE];

void error(char str[])
{
	printf("%s\n", str);
	exit(1);
}

void init_stack() { top = -1; }
int is_empty() { return top == -1; }
int is_full() { return top == MAX_STACK_SIZE - 1; }
int size() { return top + 1; }

void push(Element e)
{
	if (is_full())
		error("스택 포화 에러");
	data[++top] = e;
}

Element pop()
{
	if (is_empty())
		error("스택 공백 에러");
	return data[top--];
}

Element peek()
{
	if (is_empty())
		error("스택 공백 에러");
	return data[top];
}

void print_stack(char msg[])
{
	int i;
	printf("%s[%2d] = ", msg, size());
	for (i = 0; i < size(); i++)
		printf("%2d", data[i]);
	printf("\n");
}

Element reverse(char str[], int len)
{
	int i;

	for (i = 0; i < len; i++)
	{
		push(str[i]);
	}

	for (i = 0; i < len; i++)
	{
		Reverse_str[i] = pop();
	}

	Reverse_str[len] = NULL;

}

void main()
{
	char str[MAX_STACK_SIZE];

	printf("문자열 입력 : ");
	scanf("%s", str);

	int len = strlen(str);

	reverse(str, len);

	printf(Reverse_str);

	return 0;
}