#include<stdio.h>
#include<stdlib.h>

typedef struct linkedlist{
	int data;
	struct linkedlist *next;
}node;
void display(node *head);
void create();
void add_beg();
void add_end();
void add_before();
void add_after();
void add_pos();
void delete_beg();
void delete_end();
void delete_after();
void delete_before();
void delete_pos();
void search();
node *head = NULL;
int num,n,count;

void create(){
	node *new,*temp;
	printf("Enter the number of nodes you want to create: ");
	scanf("%d", &n);
	new = (node*) malloc(sizeof(node));
	if(new == NULL){
		printf("No memory");
	}
	else{
		printf("Element[1]: ");
		scanf("%d", &num);
		new->data = num;
		new->next = NULL;
		head = new;
		temp = head;
		count = 1;
		for(int i = 2; i <= n; i++){
			new = (node*) malloc(sizeof(node));
			if(new == NULL){
			printf("No Memory");
			}
			else {
			printf("Element[%d]: ", i);
			scanf("%d", &num);
			new->data = num;
			new->next = NULL;
			temp->next = new;
			temp = temp ->next;
			count++;
			}
		}
	}
	display(head);
}

void display(node *head){

	node *temp = head;
	if (temp == NULL){
		printf("There is no linked list");
	}
	else{
	while(temp != NULL){
		printf("\n%d", temp->data);
		temp = temp->next;
	}
	}
	printf("\nCount : %d\n", count);
}

void  add_beg(){
	node *new;
	new = (node*) malloc(sizeof(node));
	if(new == NULL){
	printf("No Memory");
	}
	else{
	printf("\nEnter the element you want to add in beginning : ");
	scanf("%d", &num);
	new->data = num;
	new->next = head;
	head = new;
	count++;
	}
	display(head);
}

void add_end(){
	node *new,*temp;
	temp = head;
	new = (node*) malloc(sizeof(node));
	if(new == NULL){
		printf("No Memory");
	}
	else{
		printf("\nEnter the element you want to add at the end : ");
		scanf("%d", &num);
		new->data = num;
		new->next = NULL;
		while(temp->next != NULL){
			temp = temp->next;
		}
	temp->next = new;
	count++;
	}
	display(head);
}

void add_before(){
	int before;
	node *new, *preptr,*ptr;
	ptr = head;
	new = (node*) malloc(sizeof(node));
	if(new == NULL){
		printf("No Memory");
	}
	else{
		printf("\nThe node you want to add before : ");
		scanf("%d", &before);
		printf("\nEnter the element you want to add at the before %d : ", before);
		scanf("%d", &num);
		new->data = num;
		while( ptr->data != before){
			preptr = ptr;
			ptr = ptr->next;
		}
		new->next = ptr;
		preptr->next =new;
		count++;
	}
	display(head);
}

void add_after(){
	int after;
	node *new, *preptr,*ptr;
	ptr = head;
	new = (node*) malloc(sizeof(node));
	if(new == NULL){
		printf("No Memory");
	}
	
	else{
		printf("\nThe node you want to add after : ");
		scanf("%d", &after);
		while( preptr->data != after){
			preptr = ptr;
			ptr = ptr->next;
		}
		if (preptr->next == NULL){
			printf("\nThe node doesn't exits\n");
		}
		else{
		printf("\nEnter the element you want to add at the after %d : ", after);
		scanf("%d", &num);
		new->data = num;
		
		
		new->next = ptr;
		preptr->next =new;
		count++;
	}
	}
	display(head);
}
void add_pos(){
	int pos;
	int i =1;
	node *new;
	node *preptr = head;
	node *ptr = head;
	new = (node*) malloc(sizeof(node));
	if(new == NULL){
		printf("No Memory");
	}
	else{
		printf("\nEnter the position you want to add the element : ");
		scanf("%d", &pos);
        if(pos == 1){
            add_beg();
        }
        else{
		printf("\nEnter the element you want to add at position %d : ", pos);
		scanf("%d", &num);
		
		new->data = num;
        
		while(i<pos){
			preptr = ptr;
			ptr = ptr->next;
			i++;
		}
		preptr->next = new;
		new->next = ptr;
		count++;
	}
    }
	display(head);
}
void delete_beg(){
	node *temp = head;
	head = head->next;
	free(temp);
	count--;
	display(head);
}

void delete_end(){
	node *ptr = head;
	node *preptr;
	while(ptr->next != 0){
		preptr = ptr;
		ptr = ptr->next;
	}
	preptr->next = NULL;
	free(ptr);
	count--;
	display(head);
}
void delete_after(){
	node *ptr = head;
	node *preptr = head;
	printf("You want to delete the node comes after :");
	scanf("%d", &num);
	while(preptr->data != num){
		preptr = ptr;
		ptr = ptr->next;
	}
	preptr->next = ptr->next;
	free(ptr);
	count--;
	display(head);
	
}

void delete_before(){
	node *ptr = head;
	node *preptr, *temp = head;
	printf("You want to delete the node comes before :");
	scanf("%d", &num);
	while(ptr->data != num){
		preptr = temp;
		temp = temp->next;
		ptr = temp ->next;
	}
    
	preptr->next = ptr;
	free(temp);
	count--;
	display(head);
	
}
void delete_pos(){
	node*ptr =head, *preptr =head;
	int pos;
	printf("Element in the position you want to delete: ");
	scanf("%d", &pos);
	for (int i = 1 ; i < pos; i++){
		preptr = ptr;
		ptr = ptr->next;
	}
	preptr->next =ptr->next;
	free(ptr);
	count--;
	display(head);
}

void search(){
	if(head == NULL){
		printf("No linked list");
	}
	else{
	node *temp = head;
	int find,pos=1,flag;
	printf("search: ");
	scanf("%d", &find);
	while(temp != NULL){
		if(temp->data != find){
			temp = temp->next;
			pos++;
			flag = 1;	
		}
		else{
			flag = 0;
			break;
		}	
	}
	if (flag == 0){
			printf("The element %d exists at position %d", find, pos);
		}
	else{
			printf("The element does not exist in the linked list");
		}
	}
}

int main(){
	int choice;
	printf("\n1.Create\n2.Add at beginning\n3.Add at end\n4.Add after a given node\n5.Add before a given node\n6.Add at specific position\n7.Delete at beginning\n8.Delete at end\n9.Delete after a given node\n10.Delete before a given node\n11.Delete at specific position\n12.Search\n13.Display\n");
	while(1){
		printf("\nEnter your choice : ");
		scanf("%d",&choice);
		switch(choice){
			case 0:
			exit(0);

			case 1:
			create();
			break;

			case 2:
			add_beg();
			break;

			case 3:
			add_end();
			break;

			case 4:
			add_after();
			break;

			case 5:
			add_before();
			break;

			case 6:
			add_pos();
			break;

			case 7:
			delete_beg();
			break;

			case 8:
			delete_end();
			break;

			case 9:
			delete_after();
			break;

			case 10:
			delete_before();
			break;

			case 11:
			delete_pos();
			break;

			case 12:
			search();
			break;

			case 13:
			display(head);
			break;
		}
		}
	}