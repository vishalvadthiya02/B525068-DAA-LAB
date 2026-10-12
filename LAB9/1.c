#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double v, w, lambda, density;
} Item;

int cmp(const void *a, const void *b) {
    double x = ((Item *)a)->density;
    double y = ((Item *)b)->density;
    return (x < y) - (x > y);
}

int main() {
    int n;
    double W, time = 0, total = 0;

    scanf("%d %lf", &n, &W);

    Item *a = malloc(n * sizeof(Item));

    for (int i = 0; i < n; i++) {
        scanf("%lf %lf %lf",
              &a[i].v, &a[i].w, &a[i].lambda);
        a[i].density = a[i].v / a[i].w;
    }

    qsort(a, n, sizeof(Item), cmp);

    for (int i = 0; i < n && W > 0; i++) {
        double density = a[i].v / a[i].w
                         - a[i].lambda * time;

        if (density <= 0)
            continue;

        double take = a[i].w < W ? a[i].w : W;

        total += take * density;
        W -= take;
        time += take;
    }

    printf("Total value: %.2f\n", total);

    free(a);
    return 0;
}