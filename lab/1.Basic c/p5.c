#include<stdio.h>
void main()
{
    int p,n;
    float r,si;
    printf("Enter the principal amount :");
    scanf("%d",&p);
    printf("Enter the no of years :");
    scanf("%d",&n);
    printf("Enter the rate of interest :");
    scanf("%f",&r);
    si=(p*n*r)/100;
    printf("The simple interest is :%f",si);

}