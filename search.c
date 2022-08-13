#include "stdio.h"
#include "stdlib.h"

void bubbleSort(int *arr, int n)
{
    char isSorted = 0;
    while (!isSorted)
    {
        isSorted = 1;
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                isSorted = 0;
            }
        }
    }
}

int binarySearch(int key, int *arr, int n)
{
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == key)
            return mid;
        if (key > arr[mid])
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int main()
{
    int n;
    printf("Please enter the array size: ");
    scanf("%d", &n);
    int *arr = (int *)calloc(n, sizeof(int));
    printf("Please enter the array elements (space-separated): ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }

    bubbleSort(arr, n);
    printf("Sorted Array: [");
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
        if (i != n - 1)
        {
            printf(",");
        }
    }
    printf("]\n");

    int key;
    printf("Please enter element to search for: ");
    scanf("%d", &key);
    int index = binarySearch(key, arr, n);
    if (index != -1)
    {
        printf("found at index: %d\n", index);
    }
    else
    {
        printf("not found\n");
    }

    return 0;
}