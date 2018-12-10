#include <stdlib.h>
#include <stdio.h>

int removeDuplicates(int arr[], int n) 
{ 
    // Return, if array is empty 
    // or contains a single element 
    if (n==0 || n==1) 
        return n; 
  
    int temp[n]; 
  
    // Start traversing elements 
    int j = 0; 
    for (int i=0; i<n-1; i++) 
  
        // If current element is not equal 
        // to next element then store that 
        // current element 
        if (arr[i] != arr[i+1]) 
            temp[j++] = arr[i]; 
  
    // Store the last element as whether 
    // it is unique or repeated, it hasn't 
    // stored previously 
    temp[j++] = arr[n-1]; 
  
    // Modify original array 
    for (int i=0; i<j; i++) 
        arr[i] = temp[i]; 
  
    int len = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < len; ++i)
    {
       printf("%d\n", arr[i]);
    }
    return j; 
} 

int main () {
    int arr[] = {1,2,3,4,4,4};
    removeDuplicates(arr, 5);
}






