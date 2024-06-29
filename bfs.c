#include <stdio.h>
#define MAX 10

void breadth_first_search(int adj[][MAX], int visited[], int start, int n) {
    int queue[MAX], rear = -1, front = -1, i;
    queue[++rear] = start;
    visited[start] = 1;

    while (rear != front) {
        start = queue[++front];
        printf("%c \t", start + 'A');

        for (i = 0; i < n; i++) {
            if (adj[start][i] == 1 && visited[i] == 0) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int visited[MAX] = {0};
    int adj[MAX][MAX], i, j, n;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    if (n > MAX) {
        printf("Number of vertices should be less than or equal to %d\n", MAX);
        return 1;

    }

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("BFS starting from vertex A:\n");
    breadth_first_search(adj, visited, 0, n);

    return 0;
}

