#include <stdio.h>
#include <stdlib.h>
struct node {
  int key;
  struct node *left, *right;
};

struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}
void inorder(struct node *root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%d -> ", root->key);
    inorder(root->right);
  }
}
void preorder(struct node *root) {
  if (root != NULL) {
    printf("%d -> ", root->key);
    preorder(root->left);
    preorder(root->right);
  }
}
void postorder(struct node *root) {
  if (root != NULL) {
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->key);
  }
}
struct node *insert(struct node *node, int key) {
  
  if (node == NULL) return newNode(key);
 
  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}

// Find the inorder successor
struct node *minValueNode(struct node *node) {
  struct node *current = node;

  // Find the leftmost leaf
  while (current && current->left != NULL)
    current = current->left;

  return current;
}

struct node *deleteNode(struct node *root, int key) {
  
  if (root == NULL) return root;

  
  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);

  else {
    // If the node is with only one child or no child
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }

    // If the node has two children
    struct node *temp = minValueNode(root->right);

    // Place the inorder successor in position of the node to be deleted
    root->key = temp->key;

    // Delete the inorder successor
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}

int search(struct node* root, int value) 
{ 
  
    while (root != NULL){

        if (value > root->key) 
            root = root->right; 

        else if (value < root->key) 
            root = root->left; 
        else
            return 1; 
    } 
    return 0; 
} 

int main() {
  int i,n,val,dval,choice,item;
  struct node *root = NULL;

 do      
        {  
            printf("\nBinary Search Tree Operations");  
            printf("\n1. To insert a new node in the Binary Tree");  
            printf("\n2. To delete a value from tree");  
            printf("\n3. To search the node in tree");
            printf("\n4. To display the elements in inorder traversal");
            printf("\n5. To display the elements in preorder traversal");
            printf("\n6. To display the elements in postorder traversal");
            printf("\nEnter your choice:");
 
            scanf("%d",&choice);              
            switch (choice)  
            {  
            case 1 :   
                printf("Enter the number of elements to add: ");
                scanf("%d",&n);
                for(i=0;i<n;i++)
                {
                scanf("%d",&val);
                root = insert(root, val);
                }                   
                break;                            
            case 2 :   
                printf("Enter an element to delete: ");
                scanf("%d",&dval);
                root = deleteNode(root, dval); 
                break; 
            case 3 :   
                
                printf("Enter an item to search: ");
                scanf("%d" ,&item);
                int found = search(root,item);

                if(found)
                    printf("%d value is found in the tree\t",item);
                else
                    printf("%d value not found in the tree\t",item);

            case 4 :   
                printf("Inorder traversal: ");
                inorder(root); 
                break; 
                 case 5 :   
                printf("preorder traversal: ");
                preorder(root); 
                break; 
                 case 6 :   
                printf("postorder traversal: ");
                postorder(root); 
                break; 
            default :   
                printf("Wrong Entry\n");  
                break;     
            }  
  
            printf("\nDo you want to continue (Type y or n)\n");  
            scanf(" %c",&choice);                          
        } while (choice == 'Y'|| choice == 'y');  
  
   return 0;  

}