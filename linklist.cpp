#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;

	node(int t_data)
	{
		data=t_data;
		next=NULL;

	} 
};

class link_list
{
	node  *head;
	public:

		link_list()

		{
			head=NULL;
		}


		//insert at begin

		void addb(int t_data)
		{
			node  *newnode = new node(t_data);
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


		//delete at begin

		void del_at_first()
		{
			if(head==NULL)
			{
				cout<<"link list is empty"<<endl;
			}

			else
			{
				struct node  *temp;

				temp = head;
				head=head->next;
				delete temp;
				cout<<"element is deleted"<<endl;
			}
		}


		//insert at end

		void addl(int t_data)
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

				current->next=newnode;
			}
		}
		
		
		//delete at end
		
		del_at_last()
		{
			if(head == NULL)
			{
				cout<<"link list is empty"<<endl;
			}
			
			else if(head->next == NULL)
			{
				struct node *temp = head;
				delete temp;
				head = NULL;
				cout<<"element is deleted"<<endl;
			}
			
			else
			{
				struct node *current = head;
			
				while(current->next->next != NULL)
				{
			
					current=current->next;
			
				}
					delete current->next;
					current->next = NULL;
					cout<<"element is deleted"<<endl;
			}
	}

		//display the linklist

		display()
		{
			node *current = head;
			while(current != NULL)
			{
				cout<<"element :"<<current->data;
				current = current->next;
				cout<<endl;
			}
		}
		
		

};

int main()
{
	link_list l1;
	int ch,pos,t_data;

	do
	{

	cout<<"1 .for add at beg"<<endl;
	cout<<"2 .for display"<<endl;
	cout<<"3 .for del at beg"<<endl;
	cout<<"4 .for add at last"<<endl;
	cout<<"5 .for del at last"<<endl;
	cout<<"------------------------"<<endl;
	cout<<"enter choice"<<endl;
	cin>>ch;

	switch(ch)
	{
	  case 1:
	  {
	  	cout<<"enter data : ";
	  	cin>>t_data;
	  	l1.addb(t_data);
	  	break;
	  	
	  	
	  	case 2:
	  		l1.display();
	  		break;
	  		
	  	
		case 3:
			l1.del_at_first();
			break; 
			
			
		case 4:
			cout<<"enter data : ";
	  		cin>>t_data;
	  		l1.addl(t_data);
	  		break;
			
	  	case 5:
			l1.del_at_last();
			break; 
	  	
	  }
	  
	  	
	}

	}while(ch <= 5);

	return 0;
}
