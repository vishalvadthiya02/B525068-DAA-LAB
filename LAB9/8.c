#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Meeting;

int cmpStart(const void *a, const void *b) {
    return ((Meeting *)a)->start -
           ((Meeting *)b)->start;
}

void push(int h[], int *n, int x) {
    int i = ++(*n);

    while (i > 1 && h[i / 2] > x) {
        h[i] = h[i / 2];
        i /= 2;
    }

    h[i] = x;
}

int pop(int h[], int *n) {
    int result = h[1];
    int x = h[(*n)--], i = 1, child;

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
    int n;
    scanf("%d", &n);

    Meeting *m = malloc(n * sizeof(Meeting));
    int *heap = malloc((n + 1) * sizeof(int));
    int size = 0, rooms = 0;

    for (int i = 0; i < n; i++)
        scanf("%d %d", &m[i].start, &m[i].end);

    qsort(m, n, sizeof(Meeting), cmpStart);

    for (int i = 0; i < n; i++) {
        while (size > 0 && heap[1] <= m[i].start)
            pop(heap, &size);

        push(heap, &size, m[i].end);

        if (size > rooms)
            rooms = size;
    }

    printf("%d\n", rooms);

    free(m);
    free(heap);
    return 0;
}