#include <stdio.h>  

  
void main ()  
{  
    int arr[10];  
    int p, i, n; // declare int type variable  
    printf (" Enter the number of elements in an array:  ");  
    scanf (" %d", &n);  
    printf (" Enter %d elements in array:", n);  
    // use for loop to insert elements one by one in array  
    for (i = 0; i < n; i++ )  
    {   printf (" arr[%d] = ", i);  
        scanf (" %d", &arr[i]);  
    }  
      
    // enter the position of the element to be deleted  
    printf( " enter the index of the element to be deleted : ");  
    scanf (" %d", &p);  
      
    // check whether the deletion is possible or not  
    if (p >= n+1)  
    {  
        printf (" \n Deletion is not possible in the array.");  
    }  
    else  
    {  
        // use for loop to delete the element and update the index  
        for (i = p; i < n -1; i++)  
        {  
            arr[i] = arr[i+1]; // assign arr[i+1] to arr[i]  
        }  
          
        printf (" \n The resultant array is: \n");  
          
        // display the final array  
        for (i = 0; i< n - 1; i++)  
        {  
            printf (" arr[%d] = ", i);  
            printf (" %d \n", arr[i]);  
        }  
    }   
}  