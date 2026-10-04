
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[n], dp[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        dp[i] = 1;
    }

    int ans = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
        }

        if (ans < dp[i])
            ans = dp[i];
    }

    printf("%d\n", ans);

    return 0;
}