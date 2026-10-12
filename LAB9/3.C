#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int d, f;
} Station;

int cmp(const void *a, const void *b) {
    return ((Station *)a)->d - ((Station *)b)->d;
}

int main() {
    int n, D, F;
    scanf("%d %d %d", &n, &D, &F);

    Station s[n + 1];

    for (int i = 0; i < n; i++)
        scanf("%d %d", &s[i].d, &s[i].f);

    qsort(s, n, sizeof(Station), cmp);
    s[n].d = D;
    s[n].f = 0;

    int fuel = F, prev = 0, stops = 0;

    for (int i = 0; i <= n; i++) {
        fuel -= s[i].d - prev;

        if (fuel < 0) {
            printf("-1\n");
            return 0;
        }

        if (i < n) {
            int nextDist = s[i + 1].d - s[i].d;

            if (fuel < nextDist) {
                fuel += s[i].f;
                stops++;
            }
        }

        prev = s[i].d;
    }

    printf("%d\n", stops);
    return 0;
}