#include <stdio.h>
#define MAXSIZE 10
int stack[MAXSIZE], top=-1;

int isfull()
{ //returns 1 if stack is full else -1
	if(top==(MAXSIZE-1))
		return 1;
	else
		return-1;
}

int isempty()
{//returns 1 if stack is full else -1
	if (top==-1)
		return 1;
	else
		return -1;
}

int peek()
{//returns the element at the top of the stack
	return stack[top];
}

int push(int e)
{  //inserts an element in the stack
	if(isfull()==1)
		printf("STACK OVERFLOW\n");
	else
	{
		stack[++top]=e;
		printf("element successfully inserted\n");
	}
}

void pop()
{  //deletes an element from the stack
	if(isempty()==1)
		printf("STACK UNDERFLOW\n");
	else
	{
		int d=stack[top--];
		printf("%d successfully deleted\n",d);
	}
}

int main()
{
    int ch,e;
    do
    {
        printf("\n\tMENU\n1.PEEK\n2.POP\n3.PUSH\n4.EXIT\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("the topmost element is:%d",peek());
                   break;
            case 2:pop();
                   break;
            case 3:printf("\nenter the element to be pushed:");
                   scanf("%d",&e);
                   push(e);
                   break;
            case 4:return 0;
        }
    }while(1);
    return 0;
}
