#include<stdio.h>
#include<stdlib.h>
#define GAP 1
struct node
{
	int data,height;
	struct node *left,*right; 
}*root=0,*newnode,*temp,*temp1,*temp2;
max(int a,int b)
{
	return (a>b)?a:b;
}
height(struct node *root)
{
	return (root==0)?0:root->height;
}
balancefactor(struct node *root)
{
	return (root==0)?0:height(root->left)-height(root->right);
}
struct node *leftrotate(struct node *root)
{
    temp1=root->right;
    temp2=temp1->left;
    temp1->left=root;
    root->right=temp2;
    root->height=1+max(height(root->left),height(root->right));
    temp1->height=1+max(height(temp1->left),height(temp1->right));
    return temp1;
}
struct node *rightrotate(struct node *root)
{
    temp1=root->left;
    temp2=temp1->right;
    temp1->right=root;
    root->left=temp2;
    root->height=1+max(height(root->left),height(root->right));
    temp1->height=1+max(height(temp1->left),height(temp1->right));
    return temp1;
}
struct node *minimum(struct node *root)
{
	return ((root==0)||(root->left==0))?root:minimum(root->left);
}
struct node *maximum(struct node *root)
{
	return ((root==0)||(root->right==0))?root:maximum(root->right);
}
struct node *search(struct node *root,int value)
{
	if((root==0)||(root->data==value))
		return root;
	else 
		return (value<root->data)?search(root->left,value):search(root->right,value);
}
count(struct node *root)
{
	return (root==0)?0:count(root->left)+count(root->right)+1;
}
struct node *insertnode(struct node *root,int value)
{
	int bf;
	if(root==0)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		newnode->data=value;
		newnode->height=1;
		newnode->left=newnode->right=0;
		return newnode;
	}
	if(value<root->data)
		root->left=insertnode(root->left,value);
	else if(value>root->data)
		root->right=insertnode(root->right,value);
	else
		return root;
	root->height=1+max(height(root->left),height(root->right));	
	bf=balancefactor(root);
	if(bf>1&&value<root->left->data)
        return rightrotate(root);
    if(bf<-1&&value>root->right->data)
        return leftrotate(root);
    if(bf>1&&value>root->left->data)
    {
        root->left=leftrotate(root->left);
        return rightrotate(root);
    }
    if(bf<-1&&value<root->right->data)
    {
        root->right=rightrotate(root->right);
        return leftrotate(root);
    }
    return root;
}
struct node *deletenode(struct node *root,int value)
{
	int bf,ch;
	if(root==0)
		return root;
	if(value<root->data)
		root->left=deletenode(root->left,value);
	else if(value>root->data)
		root->right=deletenode(root->right,value);
	else
	{
		if(root->left==0)
		{
			temp=root;
			root=root->right;
			free(temp);
		}
		else if(root->right==0)
		{
			temp=root;
			root=root->left;
			free(temp);
		}
		else
		{
			printf("Replace with 1.Inorder predecessor or 2.Inorder successor");
			printf("\nEnter your choice: ");
			scanf("%d",&ch);
			if(ch==1)
			{
				temp=maximum(root->left);
    			root->data=temp->data;
		    	root->left=deletenode(root->left,temp->data);
			}
			else
			{
				temp=minimum(root->right);
    			root->data=temp->data;
		    	root->right=deletenode(root->right,temp->data);
  			}
  		}
  	}
  	if(root==0)
  		return root;
  	root->height=1+max(height(root->left),height(root->right));	
	bf=balancefactor(root);
	if(bf>1&&balancefactor(root->left)>=0)
        return rightrotate(root);
    if(bf<-1&&balancefactor(root->right)<=0)
        return leftrotate(root);
    if(bf>1&&balancefactor(root->left)<0)
    {
        root->left=leftrotate(root->left);
        return rightrotate(root);
    }
    if(bf<-1&&balancefactor(root->right)>0)
    {
        root->right=rightrotate(root->right);
        return leftrotate(root);
    }
    return root;
}	
void display(struct node *root,int space)
{
	int i;
    if(root==0)
        return;
    space=space+GAP;
    display(root->right,space);
    for(i=GAP;i<space;i++)
        printf("\t");
    printf("%d\n",root->data);
    display(root->left,space);
}
main()
{
	int choice,value;
	printf("AVL Tree Implementation");
	printf("\n1.Insert node\t2.Delete node\t3.Search\t4.Display\t5.Count\t6.End");
	do
	{
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:	printf("Enter Node: ");
					scanf("%d",&value);
					root=insertnode(root,value);
					printf("Node Inserted\n");
					display(root,0);
					break;
			case 2: if(root==0)
						printf("Tree is Empty");
					else
					{
						printf("Enter Node: ");
						scanf("%d",&value);
						temp=search(root,value);
						if(temp==0)
							printf("Node is not in Tree");
						else
							{
								root=deletenode(root,value);
								printf("Node Deleted");
							}
					}
					break;
			case 3: if(root==0)
						printf("Tree is Empty");
					else
					{
						printf("Enter Node: ");
						scanf("%d",&value);
						temp=search(root,value);
						if(temp==0)
							printf("Node is not in Tree");
						else
							printf("Node is found in location %u",temp);
					}
					break;
			case 4: if(root==0)
						printf("Tree is Empty");
					else
						display(root,0);
					break;
			case 5: printf("No of Nodes in Tree is %d",count(root));
					break;
			case 6: printf("Thank You");
					break;
			default:printf("Invalid Choice");
					break;
		}
	}while(choice!=6);
}