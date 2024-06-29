#include<iostream>

using namespace std;

class stack {
    int *a;
    int n;
    int top;

public:
    stack() {
        cout << "Enter the size of the array:\nSize: ";
        cin >> n;
        a = new int[n];
        top = -1;
    }

    // Insert an element in stack
    void push(int x) {
        if (isFull()) {
            cout << "Stack overflow." << endl;
        } else {
            top++;
            a[top] = x;
            cout << "Inserted: " << a[top] << endl;
        }
    }

    // Returns the top element in stack (peek)
    void Top() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Top element is: " << a[top] << endl;
        }
    }

    // Remove the element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "No elements in the stack." << endl;
        } else {
            cout << "Removed: " << a[top] << endl;
            top--;
        }
    }

    // Check if stack is full
    bool isFull() {
        return top == (n - 1);
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Display the elements in the stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Stack elements: ";
            for (int i = top; i >= 0; i--) {
                cout << a[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    stack st;

    int ch, x;
    cout << "\n\n\n1. Push the element in the stack\n2. Top element of the stack.\n3. Pop the element.\n4. Display the stack.\n99. Exit" << endl;
    do {
        cout << "\nEnter the choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter the element: ";
                cin >> x;
                st.push(x);
                break;
            case 2:
                st.Top();
                break;
            case 3:
                st.pop();
                break;
            case 4:
                st.display();
                break;
            
            default:
                cout << "Wrong choice." << endl;
                break;
        }

    } while (ch != 99);

    return 0;
}

