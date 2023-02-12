#include<stdio.h>
struct student
{
    char name[20];
    int reg;
    int marks;
};
int main()
{
    struct student s[20],temp;
    int i,j,n,s1,s2,s3,sum,ct=1;
    printf("enter the no.of students :");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter Name , Reg.No and Marks in 3 Subjects : \n");
        scanf("%s %d %d %d %d" ,s[i].name , &s[i].reg ,&s1,&s2,&s3);
        sum=s1+s2+s3;
        s[i].marks=sum;
    }


    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(s[i].marks < s[j].marks)
            {
                temp=s[i];
                s[i]=s[j];
                s[j]=temp;
            }
        }
    }

    printf("Rank List : \n");
    for(i=0;i<n;i++)
    {
        printf("\n");
        printf("Rank : %d \n",ct);
        printf("Name : %s \n",s[i].name);
        printf("Registration No : %d \n",s[i].reg);
        printf("Marks : %d \n\n",s[i].marks);
        ct++;
    }
    return 0;
}