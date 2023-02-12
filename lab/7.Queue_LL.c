#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;
void ins_que()
{
    int num;
    printf("Enter the element to be inserted:");
    scanf("%d",&num);
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=NULL;
    if(front==NULL && rear==NULL)
    {
        front=rear=newnode;
        printf("First value inserted\n");
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
        printf("Value is inserted\n");
    }
}
void del_que()
{
    struct node* temp=front;
    if(front==NULL)
    {
        printf("Queue underflow\n");
    }
    else
    { 
        printf("Deleted Element:%d \n",front->data);
        front=front->next;
        free(temp);
    }
}
void search_que()
{
     int search_no,index=0;
     struct  node*temp=front;
     printf("Enter the element to be searched:");
     scanf("%d",&search_no);
     if(front==NULL)
     {
        printf("Queue underflow\n");
     }
     else
     {
        while(temp!=NULL)
        {
            index+=1;
            if(temp->data==search_no)
            {
            printf("Element found at index:%d",index);
            }
            temp=temp->next;
        }
        
    
     }
     
     
}
void display()
{
    struct node* temp;
    temp=front;
    if(front==NULL)
    {
        printf("Queue underflow\n");
    }
    else
    {
        
        printf("Elements present:\n");
        while(temp->next!=NULL)
        {
            printf("%d-->",temp->data);
            temp=temp->next;
        }
        printf("%d-->NULL\n",temp->data);
        
    }
    
}
void peek()
{
    if(front==NULL)
    {
        printf("Queue underflow\n");
    }
    else
    {
        printf("Top element:%d \n",front->data);
    }
}
int main()
{
    int choice;
    
    while(1)
    {
        printf("\n Queue Operations using Linked List\n");
        printf("\n1:Inserting element to queue(enqueue)\n");
        printf("2:Deleting element from queue(dequeue)\n");
        printf("3.Enter the element to be searched in the queue:\n");
        printf("4:Display all the elements of queue \n");
        printf("5.Display front element(peek):\n");
    
        printf("6:Exit \n");
        printf("\nEnter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            ins_que();
            break;
            case 2:
            del_que();
            break;
            case 3:
            search_que();
            break;
            case 4:
            display();
            break;
            case 5:
            peek();
            break;
            case 6:
            exit(0);
            break;
            default:
            printf("Invalid choice\n");
        }

    }
    return 0;
}