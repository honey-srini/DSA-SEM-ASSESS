#include<stdio.h>
#include<string.h>

struct book
{
    int bnum;
    char bookname[20];
    char bookauthr[20];
    int year;
    int copies;
};

struct book b[20];
void issuebook (int n)
{
    int bnum,flag=0,i=0;
    printf("Enter the book number \n");
    scanf("%d",&bnum);
    for(i=0;i<n;i++)
    {
        if(b[i].bnum==bnum)
        {
            b[i].copies--;
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("Book number is invalid \n");
    }
    if (flag==1)
    {
        printf("No.of copies =%d \n",b[i].copies);
    }
}

void returnbook(int n)
{
    int bnum,flag=0,i=0;
    printf("Enter the book number : \n");
    scanf("%d", &bnum);
    for(i=0;i<n;i++)
    {
        if(b[i].bnum==bnum)
        {
            b[i].copies++;
            flag=1;
            break;
        }
    }
    if (flag==0)
    {
        printf("Book number invalid \n");
    }
    if(flag==1)
    {
        printf("no.of copies %d \n",b[i].copies);
    }
}

void listbook(int n)
{
    int i=0, year=0, flag=0 ;
    printf("enter the year : \n");
    scanf("%d",&year);
    for(i=0;i<=n;i++)
    {
        if(b[i].year==year)
        {
            printf("Book Number : %d",b[i].bnum);
            printf("\nBook Name : %s",b[i].bookname);
            printf("\nBook Author : %s",b[i].bookauthr);
            printf("\nCopies of book : %d",b[i].copies);
            printf("\nYear of publication : %d",b[i].year);
            printf("\n");
            printf("\n");
            flag=1;
            break;
        }
    }
}

void listallbook (int n)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        printf("Book number : %d",b[i].bnum);
        printf("\nBook name : %s",b[i].bookname);
        printf("\nCopies of book : %d",b[i].copies);
        printf("\n");
        printf("\n");
    }
}

void listcopies (int n)
{
    char name[20];
    int i=0 , result;
    printf("Enter the name of the book :\n");
    scanf("%s",name);
    for(i=0;i<n;i++)
    {
        result=strcmp(name,b[i].bookname);
        if(result==0)
        {
            printf("No of copies is %d :\n",b[i].copies);
            printf("\n");
        }
    }
}

int main()
{
    int n,ch;
    printf("How many books available ? \n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter the book number : \n");
        scanf("%d",&b[i].bnum);
        printf("Enter the name of book : \n");
        scanf("%s",&b[i].bookname);
        printf("Enter the name of author: \n");
        scanf("%s",&b[i].bookauthr);
        printf("Enter the year of publication : \n");
        scanf("%d",&b[i].year);
        printf("Enter the total number of copies : \n");
        scanf("%d",&b[i].copies);
        printf("---------\n");
    }

    while(ch>=0)
    {
        printf("0 - exit \n");
        printf("1 - issue a book \n");
        printf("2 - accept a book \n");
        printf("3 - list books based on year \n");
        printf("4 - list all the books \n");
        printf("5 - search copies of a book by name \n");
        printf("\n");
        scanf("%d", &ch);

        if(ch==0)
        return 0;
        else if(ch==1)
        issuebook(n);
        else if(ch==2)
        returnbook(n);
        else if(ch==3)
        listbook(n);
        else if(ch==4)
        listallbook(n);
        else if(ch==5)
        listcopies(n);
    }   

}