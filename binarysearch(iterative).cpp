#include <stdio.h>
int binarySearch(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60};
    int n = 6;
    int key;
    printf("Enter element to search: ");
    scanf("%d", &key);
    int result = binarySearch(arr, n, key);
    if (result != -1)
        printf("Element found at position %d", result + 1);
    else
        printf("Element not found");
    return 0;
}
