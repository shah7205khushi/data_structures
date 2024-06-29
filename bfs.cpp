#include <iostream>
using namespace std;

#define MAX 10

class Queue {
private:
    int items[MAX];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return rear == MAX - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(int element) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        if (front == -1) front = 0;
        items[++rear] = element;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return items[front++];
    }
};

void breadth_first_search(int adj[][MAX], bool visited[], int start, int n) {
    Queue q;
    q.enqueue(start);
    visited[start] = true;

    while (!q.isEmpty()) {
        start = q.dequeue();
        cout << char(start + 'A') << "\t";


        for (int i = 0; i < n; ++i) {
            if (adj[start][i] == 1 && !visited[i]) {
                q.enqueue(i);
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


/*

Enter the number of vertices: 5
Enter the adjacency matrix:
1 0 1 0 1
0 1 0 1 0
1 1 0 0 1
0 0 1 1 0
1 1 0 1 0
BFS starting from vertex 0:
0       2       4       1       3


Enter the number of vertices: 5
Enter the adjacency matrix:
0 1 1 1 0
1 0 0 0 1
1 0 0 1 0
1 0 1 0 1
0 1 0 1 0
BFS starting from vertex 0:
A       B       C       D       E

Enter the number of vertices: 8
Enter the adjacency matrix:
0 1 0 1 0 0 0 0
0 0 0 0 1 0 0 0
0 1 0 0 0 1 0 0
0 0 1 0 0 1 0 0
0 0 1 0 0 0 0 0
0 0 0 0 0 0 1 1
0 0 0 0 1 0 0 1
0 1 0 0 0 0 0 0
BFS starting from vertex 0:
A       B       D       E       C       F       G       H=]

*/

