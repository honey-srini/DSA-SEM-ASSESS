#include<stdio.h>
int heap[50];

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int n,int i)
{
    int lar = i;
    int l = (2*i)+1;
    int r = (2*i)+2;
    if (l<n&&heap[l]>heap[lar]) lar = l;
    if (r<n&&heap[r]>heap[lar]) lar = r;
    if (lar!=i)
    {
        swap(&heap[lar],&heap[i]);
        heapify(n,lar);
    }
}

int insert(int n)
{
    int node,i;
    printf("\nEnter the node: ");
    scanf("%d",&node);
    heap[n++]=node;
    for(i=n/2-1;i>=0;i--) heapify(n,i);
    return n;
}

int del(int n)
{
    int node,i;
    printf("\nEnter the node: ");
    scanf("%d",&node);
    for(i=0;i<n;i++) if(heap[i]==node) break;
    if(i!=n)
    {   printf("%d is deleted.\n",heap[i]);
        swap(&heap[i],&heap[n-1]); 
        n--;
        for(i=n/2-1;i>=0;i--) heapify(n,i);
    }
    return n;
}

void minheap(int n)
{
    int i;
    for(i=n-1;i>0;i--)
    {
        swap(&heap[i],&heap[0]); 
        heapify(i,0);
    }
}

void print(int n)
{
    printf("Heap Level Order\n");
    for(int j=0;j<n;j++) printf("%d  ",heap[j]); printf("\n");
    printf("\n");
}

void display(int n,int i,int space)
{
    if (i<n)
    {
        int l = (2*i)+1;
        int r = (2*i)+2;
        space+=1;
        display(n,r,space);
        for(int j=1;j<space;j++) 
            printf("\t");
        printf("%d\n",heap[i]);
        display(n,l,space);
    }
}

int main()
{
    int ch,n = 0;
   

    while(1)
    {
    printf("\nEnter the choice: ");
    scanf("%d",&ch);
    switch(ch)
        {
            case 1: n = insert(n);
                    print(n);
                    printf("Heap as tree\n");
                    display(n,0,0);
                    break;
            case 2: n = del(n);
                    print(n);
                    printf("Heap as tree\n");
                    display(n,0,0);
                    break;
            case 3: minheap(n);
                    print(n);
                    display(n,0,0);
                    break;
            default: printf("\nWrong Choice\n");
        }
    }
}