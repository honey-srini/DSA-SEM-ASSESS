#include<stdio.h>

#include<stdlib.h>
 
#define Size 4 
 
int Top=-1, arr[Size];
void Push();
void Pop();
void isempty();
void top();
void show();
void search();
 
int main()
{
	int choice;
	
	while(1)	
	{
        printf("\n");
		printf("\nSTACK OPERATIONS :");
		printf("\n1.Push the element");
        printf("\n2.Pop the element");
        printf("\n3.Check the stack is empty or not");
        printf("\n4.Top element");
        printf("\n5.Show");
		printf("\n6.Search");
        printf("\n7.Exit");
		printf("\n\nEnter the choice:");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1: 
            Push();
			break;

			case 2: 
            Pop();
			break;

			case 3:
            isempty();
			break;

            case 4:
            top();
            break;

            case 5:
            show();
            break;

			case 6:
            search();
            break;

			case 7: 
            exit(0);
			
			default:
            printf("\nInvalid choice!!");
		}
	}
}
 
void Push()
{
	int x;
	
	if(Top==Size-1)
	{
		printf("\nOverflow!!");
	}
	else
	{
		printf("\nEnter element to be inserted to the stack:");
		scanf("%d",&x);
		Top=Top+1;
		arr[Top]=x;
	}
}
 
void Pop()
{
	if(Top==-1)
	{
		printf("\nUnderflow!!");
	}
	else
	{
		printf("\nPopped element:  %d",arr[Top]);
		Top=Top-1;
	}
}

void isempty()
{
    if(Top==-1)
	{
		printf("\nThe Stack is Empty\n");
	}

    else
    {
        printf("\nThe stack is Not Empty\n");
    }

}
 
void top()
{
    printf("\nThe top of the Stack is :%d",arr[Top]);

}

void show()
{
	
	if(Top==-1)
	{
		printf("\nUnderflow!!");
	}
	else
	{
		printf("\nElements present in the stack: \n");
		for(int i=Top;i>=0;--i)
			printf("%d\n",arr[i]);
	}
}

void search()
{
	int n,i;
	if(Top==-1)
	{
		printf("\nUnderflow!!");
	}
	else
	{
		printf("Enter the element to be searched :");
		scanf("%d",&n);
		
		for(i=0;i<=Top;i++)
		{
			if(arr[i]==n)
			{
				printf("%d element is in the location %d ",arr[i],i );
				break;
			}
			else if(i==Top)
			{
				printf("element not found");
			}
			
		}
		
	}
}