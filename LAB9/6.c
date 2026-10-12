#include <stdio.h>
#include <string.h>

int main() {
    char s[10005], result[10005];
    int k, freq[256] = {0};
    int last[256];

    scanf("%10000s %d", s, &k);

    int n = strlen(s);

    if (k <= 1) {
        printf("%s\n", s);
        return 0;
    }

    for (int i = 0; i < 256; i++)
        last[i] = -k;

    for (int i = 0; i < n; i++)
        freq[(unsigned char)s[i]]++;

    for (int pos = 0; pos < n; pos++) {
        int best = -1;

        for (int c = 0; c < 256; c++) {
            if (freq[c] > 0 &&
                pos - last[c] >= k &&
                (best == -1 || freq[c] > freq[best]))
                best = c;
        }

        if (best == -1) {
            printf("\n");
            return 0;
        }

        result[pos] = (char)best;
        freq[best]--;
        last[best] = pos;
    }

    result[n] = '\0';
    printf("%s\n", result);
    return 0;
}