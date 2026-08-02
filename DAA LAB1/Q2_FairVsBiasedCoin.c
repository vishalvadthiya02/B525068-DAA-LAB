/*1. Read number of tosses n.
2. Initialize fairHead = 0 and biasedHead = 0.
3. Generate n random tosses for fair coin.
4. Count number of heads.
5. Generate n random tosses for biased coin.
6. Assume P(H)=0.7.
7. Count number of heads.
8. Compute probabilities.
9. Display results.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n, i;
    int fairHead = 0, biasedHead = 0;

    printf("Enter number of tosses: ");
    scanf("%d", &n);

    srand(time(NULL));

    for(i = 0; i < n; i++)
    {
        if(rand() % 2)
            fairHead++;
    }

    for(i = 0; i < n; i++)
    {
        if(rand() % 100 < 70)
            biasedHead++;
    }

    printf("\nFair Coin Probability = %.4f\n",
           (float)fairHead/n);

    printf("Biased Coin Probability = %.4f\n",
           (float)biasedHead/n);

    return 0;
}
/*Best Case   : O(n)
Average Case: O(n)
Worst Case  : O(n)
Space       : O(1)*/