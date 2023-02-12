#include <stdio.h>
void main()
{
    int a[10],i,n,min,max;
   
    printf("Enter the no of elements : ");
    scanf("%d",&n);
 
    printf("Enter the numbers : ");
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
 
    min=max=a[0];
    for(i=1; i<n; i++)
    {
         if(min>a[i])
		  min=a[i];   
		   if(max<a[i])
		    max=a[i];       
    }
     printf("minimum of array is : %d",min);
    printf("\n maximum of array is : %d",max);

}
