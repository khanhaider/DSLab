
#include <stdio.h>
#define MAXSIZE 10
int Queue[MAXSIZE];
int front=-1,rear=-1;



int isFull()
{
	return (rear==(MAXSIZE-1));
	
}

int isEmpty()
{
	return (rear==-1 && front==-1);
}

void display()

{  
	int i;
	  printf("The Element of Queue are:  ");
	for(i=front;i<=rear;i++)
	{
		 printf("%d\t",Queue[i]);
	 }
}

void insert(int d)
{
	if(isFull())
	  {
		  printf("QUEUE IS FULL");
		  return;
	  }
	  
	 else
	 {
		rear++;
		Queue[rear]=d;
		     if(front==-1)
		     {
				  front++;
			 }
	   
			printf("Element Successful Inserted");
		}
 }
 
void delete()
{ 
	int d;
	if(isEmpty())
		{
			printf("QUEUE IS EMPTY");
		}
	
	else
	{
		d=Queue[front];
		 if(front==rear)
		   {
			   front=-1;
			   rear=-1;
		   }
		   
		  else
		{
			front++;
		}
		
	}
}
	
	
	
	
	
	
	
	

int main()
{
    int ch,e;
    do
    {
        printf("\n\tMENU\n1.Display\n2.Delete\n3.Insert\n4.EXIT\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:display();
                   break;
            case 2:delete();
                   break;
            case 3:printf("\nenter the element to be Inserted:");
                   scanf("%d",&e);
                   insert(e);
                   break;
            case 4:return 0;
        }
    }while(1);
    return 0;
}
