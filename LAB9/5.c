#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int *rating = malloc(n * sizeof(int));
    int *candy = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &rating[i]);
        candy[i] = 1;
    }

    for (int i = 1; i < n; i++)
        if (rating[i] > rating[i - 1])
            candy[i] = candy[i - 1] + 1;

    for (int i = n - 2; i >= 0; i--)
        if (rating[i] > rating[i + 1] &&
            candy[i] <= candy[i + 1])
            candy[i] = candy[i + 1] + 1;

    long long total = 0;

    for (int i = 0; i < n; i++)
        total += candy[i];

    printf("%lld\n", total);

    free(rating);
    free(candy);
    return 0;
}