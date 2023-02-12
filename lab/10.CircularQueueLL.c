#include<stdio.h>
#include<stdlib.h>

typedef struct queue {
    struct queue *prev;
    int data;
    struct queue *next;
}queue;

queue *front = NULL;
queue *rear = NULL;

void enqueue(int val){
    queue *newnode;
    newnode = (queue*) malloc(sizeof(queue));
    newnode->prev = NULL;
    newnode->data = val;
    newnode->next = NULL;
    if(front == NULL && rear == NULL){
        front = newnode;
        rear = newnode;
    }
    else{
        newnode->prev = rear;
        rear->next = newnode;
        rear = newnode;
        
    }
}

void dequeue(){
    if(front == NULL && rear == NULL){
        printf("No value to dequeue");
    }
    else{
    queue *temp = front;
    front = front->next;
    front->prev = rear;
    free(temp);
    }
}

void display(){
    queue *temp = front;
    while(temp!= NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

void peek(){
    printf("Front : %d", front->data);
}

void search(){
    if (front == NULL){
        printf("There's no queue to search");
    }
    else{
    queue *temp = front;
    int find,pos = 1, flag = 0 ;
    printf("Value to search : ");
    scanf("%d", &find);
while (temp->next != front)
    {
        if(temp->data != find){
        temp = temp->next;
        pos++;
        flag = 0;
        }
        if(temp->data == find){
            flag = 1;
            break;
        }
    }
     if(flag == 1 ){
            printf("\n Value %d exists at position %d",find, pos);
        }
    if(flag == 0){
            printf("\n Value %d does not exist\n",find);
        }
    }
}

int main(){
    int choice,val;
    while ((1))
    {
        printf("\n0.Exit\n1.Enqueue\n2.Dequeue\n3.Display\n4.Peek\n5.Search\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            exit(0);
        
        case 1:
            printf("\nEnter the value to enqueue: ");
            scanf("%d", &val);
            enqueue(val);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            peek();
            break;
        
        case 5:
            search();
            break;
        }
    }
    
}