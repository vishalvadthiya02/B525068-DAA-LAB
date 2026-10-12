#include <stdio.h>
#include <stdlib.h>

void push(long long h[], int *n, long long x) {
    int i = ++(*n);

    while (i > 1 && h[i / 2] > x) {
        h[i] = h[i / 2];
        i /= 2;
    }

    h[i] = x;
}

long long pop(long long h[], int *n) {
    long long result = h[1];
    long long x = h[(*n)--];
    int i = 1, child;

    while (i * 2 <= *n) {
        child = i * 2;

        if (child + 1 <= *n &&
            h[child + 1] < h[child])
            child++;

        if (h[child] >= x) break;

        h[i] = h[child];
        i = child;
    }

    h[i] = x;
    return result;
}

int main() {
    int n, size = 0;
    scanf("%d", &n);

    long long *h = malloc((n + 2) * sizeof(long long));

    for (int i = 0; i < n; i++) {
        long long x;
        scanf("%lld", &x);
        push(h, &size, x);
    }

    long long cost = 0;

    while (size > 1) {
        long long x = pop(h, &size);
        long long y = pop(h, &size);
        cost += x + y;
        push(h, &size, x + y);
    }

    printf("%lld\n", cost);
    free(h);
    return 0;
}