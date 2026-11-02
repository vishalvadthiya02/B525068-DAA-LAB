
#include <stdio.h>
#define MAXV 1000
#define MAXE 10000
#define MAXQ (4 * MAXE + 100)
#define INF 999999

int head[MAXV], to[2 * MAXE];
int wt[2 * MAXE], next[2 * MAXE];
int cnt = 0;

// Circular deque
int dq[MAXQ], dd[MAXQ];
int front = 0, rear = 0, size = 0;

void addEdge(int u, int v, int w) {
    to[cnt] = v;
    wt[cnt] = w;
    next[cnt] = head[u];
    head[u] = cnt++;
}

void pushFront(int state, int d) {
    front = (front - 1 + MAXQ) % MAXQ;
    dq[front] = state;
    dd[front] = d;
    size++;
}

void pushBack(int state, int d) {
    dq[rear] = state;
    dd[rear] = d;
    rear = (rear + 1) % MAXQ;
    size++;
}

void popFront(int *state, int *d) {
    *state = dq[front];
    *d = dd[front];

    front = (front + 1) % MAXQ;
    size--;
}

int main() {
    int n, m, s, C;

    for(int i = 0; i < MAXV; i++)
        head[i] = -1;

    printf("Enter number of vertices and edges: ");
    scanf("%d%d", &n, &m);

    printf("Enter source vertex and penalty C: ");
    scanf("%d%d", &s, &C);

    printf("Enter directed edges (u v weight):\n");

    for(int i = 0; i < m; i++) {
        int u, v, w;

        printf("Edge %d: ", i + 1);
        scanf("%d%d%d", &u, &v, &w);

        addEdge(u, v, w);
    }

    int dist[MAXV][2];

    for(int i = 0; i < n; i++) {
        dist[i][0] = INF;
        dist[i][1] = INF;
    }

    // Source starts with even parity
    dist[s][0] = 0;

    pushFront(2 * s, 0);

    // 0-1 BFS
    while(size > 0) {

        int state, d;
        popFront(&state, &d);

        int u = state / 2;
        int p = state % 2;

        if(d != dist[u][p])
            continue;

        for(int e = head[u]; e != -1; e = next[e]) {

            int v = to[e];
            int w = wt[e];

            int np = p ^ w;
            int nd = d + w;

            if(nd < dist[v][np]) {

                dist[v][np] = nd;

                if(w == 0)
                    pushFront(2 * v + np, nd);
                else
                    pushBack(2 * v + np, nd);
            }
        }
    }

    printf("\nMinimum effective costs:\n");

    for(int i = 0; i < n; i++) {

        int ans = dist[i][0];

        if(dist[i][1] != INF &&
           dist[i][1] + C < ans)
            ans = dist[i][1] + C;

        if(ans == INF)
            printf("Vertex %d: Unreachable\n", i);
        else
            printf("Vertex %d: %d\n", i, ans);
    }

    return 0;
}