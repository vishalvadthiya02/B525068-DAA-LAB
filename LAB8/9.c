
#include <stdio.h>
#include <limits.h>

void collatz(unsigned long long n) {
    unsigned long long count = 0;

    printf("%llu: ", n);

    while (n != 1) {
        printf("%llu ", n);

        if (n % 2 == 0) {
            n = n / 2;
        }
        else {
            if (n > (ULLONG_MAX - 1) / 3) {
                printf("OVERFLOW\n");
                return;
            }

            n = 3 * n + 1;
        }

        count++;
    }

    printf("1\nSteps = %llu\n", count);
}

int main() {
    unsigned long long a, b;

    scanf("%llu %llu", &a, &b);

    if (a > b) {
        unsigned long long temp = a;
        a = b;
        b = temp;
    }

    for (unsigned long long n = a; n <= b; n++) {
        collatz(n);

        if (n == ULLONG_MAX)
            break;
    }

    return 0;
}