#include<stdio.h>
#include<stdlib.h>
#define N 5
int queue[N];
int front = -1;
int rear =  -1;

void enqueue(int val){
    if(front == -1 && rear == -1){
        front = 0;
        rear = 0;
        queue[rear] = val;
        printf("queue[%d]->%d", rear, queue[rear]);
    }
    else if(front == (rear+1)%N){
        printf("\n f: %d r: %d ",front,rear);
        printf("\nOverflow");

    }
    else{
        rear =  (rear+1) % N;
        queue[rear] = val;
        printf("queue[%d]->%d", rear, queue[rear]);
    }
    
}
void dequeue(){
    if(front == -1 && rear == -1){
        printf("\nUnderflow");
    }
    else{
        printf("f b : %d ", front);
        front = (front + 1) % N;
        printf("f a :%d", front);
    }
}

void display(){
    for(int i = front; i != rear; i = (i+1)%N){
        printf("%d ", queue[i]);
    }
    printf("%d ", queue[rear]);
}

void peek(){
    printf("%d", queue[front]);
}

void isempty(){
    if(front == -1 && rear ==-1 ){
        printf("\nThe queue is empty\n");
    }
    else{
        printf("\nQueue is not empty\n");
    }
}
void isfull(){
    if(front == (rear+1)%N){
        printf("\nQueue is full\n");
    }
    else{
        printf("\nQueue is not full\n");
    }
}

void search(){
    int  find,temp = front,flag = 0;
    if(queue == NULL){
        printf("There's no queue");
    }
    else{
    printf("Value to search : ");
    scanf("%d", &find);
        do{
            {
            
            if(queue[temp] == find){
                flag = 1;
                break;   
        }
        else{
            flag = 0;
        }
        temp = (temp+1) % N;
        }
        }
        while (queue[temp] != rear);
        
        if (flag == 0){
            printf("\n Value %d does not exist in queue\n", find);
        }
        if(flag == 1){
            printf("\n Value %d exists in position %d",find,temp+1);
        }
        
    }
}

int main(){
    int choice;
    int val;
    while(1){
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Peek\n5.IsEmpty?\n6.IsFull?\n7.Search\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 0:
            exit(0);

            case 1 : 
            if(front == (rear+1)%N){
                printf("\nOverflow");
            }
            else{
            printf("\nElement to enqueue : ");
            scanf("%d",&val);
            enqueue(val);
            }
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
            isempty();
            break;

            case 6:
            isfull();
            break;

             case 7:
            search();
            break;
        }
    }
    
}