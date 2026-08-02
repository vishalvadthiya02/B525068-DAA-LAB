/*1. Read n elements.
2. Compare every element with remaining elements.
3. If duplicate found:
      Print Duplicate Found.
4. Otherwise:
      Print All Elements Unique.*/
      #include <stdio.h>

int main()
{
    int n, i, j;
    int duplicate = 0;

    printf("Enter size: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");

    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(arr[i] == arr[j])
            {
                duplicate = 1;
                break;
            }
        }

        if(duplicate)
            break;
    }

    if(duplicate)
        printf("Duplicate Found\n");
    else
        printf("All Elements Are Unique\n");

    return 0;
}
/*Best Case   : O(1)
Average Case: O(n²)
Worst Case  : O(n²)

Space       : O(1)*/