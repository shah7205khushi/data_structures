//stack with linklist

#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
	
	node(int t_data)
	{
		data = t_data;
		next = NULL;
	}
};

class stack
{
	struct node *head;
	public:
		
		stack()
		{
			head = NULL;
		}	
		
		void push(int t_data)
		{
			struct node *newnode = new node(t_data);
			if(head == NULL)
			{
				head = newnode;
			}
			
			else
			{
				newnode->next = head;
				head = newnode;
				
			}
		}
		
		void pop()
		{
			if(head == NULL )
			{
				cout<<"stack is empty";
			}
			else
			{
				struct node *temp =head;
				head = head->next;
				delete temp; 
			}
		}
		
		void peek()
		{
			if(head == NULL)
			{
				cout<<"stack is empty"<<endl;
			}
			else
			{
				cout<<"the top element of stack is :"<<head->data<<endl;
			}
		}
		
		void isempty()
		{
			if(head==NULL)
			{
				cout<<"stack is empty"<<endl;
			}
			else
			{
				cout<<"stack is not empty"<<endl;
			}
		}
		
		void display()
		{
			if(head == NULL)
			{
				cout<<"stack is empty"<<endl;
			}
			else
			{
				struct node *current =head;
				cout<<"-------------------------"<<endl;
				while(current != NULL)
				{
					
					cout<<current->data;
					cout<<endl;
					current = current->next;
					

				}
				cout<<"-------------------------"<<endl;
				cout<<endl;
			}
		}
		
		
};

int main()
{
	stack s;
	int choise,t_data;
	do
	{
		cout<<"1.push"<<endl;
		cout<<"2.pop"<<endl;
		cout<<"3.display"<<endl;
		cout<<"4.peek"<<endl;
		cout<<"5.isempty"<<endl;
		cout<<endl;
		
		cout<<"enter choice"<<endl;
		cin>>choise;
		
		switch(choise)
		{
			case 1:
				cout<<"enter the data"<<endl;
				cin>>t_data;
				s.push(t_data);
				break;
			
			case 2:
				s.pop();
				break;
				
			case 3:
				s.display();
				break;	
				
			case 4:
				s.peek();
				break;
				
			case 5:
				s.isempty();
				break;				
		}
		
	}while(choise<=5);
}
