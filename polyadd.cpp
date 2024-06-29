#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int coeff, power;
    Node* next;

    // Constructor of Node
    Node(int coeff, int power)
    {
        this->coeff = coeff;
        this->power = power;
        this->next = NULL;
    }
    
    
};

// Function to add polynomials

void addPolynomials(Node* head1, Node* head2)
{
    while (head1 != NULL && head2 != NULL) {
        if (head1->power == head2->power) {
            cout << " " << head1->coeff + head2->coeff << "x^" << head1->power << " +";
            head1 = head1->next;
            head2 = head2->next;
        }
        else if (head1->power > head2->power) {
            cout << " " << head1->coeff << "x^" << head1->power << " +";
            head1 = head1->next;
        }
        else {
            cout << " " << head2->coeff << "x^" << head2->power << " +";
            head2 = head2->next;
        }
    }
    
    // Print remaining terms of the longer polynomial if any
    while (head1 != NULL) {
        cout << " " << head1->coeff << "x^" << head1->power << " +";
        head1 = head1->next;
    }
    while (head2 != NULL) {
        cout << " " << head2->coeff << "x^" << head2->power << " +";
        head2 = head2->next;
    }
    
    // Remove the trailing '+'
    cout << "\b ";
}

// Function to insert a term into the polynomial
void insert(Node* head, int coeff, int power)
{
    Node* new_node = new Node(coeff, power);
    while (head->next != NULL) {
        head = head->next;
    }
    head->next = new_node;
}

// Function to print the polynomial
void printList(Node* head)
{
    cout << "Linked List" << endl;
    while (head != NULL) {
        cout << " " << head->coeff << "x^" << head->power<<"+";
        head = head->next;
    }
}

int main()
{
    int num, coeff, power;
    Node* head1 = NULL;
    Node* head2 = NULL;

    cout << "Enter the number of terms in first polynomial: ";
    cin >> num;
    cout << "Enter the terms (coefficient power):" << endl;
    for (int i = 0; i < num; ++i) {
        cin >> coeff >> power;
        if (head1 == NULL) {
            head1 = new Node(coeff, power);
        } else {
            insert(head1, coeff, power);
        }
    }

    cout << "Enter the number of terms in second polynomial: ";
    cin >> num;
    cout << "Enter the terms (coefficient power):" << endl;
    for (int i = 0; i < num; ++i) {
        cin >> coeff >> power;
        if (head2 == NULL) {
            head2 = new Node(coeff, power);
        } else {
            insert(head2, coeff, power);
        }
    }

    cout << "First Polynomial:" << endl;
    printList(head1);
    cout << endl;

    cout << "Second Polynomial:" << endl;
    printList(head2);
    cout << endl;

    cout << "Addition:" << endl;
    addPolynomials(head1, head2);

    return 0;
}

