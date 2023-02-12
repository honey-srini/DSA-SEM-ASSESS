#include<stdio.h>
#include<stdlib.h>
#define MAX 100
void copy(int arr[],int temp[],int low,int up);
void merge(int arr[],int temp[],int low1,int up1,int low2,int up2);
void merge_sort(int arr[],int low,int up)
{
	int mid;
	int temp[MAX];
	if(low<up)
	{
		mid=(low+up)/2;
		merge_sort(arr,low,mid);
		merge_sort(arr,mid+1,up);
		merge(arr,temp,low,mid,mid+1,up);
		copy(arr,temp,low,up);
	}
}
void merge(int arr[],int temp[],int low1,int up1,int low2,int up2)
{
	int i=low1;
	int j=low2;
	int k=low1;
	while((i<up1)&&(j<=up2))
	{
		if(arr[i]<=arr[j])
		 temp[k++]=arr[i++];
		else
		  temp[k++]=arr[j++];
	}
	while(i<=up1)
	  temp[k++]=arr[i++];
	while(j<=up2)
	   temp[k++]=arr[j++];
}
void copy(int arr[],int temp[],int low,int up)
{
	int i;
	for(i=low;i<=up;i++)
	{
		arr[i]=temp[i];
	}
}
int main()
{
	int arr[MAX],arr2[MAX],arr3[MAX],n1,n2,i;
	printf("Enter the size of first Array:");
	scanf("%d",&n1);
	printf("Enter Ele:");
	for(i=0;i<n1;i++)
	{
		scanf("%d",&arr);
	}
	
	merge_sort(arr,0,n1-1);
	printf("Merge list:\n");
	for(i=0;i<n1;i++)
	  printf("%d",arr[i]);
}
