#include<iostream>
using namespace std;


// stack using linklist

struct node {
	int data;
	struct node *next;
	
	node (int l_data){
		data =l_data;
		next = NULL;
	}
};


class stack{
public :
	struct node *head;
	
	stack()
	{
		head=NULL;
	}
	
	
	bool isempty() {
    if (head == NULL) {
      return true;
    } else {
      return false;
    }
  }
	
	
	void push(int x)
	{
	struct node *newnode = new node(x);		
		if (head == NULL)
		{
			head = newnode;
			cout<<"element is pushed to stack. : "<<newnode->data;
		}
		else
		{
			newnode->next =head;
			head =newnode;
			cout<<"element is pushed to stack. : "<<newnode->data;
		}
	}
	
	
	void pop()
	{
		if(isempty())
		{
			cout<<"no element to pop .";
		}
		else
		{
			struct node * temp;
			temp = head ;
			head = head->next;
			
			cout<<"removed : "<<temp->data;
			delete temp;
		}
		
	}
	
void peek() {
        if (isempty()) {
            cout << "Stack is Empty" << endl;
        } else {
            cout << "Top Element: " << head->data << endl;
        }
    }
	
	
	void display() {
        if (isempty()) {
            cout << "Stack is Empty" << endl;
        } else {
            cout << "Stack elements: ";
            struct node *temp = head;
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
	
	
};


int main()
{
	stack s;
	
	int ch,x;
		cout<<"\n\n\n1. psuh the element in the stack\n2.pop element from the stack.\n3.isempty.\n4.top element\n5.display stack";
	do{
		cout<<"\n\nenter the choise";
		cin>>ch;
		
		switch(ch)
		{
			
			case 1:
				cout<<"enter the element";
				cin>>x;
				s.push(x);
				break;
				
			case 2:
				s.pop();
				break;
				
			case 3:
      			if (s.isempty())
        		cout << "Stack is Empty" << endl;
      			else
        		cout << "Stack is not Empty" << endl;
      			break;
      			
      		case 4:
			  	s.peek();
				break;	
				  	
			case 5:
			  	s.display();
				break;	
				  		  	
			default :
				cout<<"wrong choise :";
				break;
				
		}
			
	}
	while(ch != 99);
	
}



