
#include <stdio.h>
#include <ctype.h>

typedef struct conversion
{
	char a[30];
	int top;
}stack;

void push(char, stack *s);

char pop(stack *s);

void checkContinuity(char exp[30]);

int isMatching(char left, char right);

int main()
{
	char exp[30];
	printf("\nEnter the expression containing paranthesis:\n");
	scanf("%s",exp);
	checkBalance(exp);
	return 0;
}

char pop(stack *s)
{
    int top=s->top;
    int d;
    if(top!=-1)
    {
		d=s->a[top];
        s->top=s->top-1;
		return d;
    }
}
void push(char e, stack *s)
{
    int top=s->top;
    if(top<29)
	{
		s->a[++(s->top)]=e;
	}
}

int isMatching(char left, char right)
{
	switch(left)
	{
		case '(': 
			if(right==')')
				return 1;
			else
				return 0;	
		case '{': 
			if(right=='}')
				return 1;
			else
				return 0;	
		case '[': 
			if(right==']')
				return 1;
			else
				return 0;	
	}
	return 0;
}

void checkBalance(char exp[30])
{
	int i;
	char e,left;
	stack s;
	s.top=-1;
	for(i=0;exp[i]!='\0';i++)
	{
		e=exp[i];
		if(e=='('||e=='{'||e=='[')
			push(e,&s);
		else
		{
			if(s.top==-1)
			{
				printf("Expression is invalid\n");
				return;
			}
			else{
				left=pop(&s);
				if(isMatching(left,e))
					continue;
				else
				{
					printf("Expression is invalid\n");
					return;
				}
			}
		}
	}
	if(s.top!=-1)
	printf("Expression is invalid\n");
	else
	printf("Expression is valid\n");
}
