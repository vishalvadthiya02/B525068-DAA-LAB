#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 105

long long w[MAX], prefix[MAX];
long long dp[MAX][MAX];
int split[MAX][MAX];

void printTree(int l, int r) {
    if (l == r) {
        printf("%d", l);
        return;
    }

    printf("(");
    printTree(l, split[l][r]);
    printf(",");
    printTree(split[l][r] + 1, r);
    printf(")");
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%lld", &w[i]);
        prefix[i] = prefix[i - 1] + w[i];
        dp[i][i] = 0;
    }

    for (int len = 2; len <= n; len++) {
        for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            dp[l][r] = LLONG_MAX;

            long long sum = prefix[r] - prefix[l - 1];

            for (int k = l; k < r; k++) {
                long long cost =
                    dp[l][k] + dp[k + 1][r] + sum;

                if (cost < dp[l][r]) {
                    dp[l][r] = cost;
                    split[l][r] = k;
                }
            }
        }
    }

    printf("Minimum weighted path length: %lld\n",
           dp[1][n]);

    printf("Alphabetic tree: ");
    printTree(1, n);
    printf("\n");

    return 0;
}