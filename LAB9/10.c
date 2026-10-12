#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 100
#define L 1005

int overlap(const char *a, const char *b) {
    int la = strlen(a);
    int lb = strlen(b);
    int max = la < lb ? la : lb;

    for (int k = max; k > 0; k--) {
        if (strncmp(a + la - k, b, k) == 0)
            return k;
    }

    return 0;
}

int main() {
    int n;
    char s[N][L];

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%1004s", s[i]);

    /* Remove strings contained in another string. */
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && s[i][0] != '\0' &&
                strstr(s[j], s[i]) != NULL) {
                s[i][0] = '\0';
                break;
            }
        }
    }

    while (1) {
        int bi = -1, bj = -1, best = -1;

        for (int i = 0; i < n; i++) {
            if (s[i][0] == '\0') continue;

            for (int j = 0; j < n; j++) {
                if (i == j || s[j][0] == '\0')
                    continue;

                int ov = overlap(s[i], s[j]);

                if (ov > best) {
                    best = ov;
                    bi = i;
                    bj = j;
                }
            }
        }

        if (bi == -1)
            break;

        int len = strlen(s[bi]);
        strncat(s[bi], s[bj] + best,
                L - strlen(s[bi]) - 1);

        s[bj][0] = '\0';
    }

    for (int i = 0; i < n; i++) {
        if (s[i][0] != '\0') {
            printf("Greedy superstring: %s\n", s[i]);
            break;
        }
    }

    return 0;
}