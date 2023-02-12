#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
struct ll
{
    int data;
    struct ll* next;
};

struct ll *head = NULL;
int top = -1;

struct ll* addtoll(int value, struct ll* ptr){
    struct ll* node = malloc(sizeof(struct ll));
    node->data = value;

    if (ptr == NULL)
    {
        node->next = NULL;
        ptr = node;
        return ptr;
    }
    else if (ptr != NULL)
    {
        node->next = ptr;
        ptr = node;
        return ptr;
    }    
}

struct ll* deletefromll(struct ll* ptr){
    struct ll* temp = ptr->next;
    printf("The element pop is %d\n",ptr->data);
    free(ptr);
    ptr = temp;
    return ptr;
}

void displayll(struct ll* ptr){
    if (ptr==NULL)
    {
        printf("Stack is empty. No data to display\n");
    }
    else
    {
        printf("Data in the Linked List\n");
        while (ptr!=NULL)
        {
            printf("%d\n",ptr->data);
            ptr = ptr->next;
        }
    }
}

void push(struct ll* ptr){
    int value;
    printf("Enter value to be added to stack ");
    scanf("%d",&value);
    ptr = addtoll(value,ptr);
    head = ptr;
    top++;
}

void pop(struct ll* ptr){
    if (ptr==NULL)
    {
        printf("There is no element to pop\n");
    }
    else
    {
        head = deletefromll(ptr);
        top--;
    }
}

void peek(struct ll* ptr){
    if (top==-1)
    {
        printf("UNDERFLOW\n");
    }
    else
    {
        printf("The peek element is %d\n",ptr->data);
    }
}

bool isEmpyty(struct ll* ptr){
    if (ptr==NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int sizeofstack(struct ll* ptr){
    if (ptr==NULL)
    {
        return 0;
    }
    else
    {
        int counter = 0;
        while (ptr!=NULL)
        {
            ptr = ptr->next;
            counter++;
        }
        return counter;
    }
}

void search(struct ll *ptr)
{
    struct ll *temp =ptr;
    int key;
    printf("Enter element to be searched ");
    scanf("%d",&key);
    // printf(temp);
    int count =1;

    //iterate the entire linked list and print the data
    while(temp != NULL)
    {
         //key found return 1.
         if(temp->data == key)
         count=count+1;
         printf("element is found in the linked list1 %d position",count);
        
         temp = temp->next;
         break;
    }
    //key not found
    // printf("element not in the linked list");
}

void main(){
    int choice;
    printf("\n");
    printf("Stack Operations\n");
    printf("1. PUSH\n");
    printf("2. DISPLAY\n");
    printf("3. POP\n");
    printf("4. PEEK\n");
    printf("5. ISEMPTY\n");
    printf("6. SIZE OF STACK\n");
    printf("7. SEARCH AN ELEMENT\n");
    printf("8. EXIT\n");
    printf("Enter your choice number\n");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
        push(head);
        main();
    case 2:
        displayll(head);
        main();
    case 3:
        pop(head);
        main();
    case 4:
        peek(head);
        main();
    case 5:
        if (isEmpyty(head))
        {
            printf("True\n");
        }
        else
        {
            printf("False\n");
        }
        main(); 
    case 6:
        printf("The size of stack is %d\n",sizeofstack(head));
        main();  
    case 7:
        search(head);
        main();           
    case 8:
        exit(0);
        break;    
    default:
        printf("Wrong Choice! Enter a valid number\n");
        main();
    }
}
