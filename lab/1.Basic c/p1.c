#include<stdio.h>
void main()
{
    int a[50],n,i,j,tmp;
    printf("Enter the no of elements :");
    scanf("%d",&n);
    //getting the numbers
    printf("Enter the numbers : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    //sorting
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]> a[j])
            {
                tmp=a[i];
                a[i]=a[j];
                a[j]=tmp;
            }   
        }
    }
//printing sorted elements
printf("The ascending order is :");
for(i=0;i<n;i++)
    printf("\n %d",a[i]);

}
