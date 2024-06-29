#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *prev;
	struct node *next;
	
	 node(int t_data)
	{
		data = t_data;
		next = NULL;
		prev = NULL; 
	}	
};


class doubly
{
	//int data;
	struct node *head;
	public:
		
		
		doubly()
		{
			head = NULL;
		}
		
		void insert_at_last(int t_data)
		{
			struct node *newnode = new node(t_data); 
			
			if(head == NULL)
			{
				head = newnode;	
			}
			else
			{
				struct node *current = head;
				while ( current->next != NULL )
				{
					current = current->next;
				}
				
				current->next = newnode;
				newnode->prev = current;
				
			}
		}
		
		void insert_at_start(int t_data)
		{
			struct node *newnode = new node(t_data);
			if (head == NULL)
			{
				head = newnode;
			}
			
			else 
			{
				newnode -> next = head;
				head -> prev = newnode;
				head = newnode;
			}
		}
		
		void detete_at_start()
		{
			if(head == NULL)
			{
				cout<<"link list is empty"<<endl;
			}
			
			else
			{
				struct node *temp = head;
				head = head -> next;
				delete temp;
				cout<<"element deleted.................."<<endl;
			}
		}
		
		void delete_at_last()
		{
			if(head == NULL)
			{
				cout<<"link list is empty"<<endl;
			}
			else
			 {
			 	struct node *current = head;
			 	while(current->next != NULL)
			 	{
			 		current = current->next;
				}
				
				struct node *temp;
				 temp = current;
				 current = current -> prev;
				 current->next = NULL;
				 delete temp ;
				 cout<<"element deleted ................";
			 }
			 
		}
		
		void insert_at_middle(int t_data,int pos)
		{
			struct node *newnode = new node(t_data);
			if(head == NULL)
			{
				head = newnode;
			}
			else
			{
			struct node *current = head;
			int count=  1;
			while(current->next != 0 && count < pos-1)	
			{
				count++;
				current = current -> next;
			}
			
			newnode->next = current->next;
			newnode->prev = current;
			current->next->prev = newnode;
			current->next = newnode;

			}
		}
		
		
		void display()
		{
			if(head == NULL)
			{
				cout<<"link list is empty"<<endl;
			}
			
		else
		{
			
			struct node *current = head;
			while(current != NULL )
			{
				cout<<current->data << " -> ";
				current = current->next;
			}
			
			cout<<endl;
		}
		
	}
	
		void delete_at_middle(int pos)
		{
			if(head == NULL)
			{
				cout<<"link list is empty";
			}
			
			else
			{
				struct node *current = head;
				int count = 1;
				while(current->next != NULL && count< pos-1)
				{
					count++;
					current = current->next;
				}
					struct node *temp;
					temp=current->next;
					current->next = current->next->next;
					current->next->prev=current;
					delete temp;
				
			}
		}	
	
};

int main()
{
	int choice,t_data,data,pos;
	doubly d;
	
	do
	{
		cout<<"1.insert at end"<<endl;
		cout<<"2.display"<<endl;
		cout<<"3.insert at start"<<endl;
		cout<<"4.delete at start"<<endl;
		cout<<"5.delete at last"<<endl;
		cout<<"6.insert at any potision"<<endl;
		cout<<"7.delete at any potision"<<endl;


		cout<<endl;
		cout<<"enter the choice : ";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				cout<<"enter the data : ";
				cin>>t_data;
				d.insert_at_last(t_data);
				break;
				
			case 2:
				d.display();
				break;	
				
			case 3:
				cout<<"enter the data : ";
				cin>>t_data;
				d.insert_at_start(t_data);
				break;	
				
			case 4:
				d.detete_at_start();
				break;
				
			case 5:
				d.delete_at_last();
				break;
				
			case 6:
				cout<<"enter the data : ";
				cin>>t_data;
				cout<<"enter the pos: ";
				cin>>pos;
				d.insert_at_middle(t_data,pos);
				break;
				
			case 7:
				
				cout<<"enter the pos: ";
				cin>>pos;
				d.delete_at_middle(pos);
				break;				
					
		}
	}while(choice<=7);
	
	return 0;
}
