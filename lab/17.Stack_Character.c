#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#define size 5
int top=-1;
char arr[size];

void push();
void pop();
void occur();
void show();

void main()
{
    int choice;
    while(choice!=5)
    {
        printf("\n");
        printf("\nStack Operations");
        printf("\n1.Push the element (Only Characters alowed!!!)");
        printf("\n2.Pop the element");
        printf("\n3.Find no of occurence");
        printf("\n4.Show");
        printf("\n5.Exit");
        printf("\nEnter the choice :");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            push();
            break;

            case 2:
            pop();
            break;

            case 3:
            occur();
            break;

            case 4:
            show();
            break;

            case 5:
            exit(0);

            default:
            printf("\nTnvalid Choice !!!");

        }
    }
}

void push()
{
	char c;
	
	if(top==size-1)
	{
		printf("\nOverflow!!");
	}
	else
	{
		printf("\nEnter element to be inserted to the stack:");
		scanf("%s",&c);

		if (isalpha(c) == 0)
   		{
       	printf("Only Characters are allowed");
   		}
   		else{
		if (c ==arr[top]){
			printf("Cant push the element , the previos element is same(repitaion not allowed)");
		}
		else{
		top=top+1;
		arr[top]=c;
		}
       	
   		}

		
	}
}

void pop()
{
	if(top==-1)
	{
		printf("\nUnderflow!!");
	}
	else
	{
		printf("\nPopped element:  %c",arr[top]);
		top=top-1;
	}
}

void occur(){
    int i,count=0;
    char find;
	if(top==-1)
	{
		printf("\nUnderflow!!");
	}
	else
	{
		printf("Enter the element to find the number of occurance :");
		scanf("%s",&find);
		
		for(i=0;i<=top;i++)
		{
			if(arr[i]==find)
			{
                count = count+1;
				
			}
			else if(i==top)
			{
				printf("element not found");
			}
			
		}
        printf("\nThe number of occurance of %c is %d",find,count);
		
	}
}

void show(){

    if(top==-1)
	{
		printf("\nUnderflow!!");
	}
	else
	{
		printf("\nElements present in the stack: \n");
		for(int i=top;i>=0;--i){

			printf("%c\n",arr[i]);
		}
	}
}

