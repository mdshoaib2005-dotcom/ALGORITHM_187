#include <stdio.h>
#include <time.h>

// Recursive Binary Search
int binarySearch(int a[], int low, int high, int key)
{
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (a[mid] == key)
        return mid;
    else if (key < a[mid])
        return binarySearch(a, low, mid - 1, key);
    else
        return binarySearch(a, mid + 1, high, key);
}

int main()
{
    int a[1000000];

    // Create sorted array
    for (int i = 0; i < 1000000; i++)
        a[i] = i + 1;

    int values[] = {100, 500, 1000, 5000, 10000, 50000, 100000};
    int size = 7;

    printf("Recursive Binary Search\n");
    printf("----------------------------------------\n");
    printf("n\t\tTime (seconds)\n");
    printf("----------------------------------------\n");

    for (int i = 0; i < size; i++)
    {
        int n = values[i];
        int key = n / 2;

        clock_t start = clock();

        // Repeat search to get measurable time
        volatile int result;

        for (int j = 0; j < 1000000; j++)
        {
            result = binarySearch(a, 0, n - 1, key);
        }

        clock_t end = clock();

        double time_taken =
            (double)(end - start) / CLOCKS_PER_SEC;

        printf("%d\t\t%f\n", n, time_taken);
    }

    return 0;
}