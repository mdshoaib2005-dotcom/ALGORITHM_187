#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Partition function
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low -1;
    
    for(int j = low; j< high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[j], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

//Quick Sort Function
void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int main()
{
    int n_values[] = {10000, 20000, 50000, 100000, 200000, 500000};
    int size =6;

    printf("Quick Sort Time Analysis\n");
    printf("------------------------\n");
    printf("\tTime(seconds)\n");

    for(int k = 0; k < size; k++)
    {
        int n = n_values[k];
        int *arr = (int *)malloc(n * sizeof(int));

        for(int i = 0; i<n; i++)
        {
            arr[i] = rand() % 100000;
        }

        clock_t start = clock();

        quickSort(arr, 0, n-1);

        clock_t end = clock();

        double time_taken = ((double)(end-start)) / CLOCKS_PER_SEC;
        printf("%d\t%f\n", n, time_taken);
        
        free(arr);
    }
    return 0;
}