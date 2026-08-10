#include <stdio.h>
int interpolationSearch(int arr[], int low, int high, int key)
{
    if(low <= high && key >= arr[low] && key <= arr[high])
    {
        int pos = low + 
        ((key-arr[low])*(high-low)) /
        (arr[high]-arr[low]);

        if(arr[pos] == key)
            return pos;

        if(arr[pos] < key)
            return interpolationSearch(arr,pos+1,high,key);

        else
            return interpolationSearch(arr,low,pos-1,key);
    }
    return -1;
}
int main()
{
    int arr[] = {10,20,30,40,50,60};
    int n = 6;
    int key;
    printf("Enter element to search: ");
    scanf("%d",&key);
    int result = interpolationSearch(arr,0,n-1,key);
    if(result != -1)
        printf("Element found at position %d",result+1);
    else
        printf("Element not found");

    return 0;
}

