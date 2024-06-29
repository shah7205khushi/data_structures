#include <iostream>
using namespace std;

#define MAX 10

void breadth_first_search(int adj[][MAX], bool visited[], int start, int n) {
    int queue[MAX];
    int front = 0, rear = 0;

    queue[rear++] = start;
    visited[start] = true;

    while (front < rear) {
        int current = queue[front++];
        cout << current << "\t"; // Print the current node

        for (int i = 0; i < n; ++i) {
            if (adj[current][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = true;
            }
        }
    }
}

int main() {
    bool visited[MAX] = {0};
    int adj[MAX][MAX], n;

    cout << "Enter the number of vertices: ";
    cin >> n;

    if (n > MAX) {
        cout << "Number of vertices should be less than or equal to " << MAX << endl;
        return 1;
    }

    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> adj[i][j];
        }
    }

    cout << "BFS starting from vertex 0:\n";
    breadth_first_search(adj, visited, 0, n);

    return 0;
}

