#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int index;
} Node;

void swap(Node *a, Node *b) {
    Node t = *a;
    *a = *b;
    *b = t;
}

void push(Node h[], int *n, Node x) {
    int i = ++(*n);

    while (i > 1 && h[i / 2].value < x.value) {
        h[i] = h[i / 2];
        i /= 2;
    }

    h[i] = x;
}

Node pop(Node h[], int *n) {
    Node result = h[1];
    Node x = h[(*n)--];
    int i = 1, child;

    while (i * 2 <= *n) {
        child = i * 2;

        if (child + 1 <= *n &&
            h[child + 1].value > h[child].value)
            child++;

        if (h[child].value <= x.value) break;

        h[i] = h[child];
        i = child;
    }

    h[i] = x;
    return result;
}

int main() {
    int n;
    scanf("%d", &n);

    Node *h = malloc((n + 2) * sizeof(Node));
    int size = 0, minimum = 1000000000;

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);

        if (x % 2) x *= 2;

        if (x < minimum) minimum = x;

        push(h, &size, (Node){x, i});
    }

    int answer = h[1].value - minimum;

    while (size > 0) {
        Node maximum = pop(h, &size);
        int x = maximum.value;

        if (x - minimum < answer)
            answer = x - minimum;

        if (x % 2 != 0)
            break;

        x /= 2;

        if (x < minimum) minimum = x;

        push(h, &size, (Node){x, maximum.index});
    }

    printf("%d\n", answer);
    free(h);
    return 0;
}