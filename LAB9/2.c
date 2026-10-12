#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char ch;
    int freq;
    struct Node *left, *right;
} Node;

Node *newNode(char ch, int freq) {
    Node *n = malloc(sizeof(Node));
    n->ch = ch;
    n->freq = freq;
    n->left = n->right = NULL;
    return n;
}

void sort(Node *a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i]->freq > a[j]->freq) {
                Node *t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
}

void generate(Node *root, char code[], int depth) {
    if (!root) return;

    if (!root->left && !root->right) {
        code[depth] = '\0';
        printf("%c: %s\n", root->ch,
               depth ? code : "0");
        return;
    }

    code[depth] = '0';
    generate(root->left, code, depth + 1);

    code[depth] = '1';
    generate(root->right, code, depth + 1);
}

int main() {
    int n;
    scanf("%d", &n);

    Node **a = malloc(n * sizeof(Node *));
    for (int i = 0; i < n; i++) {
        char ch;
        int f;
        scanf(" %c %d", &ch, &f);
        a[i] = newNode(ch, f);
    }

    int size = n;
    while (size > 1) {
        sort(a, size);
        Node *left = a[0];
        Node *right = a[1];

        a[0] = newNode('$', left->freq + right->freq);
        a[0]->left = left;
        a[0]->right = right;

        for (int i = 1; i < size - 1; i++)
            a[i] = a[i + 1];

        size--;
    }

    char code[1000];
    generate(a[0], code, 0);
    free(a);
    return 0;
}