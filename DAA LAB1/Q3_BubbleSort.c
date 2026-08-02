/*1. Read n elements.
2. For each pass:
      Compare adjacent elements.
      Swap if needed.
3. If no swap occurs:
      Stop sorting.
4. Print sorted array.*/
#include <stdio.h>

void bubbleSort(int arr[], int n)
{
    int i, j, temp, swapped;

    for(i = 0; i < n - 1; i++)
    {
        swapped = 0;

        for(j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }

        if(swapped == 0)
            break;
    }
}

int main()
{
    int n, i;

    printf("Enter size: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");

    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    bubbleSort(arr, n);

    printf("Sorted Array:\n");

    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
/*Best Case   : O(n)
Average Case: O(n²)
Worst Case  : O(n²)
Space       : O(1)*/