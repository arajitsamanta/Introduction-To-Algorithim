#include <stdio.h>

void insertionSort(int a[], int n);
void printArray(int a[], int n);

int main()
{
    int arr[] = {5, 2, 4, 3, 16};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, n);
    printArray(arr, n);
    printf("\n");
}

/*
Runtime Complexity
==================
Time: O(n^2)
Space:O(1)
*/
void insertionSort(int a[], int n)
{
    int key, j;

    for (int i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
        printArray(a, n);
        printf("\n");
    }
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}