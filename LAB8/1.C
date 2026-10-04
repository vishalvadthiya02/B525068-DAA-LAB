

#include <stdio.h>
#include <limits.h>

int main() {
    int n, V;
    scanf("%d", &n);

    int c[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &c[i]);

    scanf("%d", &V);

    int dp[V + 1];
    dp[0] = 0;

    for (int i = 1; i <= V; i++)
        dp[i] = INT_MAX;

    for (int i = 1; i <= V; i++) {
        for (int j = 0; j < n; j++) {
            if (c[j] <= i && dp[i - c[j]] != INT_MAX)
                dp[i] = dp[i] < dp[i - c[j]] + 1
                        ? dp[i]
                        : dp[i - c[j]] + 1;
        }
    }

    printf("%d\n", dp[V] == INT_MAX ? -1 : dp[V]);

    return 0;
}