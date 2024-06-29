#include <iostream>
using namespace std;

#define MAX 10

class Stack {
private:
    int items[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isFull() {
        return top == MAX - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int element) {
        if (isFull()) {
            cout << "Stack is full\n";
            return;
        }
        items[++top] = element;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return items[top--];
    }
};

void depth_first_search(int adj[][MAX], bool visited[], int start, int n) {
    Stack s;
    s.push(start);
    visited[start] = true;

    while (!s.isEmpty()) {
        int current = s.pop();
        cout << char(current + 'A') << "\t"; // Print the corresponding character


        for (int i = n - 1; i >= 0; --i) { // Start from end to ensure we explore smaller indices first
            if (adj[current][i] == 1 && !visited[i]) {
                s.push(i);
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

    cout << "DFS starting from vertex 0:\n";
    depth_first_search(adj, visited, 0, n);

    return 0;
}

/*
Enter the number of vertices: 5
Enter the adjacency matrix:
0 1 0 1 0
1 0 1 0 1
0 0 1 1 0
1 1 0 0 1
1 0 0 1 0

DFS starting from vertex 0:
0	1	2	4	3


Enter the number of vertices: 5
Enter the adjacency matrix:
0 1 1 1 0
1 0 0 0 1
1 0 0 1 0
1 0 1 0 1
0 1 0 1 0
DFS starting from vertex 0:
A       B       E       C       D


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
DFS starting from vertex 0:
A       B       E       C       F       G       H       D

*/

