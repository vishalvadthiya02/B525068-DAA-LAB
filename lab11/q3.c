
#include <stdio.h>
#define MAXV 1000
#define MAXE 10000

int head[MAXV], to[2 * MAXE], next[2 * MAXE];
int edgeCount = 0;

void addEdge(int u, int v) {
    to[edgeCount] = v;
    next[edgeCount] = head[u];
    head[u] = edgeCount++;
}

int main() {
    int n, m, k, R;

    // Initialize adjacency list
    for(int i = 0; i < MAXV; i++)
        head[i] = -1;

    printf("Enter number of vertices and edges: ");
    scanf("%d%d", &n, &m);

    printf("Enter undirected edges (u v):\n");

    for(int i = 0; i < m; i++) {
        int u, v;

        printf("Edge %d: ", i + 1);
        scanf("%d%d", &u, &v);

        addEdge(u, v);
        addEdge(v, u);
    }

    printf("Enter number of hubs and radius R: ");
    scanf("%d%d", &k, &R);

    int dist[MAXV], owner[MAXV];
    int q[MAXV];

    for(int i = 0; i < n; i++) {
        dist[i] = -1;
        owner[i] = -1;
    }

    int front = 0, rear = 0;

    // Insert hubs in increasing index order
    printf("Enter hub vertices in index order:\n");

    for(int i = 1; i <= k; i++) {
        int h;

        printf("Hub %d: ", i);
        scanf("%d", &h);

        dist[h] = 0;
        owner[h] = i;

        q[rear++] = h;
    }

    // Multi-source BFS
    while(front < rear) {

        int u = q[front++];

        for(int e = head[u]; e != -1; e = next[e]) {

            int v = to[e];

            if(dist[v] == -1) {

                dist[v] = dist[u] + 1;
                owner[v] = owner[u];

                q[rear++] = v;
            }
        }
    }

    printf("\nVertex\tOwner\tDistance\n");

    for(int i = 0; i < n; i++) {

        if(dist[i] == -1 || dist[i] > R)
            owner[i] = -1;

        printf("%d\t%d\t%d\n",
               i, owner[i], dist[i]);
    }

    return 0;
}