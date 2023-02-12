#include <stdio.h>
#include <stdlib.h>
#define n 10
int hash[n] = {NULL};

void insert(){
    int hash1,hash2,value,i,hashkey,index;
    printf("Enter the value to be inserted: ");
    scanf("%d",&value);
    hash1=value%11;
    hash2=value%5;
   
    for(i=0;i<n;i++){
        index = (hash1+i*hash2)%n;
        if(hash[index] == NULL){
            hash[index] = value;
            break;
        }
    }
    if(i == n){
        printf("\nTable size if full");
    }
}

void display(){
    int i;
    for(i=0;i<n;i++){
        printf("key = %d & Value = %d\n",i,hash[i]);
    }
}

int main(){
    int choice;
    while(1){
        printf("1.Insert the Element\n");
        printf("2.Display the Hash Table\n");
        printf("Enter the choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            insert();
            break;
           
            case 2:
            display();
            break;
            
            default:
            printf("wrong choice");
        }
    }
}