
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int p[n + 1];

    for (int i = 1; i <= n; i++)
        scanf("%d", &p[i]);

    int dp[n + 1], cut[n + 1];

    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        dp[i] = p[i];
        cut[i] = i;

        for (int j = 1; j < i; j++) {
            if (dp[i] < p[j] + dp[i - j]) {
                dp[i] = p[j] + dp[i - j];
                cut[i] = j;
            }
        }
    }

    printf("Maximum Revenue = %d\n", dp[n]);
    printf("Pieces: ");

    int length = n;

    while (length > 0) {
        printf("%d ", cut[length]);
        length -= cut[length];
    }

    printf("\n");

    return 0;
}