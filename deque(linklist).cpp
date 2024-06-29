#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) 
	{
		data = val; 
		next = NULL; 
		prev = NULL;
	 } 
};

// Deque class
class Deque {
private:
    Node* front; 
    Node* rear;  

public:
    // Constructor to initialize an empty deque
    Deque() {
        front = NULL;
        rear = NULL;
    }

    // Check if the deque is empty
    bool isEmpty() {
        return front == NULL;
    }

    // Insert an element at the front
    void insertFront(int val) {
        Node* newNode = new Node(val);
        
        if (isEmpty()) {
            front = rear = newNode;
        } 
		else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }

    // Insert an element at the rear
    void insertRear(int val) {
        Node* newNode = new Node(val);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Delete an element from the front
    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        } else {
            front->prev = NULL;
        }
        delete temp;
    }

    // Delete an element from the rear
    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }
        Node* temp = rear;
        rear = rear->prev;
        if (rear == NULL) {
            front = NULL;
        } else {
            rear->next = NULL;
        }
        delete temp;
    }

    // Get the front element
    int getFront() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return -1;
        }
        return front->data;
    }

    // Get the rear element
    int getRear() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return -1;
        }
        return rear->data;
    }

    // Display the elements of the deque
    void display() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Deque dq;
    int choice, value;

    do {
        cout << "\n********* Menu *********\n";
        cout << "1. Insert at Front\n";
        cout << "2. Insert at Rear\n";
        cout << "3. Delete from Front\n";
        cout << "4. Delete from Rear\n";
        cout << "5. Get Front\n";
        cout << "6. Get Rear\n";
        cout << "7. Display\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at front: ";
                cin >> value;
                dq.insertFront(value);
                break;
            case 2:
                cout << "Enter value to insert at rear: ";
                cin >> value;
                dq.insertRear(value);
                break;
            case 3:
                dq.deleteFront();
                break;
            case 4:
                dq.deleteRear();
                break;
            case 5:
                cout << "Front element is: " << dq.getFront() << endl;
                break;
            case 6:
                cout << "Rear element is: " << dq.getRear() << endl;
                break;
            case 7:
                dq.display();
                break;
            case 8:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 8);

    return 0;
}

