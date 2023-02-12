#include <stdio.h>
#include <stdlib.h>
#define n 10
int hash[n] = {NULL};
void insert(){
    int hash2,value,i,hashkey,index;
    printf("enter the value : ");
    scanf("%d",&value);
    hash2 = 7-(value%7);
    hashkey = value%n;
    for(i=0;i<n;i++){
        index = (hashkey+i*hash2)%n;
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
    int value,i,hashkey,index,hash2;
    printf("enter the value : ");
    scanf("%d",&value);
    hash2 = 7-(value%7);
    hashkey = value%n;
    for(i=0;i<n;i++){
        index = (hashkey+i*hash2)%n;
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
    int value,i,hash2,hashkey,index,flag = 0;
    printf("enter the value : ");
    scanf("%d",&value);
    hash2 = 7-(value%7);
    hashkey = value%n;
    for(i=0;i<n;i++){
        index = (hashkey+i)%n;
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
        printf("enter 1 to insert\n");
        printf("enter 2 to delete\n");
        printf("enter 3 to display\n");
        printf("enter 4 to search\n");
        printf("enter the choice : ");
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