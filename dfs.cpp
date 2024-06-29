#include <iostream>
using namespace std;

#define MAX 10

void depth_first_search(int adj[][MAX], bool visited[], int start, int n) {
    cout << start << "\t"; // Print the current node
    visited[start] = true;

    for (int i = 0; i < n; ++i) {
        if (adj[start][i] == 1 && !visited[i]) {
            depth_first_search(adj, visited, i, n);
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

    cout << "DFS starting from vertex 0:\n";
    depth_first_search(adj, visited, 0, n);

    return 0;
}

