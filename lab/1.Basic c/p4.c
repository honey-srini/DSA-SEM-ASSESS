#include<stdio.h>    
int main()    
{    
 int a,b,c,i,n;   
 printf("Enter the number of elements:");    
 scanf("%d",&n);    
 a=0;
 b=1;
 printf("\n%d %d",a,b);  
 for(i=2;i<n;++i)   
 {    
  c=a+b;  
  printf(" %d",c);    
  a=b;
  b=c;  
 }  

 }    
