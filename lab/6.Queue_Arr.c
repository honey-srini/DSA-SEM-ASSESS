#include<stdio.h>   
#include<stdlib.h>  
#define maxsize 5  
void insert();  
void delete();  
void display();  
int front = -1, rear = -1;  
int queue[maxsize];  
void main ()  
{  
    int choice;   
    while(choice != 6)   
    {   
        printf("\n Queue Operations using Array\n");
        printf("1:Inserting element to queue(enqueue)\n");
        printf("2:Deleting element from queue(dequeue)\n");
        printf("3:Display all the elements of queue \n");
        printf("4.Display front element:\n");
        printf("5.Enter the element to be searched in the queue:\n");
        printf("6:Exit \n");
        
        printf("\nEnter your choice :");  
        scanf("%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            insert();  
            break;  
            case 2:  
            delete();  
            break;  
            case 3:  
            display();  
            break; 
            case 4:  
            frontval();  
            break; 
            case 5:  
            search();  
            break;   
            case 6:  
            exit(0);  
            break;  
            default:   
            printf("\nEnter a valid choice!!!\n");  
        }  
    }  
}  
void insert()  
{  
    int item;  
    printf("\nEnter the element:");  
    scanf("\n%d",&item);      
    if(rear == maxsize-1)  
    {  
        printf("\nOVERFLOW\n");  
        return;  
    }  
    if(front == -1 && rear == -1)  
    {  
        front = 0;  
        rear = 0;  
    }  
    else   
    {  
        rear = rear+1;  
    }  
    queue[rear] = item;  
    printf("\nValue inserted into queue \n");  
      
}  
void delete()  
{  
    int item;   
    if (front == -1 || front > rear)  
    {  
        printf("\nUNDERFLOW\n");  
        return;  
              
    }  
    else  
    {  
        item = queue[front];  
        if(front == rear)  
        {  
            front = -1;  
            rear = -1 ;  
        }  
        else   
        {  
            front = front + 1;  
        }  
        printf("\nvalue deleted from the queue \n");  
    }  
      
      
}  
      
void display()  
{  
    int i;  
    if(rear == -1)  
    {  
        printf("\nEmpty queue\n");  
    }  
    else  
    {   printf("\nElements in the queue\n");  
        for(i=front;i<=rear;i++)  
        {  
            printf("%d\n",queue[i]);  
        }     
    }  
}  

void frontval(){
    if (front==-1)
    {
        printf("\nQueue is empty!");
    }
    else
    {
        printf("\nThe front element is %d \n",queue[front]);
    }
}

void search()
{
	int n,i;
	if(rear==-1)
	{
		printf("\nEmpty queue");
	}
	else
	{
		printf("Enter the element to be searched :");
		scanf("%d",&n);
		
		for(i=0;i<=rear;i++)
		{
			if(queue[i]==n)
			{
				printf("%d element is in the location %d \n",queue[i],i );
				break;
			}
			else if(i==rear)
			{
				printf("element not found");
			}
			
		}
		
	}
}