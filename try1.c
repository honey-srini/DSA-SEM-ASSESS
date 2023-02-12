#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define n 5
int arr[n];
int top=-1;

void main(){
    
    
    int choice;
    
    while(choice!=6){

    printf("\n1.push:");
    printf("\n2.pop:");
    printf("\n3.view:");
    printf("\n4.top:");
    printf("\n5.search:");
    printf("\n6.exit:");
    printf("Enter the choice:");
    scanf("%d",&choice);

    switch(choice){
    case 1:
    void push();
    break;
    
    case 2:
    void pop();
    break;
    
    case 3:
    void view();
    break;
    
    case 4:
    void peek();
    break;
    
    case 5:
    void search();
    break;
    
    

    case 6:
    return 0;
    break;

    default:
    printf("Invalid");

    }
    }
}

void push(){
    char str;
    if (top==n-1){
        printf("Overflow");
    }
    else{
        printf("Enter:");
        scanf("%s",&str);
        if(isalpha(str)==0){
            printf("Only characters:");
        }
        else{
            if(arr[top]==str){
                printf("no repeatation");

            }
            else{
                top=top+1;
                arr[top]=str;
            }
        }

    }
}

void pop(){
    if (top==-1){
        printf("Underflow");
    }
    else{
        top=top-1;

    }
}

void peek(){
    printf("Top:",top);
}

void search(){
    char f;
    printf("Find:");
    scanf("%s",&f);
    for (int i=0;i<=top;i++){
        if(arr[i]==f){
            printf("Found at:%d",arr[i]);
            break;
        }
        else if(i==top){
            printf("not found");
        }
        
    }
}

