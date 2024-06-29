#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Circular Queue class
class CircularQueue {
private:
    Node* rear;

public:
    CircularQueue() {
        rear =NULL;
    }

    // Function to check if the circular queue is empty
    bool isEmpty() {
        return rear == NULL;
    }

    // Function to enqueue an element into the circular queue
    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (isEmpty()) {
            rear = newNode;
            rear->next = rear; // Make it circular
        } else {
            newNode->next = rear->next;
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued: " << val << endl;
    }

    // Function to dequeue an element from the circular queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        Node* temp = rear->next;
        if (rear == rear->next) {
            rear = NULL;
        } else {
            rear->next = rear->next->next;
        }
        cout << "Dequeued: " << temp->data << endl;
        delete temp;
    }

    // Function to display the elements in the circular queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        Node* temp = rear->next;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != rear->next);
        cout << endl;
    }
};

int main() {
    CircularQueue cq;

    int choice, value;
    cout << "\n\n\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n" << endl;
    do {
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter the value to enqueue: ";
                cin >> value;
                cq.enqueue(value);
                break;
            case 2:
                cq.dequeue();
                break;
            case 3:
                cq.display();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter again." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}

