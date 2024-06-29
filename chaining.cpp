#include <iostream>
using namespace std;

// Node structure to store the elements in the hash table
class Node {
public:
    int key;
    Node* next;

    Node(int k) {
        key = k;
        next = NULL;
    }
};

// HashTable class to manage the array of slots
class HashTable {
    Node** table; 
    int size; 

public:
	
    // Constructor to initialize the hash table
    HashTable(int s) {
        size = s;
        table = new Node*[size];
        for (int i = 0; i < size; i++)
            table[i] = NULL;
    }
   
    // Hash function to compute the index for a given key
    int hashFunction(int x) {
        return (x % size);
    }

    // Function to insert a key into the hash table
    void insertItem(int key) {
        int index = hashFunction(key);
        Node* newNode = new Node(key);
        if (table[index] == NULL) {
            table[index] = newNode;
        } else {
            Node* temp = table[index];
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    // Function to display the hash table
    void displayHash() {
        for (int i = 0; i < size; i++) {
            cout << i;
            Node* temp = table[i];
            while (temp != NULL) {
                cout << " --> " << temp->key;
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

// Main function to demonstrate the hash table operations
int main() {
    int tableSize, option, key;

    cout << "Enter the size of the hash table: ";
    cin >> tableSize;

    HashTable h(tableSize);

    do {
        cout << "\n_________________________________\n";
        cout << "\n1. Insert";
        cout << "\n2. Display Hash Table";
        cout << "\n99. Exit";
        cout << "\nEnter your choice: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "\nEnter the key to insert: ";
                cin >> key;
                h.insertItem(key);
                break;
            case 2:
                h.displayHash();
                break;
            case 99:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid option. Please try again.\n";
        }
    } while (option != 99);

    return 0;
}

