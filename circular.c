#include <stdio.h>
#define MAXSIZE 10

int queue[MAXSIZE];
int front=-1,rear=-1;

int isFull()
{
	return (rear==MAXSIZE-1 && front==0) || ( front==rear+1);
}

int isEmpty()
{//returns 1 if stack is full else -1
		return (rear==-1 && front==-1);
}

void Display()
{	int i;
	if(!isEmpty())
	{
	printf("The Elemnet of Queue are \n");
	for(i=front;i!=rear;i=(i+1)%MAXSIZE)
	{
		printf("%d\t",queue[i]);
	}
	}
	else
	{
		printf("Queue is Empty");
	} 
}

void Insert(int d)
{
	if(isFull())
	{
		printf("queue is full");
		return;
	}
	else
	{	rear=(rear+1)%MAXSIZE;
		queue[rear]=d;
			if(front==-1)
				front++;
	}
	printf("Element successfully inserted");
}

void Delete()
{ int d;
	if(isEmpty())
	{
		printf("Queue is empty");
		return;
	}
	else
	{
		d=queue[front];
			if(front==rear)
			{
				front=-1;
				rear=-1;
			}
			else
			{
				front=(front+1)%MAXSIZE;
			}
			
	}	
}

int main()
{
    int ch,e;
    do
    {
        printf("\n\tMENU\n1.DISPLAY\n2.DELETE\n3.INSERT\n4.EXIT\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:Display();
                   break;
            case 2:Delete();
                   break;
            case 3:printf("\nEnter the element to be inserted:");
                   scanf("%d",&e);
                   Insert(e);
                   break;
            case 4:return 0;
        }
    }while(1);
    return 0;
}
