#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
int H[10];
int GAP=1;
int n;
int size=0;
void call(int i);
void Insert(int A[],int n) 
{
size++; 
 int i=n,temp; 
 temp=A[i]; 
 while(i>1 && temp>A[i/2]) 
 { 
 A[i]=A[i/2]; 
 i=i/2; 
 } 
 A[i]=temp; 
} 

int Delete(int A[],int n) 
{ 
  size--;
 int i,j,x,temp,val; 
 val=A[1]; 
 x=A[n]; 
 A[1]=A[n]; 
 //A[n]=val; 
 i=1;j=i*2; 
 while(j<=n-1) 
 { 
 if(j<n-1 && A[j+1]>A[j]) 
 j=j+1; 
 if(A[i]<A[j]) 
 { 
	 temp=A[i]; 
	 A[i]=A[j]; 
	 A[j]=temp; 
	 i=j; 
	 j=2*j; 
 } 
 else
 break; 
 } 
 return val; 
} 
void display()
{
	 int i;
 for(i=1;i<=size;i++) 
 {
   call(i);
  printf("%d ",H[i]);	
 }
}
int main()
{ 
 
 int i=1,choice; 
// printf("Enter the size of array:");
 //scanf("%d",&n);
 /*for(i=1;i<=n;i++)
 {
 	printf("\nEnter data:");
 	scanf("%d",&H[i]);
 	Insert(H,i);
 	display();
 	
 }*/
  
  
 // for(i=2;i<=n;i++) 
    

 while(1)
 {
 	printf("\n1.Insert");
 	printf("\n2.Delete");
 	printf("\n3.Display");
 	printf("\n4.Exit");
 	printf("Enter your choice:");
 	scanf("%d",&choice);
 	switch(choice)
 	{
 	 case 1:
 	 		printf("\nEnter data:");
 	        scanf("%d",&H[i]);
 	        Insert(H,i);
 	        i++;
 	        display();
	  break;
	  case 2:
	  	printf("Deletd item:%d ", Delete(H,i));
	  	printf("\n");
	  	//display();
	  break;
	  case 3:
	  	display();
	   break;
	   case 4:
	   exit(0); 	
	}
 }
 
 for(i=1;i<=n;i++) 
 {
   call(i);
  printf("%d ",H[i]);	
 }
 
 
 /*
 printf("\n");
 printf("%d ", Delete(H,n));
 printf("\n");
 n--;
 for(i=1;i<=n;i++) 
 printf("%d ",H[i]);
 
 /*for(i=7;i>1;i--) 
 { 
   Delete(H,i); 
 } 
 printf("\n");
 printf("%d ", Delete(H,7));
 printf("\n");

 
 for(i=1;i<=7;i++) 
 printf("%d ",H[i]); 
 printf("\n"); */
 
 return 0; 
}
void call(int i)
{
 	if(i==1)
 	 printf("\t\t  ");if(i==2)printf("\n\n\t  ");if(i==3)printf("\t\t\t");if(i==4)printf("\n\n ");if(i==5)printf("\t\t");if(i==6)printf("\t");if(i==7)
 	printf("\t\t");
 //	if(i==8)
 //	printf("\t\t\t");
}
