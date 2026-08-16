#include <stdio.h>

// Function to find defective coin
int findDefective(int coins[], int low, int high)
{
    if (low == high)
        return low;

    int n = high - low + 1;
    int mid = low + n / 2;

    int leftSum = 0, rightSum = 0;

    // Even number of coins
    if (n % 2 == 0)
    {
        for (int i = low; i < mid; i++)
            leftSum += coins[i];

        for (int i = mid; i <= high; i++)
            rightSum += coins[i];

        if (leftSum < rightSum)
            return findDefective(coins, low, mid - 1);
        else
            return findDefective(coins, mid, high);
    }
    else // Odd number of coins
    {
        for (int i = low; i < mid; i++)
            leftSum += coins[i];

        for (int i = mid + 1; i <= high; i++)
            rightSum += coins[i];

        if (leftSum == rightSum)
            return mid;   // middle coin is defective
        else if (leftSum < rightSum)
            return findDefective(coins, low, mid - 1);
        else
            return findDefective(coins, mid + 1, high);
    }
}

int main()
{
    int n;

    printf("Enter number of coins: ");
    scanf("%d", &n);

    int coins[n];

    printf("Enter weights of coins:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &coins[i]);

    int index = findDefective(coins, 0, n - 1);

    printf("\nDefective coin found at position %d", index + 1);
    printf("\nWeight of defective coin = %d\n", coins[index]);

    return 0;
}