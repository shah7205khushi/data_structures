#include<iostream>
using namespace std;

const int a = 5;
int queue[a];
int front = -1;
int rear = -1;

void enter_queue(int x)
{
    if (rear == a - 1)
    {
        cout << "overflow" << endl;
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
    }
    else
    {
        rear++;
        queue[rear] = x;
    }
}

void delete_queue()
{
    if (front == -1 && rear == -1)
    {
        cout << "empty queue.." << endl;
    }
    else if (front == rear)
    {
        cout << "deleted que:" << queue[front] << endl;
        front = rear = -1;
    }
    else
    {
        cout << "deleted que:" << queue[front] << endl;
        front++;
    }
}

void display()
{
    if (front == -1 && rear == -1)
    {
        cout << "empty queue.." << endl;
    }
    else {
        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << " ";
        }
        cout << endl;
    }

}

void peek()
{
    if (front == -1 && rear == -1)
    {
        cout << "empty..." << endl;
    }
    else
    {
        cout << "value of front: " << queue[front] << endl;
    }
}
int main()
{
    int data;
    char choice;

    cout << "enter data for the queue :: " << a << endl;
    for (int i = 0; i < a; i++)
    {
        cout << "enter element:" << (i + 1) << ":";
        cin >> data;
        enter_queue(data);

        cout << "do you want to enter more element?(y/n)";
        cin >> choice;
        if (choice != 'y' && choice != 'Y')
            break;
    }
    cout<<"display element :"<<endl;
    display();
    
    cout<<"peek the value is:"<<" ";
	peek();
	
	
    cout << "delete element..." << endl;
   
        delete_queue();
    
    cout<<"after deleted display element :"<<endl;
    display();
    
    cout<<"peek the value is:"<<" ";
	peek();
    return 0;
}

