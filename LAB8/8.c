
#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    scanf("%d", &n);

    int p[n + 1], q[n + 1];

    for (int i = 1; i <= n; i++)
        scanf("%d", &p[i]);

    for (int i = 0; i <= n; i++)
        scanf("%d", &q[i]);

    int cost[n + 2][n + 1];
    int weight[n + 2][n + 1];

    for (int i = 1; i <= n + 1; i++) {
        cost[i][i - 1] = q[i - 1];
        weight[i][i - 1] = q[i - 1];
    }

    for (int length = 1; length <= n; length++) {
        for (int i = 1; i <= n - length + 1; i++) {

            int j = i + length - 1;

            cost[i][j] = INT_MAX;

            weight[i][j] = weight[i][j - 1] + p[j] + q[j];

            for (int r = i; r <= j; r++) {
                int current = cost[i][r - 1] +
                              cost[r + 1][j] +
                              weight[i][j];

                if (current < cost[i][j])
                    cost[i][j] = current;
            }
        }
    }

    printf("Minimum Expected Cost = %d\n", cost[1][n]);

    return 0;
}