#include <stdio.h>
#include <ctype.h>
typedef struct conversion
{
	char a[30];
	int top;
}stack;

void push(char, stack *s);

char pop(stack *s);

void convert(char[],char[],stack *s);

int priority(char a);

int main()
{
	char infix[30],postfix[30];
	stack s;
	s.top=-1;
	printf("\nenter the infix expression\n");
	scanf("%s",infix);
	convert(infix,postfix,&s);
	printf("\n5the postfix expression is %s\n",postfix);
	return 0;
}

void convert(char in[30], char post[30],stack *s)
{
	char opr;
	int i,j;
	for(i=0,j=0;in[i]!='\0';i++)
	{
		if(isalpha(in[i]))
		post[j++]=in[i];
		if(in[i]=='(')
		push(in[i],s);
		if(in[i]=='+'||in[i]=='*'||in[i]=='/'||in[i]=='-')
		{
			if(s->top!=-1)
			{
				opr=pop(s);
				while(priority(opr)>=priority(in[i]))
				{
					post[j++]=opr;
					opr=pop(s);
				}
				push(opr,s);
				push(in[i],s);
			}
			else
			push(in[i],s);
		}
		if(in[i]==')')
		{
			opr=pop(s);
			while(opr!='(')
			{
				post[j++]=opr;
				opr=pop(s);
			}
		}
	}
	while(s->top!=-1)
	post[j++]=pop(s);
	post[j]='\0';
}

void push(char e, stack *s)
{
    int top=s->top;
    if(top<29)
	{
		s->a[++(s->top)]=e;
	}
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

int priority(char a)
{
    if (a=='*'||a=='/')
        return 2;
    else if (a=='+'||a=='-')
        return 1;
    else
		return 0;
}
