/*1. Set low = 0 and high = n-1.
2. Repeat until low <= high.
3. Find mid.
4. If arr[mid] = 1:
       Save index.
       Search left half.
5. Else:
       Search right half.
6. Return index.*/
#include <stdio.h>

int findTransition(int arr[], int n)
{
    int low = 0;
    int high = n - 1;
    int ans = -1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] == 1)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
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

    printf("Transition Point = %d\n",
           findTransition(arr, n));

    return 0;
}
/*Best Case   : O(1)
Average Case: O(log n)
Worst Case  : O(log n)

Space       : O(1)*/