#include <stdio.h>
#include <stdlib.h>
#define n 10
int hash[n] = {NULL};
void insert(){
    int value,i,hashkey,index;
    printf("enter the value : ");
    scanf("%d",&value);
    hashkey = value%n;
    for(i=0;i<n;i++){
        index = (hashkey+i*i)%n;
        if(hash[index] == NULL){
            hash[index] = value;
            break;
        }
    }
    if(i == n){
        printf("table size if full");
    }
}
void delete(){
    int value,i,hashkey,index;
    printf("enter the value : ");
    scanf("%d",&value);
    hashkey = value%n;
    for(i=0;i<n;i++){
        index = (hashkey+i*i)%n;
        if(hash[index] == value){
            hash[index] = -1;
            break;
        }
    }
}
void display(){
    int i;
    for(i=0;i<n;i++){
        printf("key = %d and value = %d\n",i,hash[i]);
    }
}
void search(){
    int value,i,hashkey,index,flag = 0;
    printf("enter the value : ");
    scanf("%d",&value);
    hashkey = value%n;
    for(i=0;i<n;i++){
        index = (hashkey+i*i)%n;
        if(hash[index] == value){
            flag = 1;
            break;
        }
    }
    if(flag == 1){
        printf("element is found at key %d\n",index);
    }else{
        printf("element not found");
    }
}

int main(){
    int choice;
    while(1){
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.Search\n");
        printf("Enter the choice : ");
        scanf("%d",&choice);
        switch(choice){
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
            search();
            break;
            default:
            printf("wrong choice");
        }
    }
}