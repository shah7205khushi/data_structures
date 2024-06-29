// types of linked list (data structure in c++)
// 1> singly linked list
// 2> doubly linked list
// 3> circular singly linked list
// 4> circular doubly linked list

#include<iostream>
using namespace std;

struct node{
	int data;
	struct node *next;
	node(int t_data)
	{
		data = t_data;
		next = NULL;
	}
};
class lili{
	struct node *head;
	public:
		lili()
		{
			head = NULL;
		}
		
		//DISPLAY FUNCTION 
		void display(void)
		{
			if(head == NULL)
			{
				cout<<"\nlist is empty...\n";
			}
			else
			{
				struct node *current = head;
				while(current!= NULL)
				{
					cout<<current->data << " -> ";
					current = current->next;
				}
				cout<<endl;	
			}
		}
		
		//INSERT AT START FUNCTION 
		void insert_at_start(int t_data)
		{
			struct node *newnode = new node(t_data);
			if(head == NULL)
			{
				head = newnode;
			}
			else 
			{
				newnode->next = head ;
				head = newnode;
			}
		}
		
		//
		void insert_at_middle(int t_data,int pos)
		{
			
			struct node *newnode = new node(t_data);
			
			if(head == NULL)
			{
				cout<<"\nlist is empty...\n";
			}
			else 
			{
				struct node *current = head;
				int count = 1;
				while(current->next != NULL && count < pos-1)
				{
					current = current->next;
					count++;
				}
				newnode->next = current->next;				
				current->next = newnode;
			}
		}
		
		//INSERT AT END FUNCTION
		void insert_at_end(int t_data)
		{
			struct node *newnode = new node(t_data);
			if(head == NULL)
			{
				head = newnode;
			}
			else 
			{
				struct node *current = head;
				while(current->next != NULL)
				{
					current = current->next;
				}
				current->next = newnode;
			}
		}
		// SORTING OF LINKED LIST 
		void sort(void)
		{
			if (head == NULL) {
		        cout << "\nList is empty\n";
		        return;
    		}
			struct node *ptr1= head,*ptr2 = head;
			while(ptr1->next != NULL)
			{
				ptr2 = ptr1->next;
				while(ptr2 != NULL)
				{
					if(ptr1->data > ptr2->data)
					{
						int temp = ptr1->data;
						ptr1->data= ptr2->data;
						ptr2->data = temp;
					}
					ptr2 = ptr2->next;
				}
				ptr1 = ptr1->next;
			}
		}
		
		
		
		void reverse(void)
		{
			if(head == NULL || head->next == NULL)
			{
				cout << "\nALREADY REVERSED\n";
		        return;
			}
			else
			{
				struct node *current = head;
				struct node *prev = NULL;
				struct node *forward;
		
				while(current != NULL)
				{
					forward = current->next;
					current->next = prev;
					prev = current;
					current = forward;
				}
				head = prev;
				
			}
		}
};


int main()
{
	lili ll;
	int op,pos,t_data;
	
	do{
		cout<<"______________________________";
		cout<<"\nEnter option : ";
		cin>> op;
		switch(op)
		{
			case 0:
				ll.display();
				break;
			case 1:
				cout<<"Enter data : ";
				cin >> t_data;
				ll.insert_at_start(t_data);
				break;
			case 2:
				cout<<"Enter data : ";
				cin >> t_data;
				cout<<"Enter pos : ";
				cin >> pos;
				ll.insert_at_middle(t_data,pos);
				break;
			case 3:
				cout<<"Enter data : ";
				cin >> t_data;
				ll.insert_at_end(t_data);
				break;
			case 4:
				ll.reverse();
				break;
			case 5:
				ll.sort();
				break;
			case 99:
				cout<<"\n....EXIT....\n";
				break;
		}
		
		cout<<"______________________________";
	}while(op != 99);
	
	return 0;
}

