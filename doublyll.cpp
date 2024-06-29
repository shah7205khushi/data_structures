
// insert : at last, middle, first
// delete : at last, middle, first

#include<iostream>
using namespace std;
struct node{
    int data;
	struct node* next;
	struct node* prev;
	node(int t_data)
	{
		data = t_data;
		next = NULL;
		prev = NULL;
	}	
};
struct ll{
    struct node* head;
	public:
		ll()
		{
			head = NULL;
		}
		void insert_last(int t_data)
		{
			struct node* newnode = new node(t_data);
			if(head == NULL)
			{
				head = newnode;
			}
			else
			{
				struct node* temp = head;
				while(temp->next != NULL)
				{
					temp = temp->next;
				}
				temp->next = newnode;
				newnode->prev = temp;
				newnode->next = NULL;
			}
		}
		
		void insert_first(int t_data)
		{
		   struct node* newnode = new node(t_data);
		   if(head == NULL)
		   {
		     head = NULL;	
		   }	
		   else
		   {
		     newnode->next = head;
		     head->prev = newnode;
		     head = newnode;
		   }
		}
		
		void insert_middle(int t_data,int pos)
		{
		 struct node* newnode = new node(t_data);
		 if(head == NULL)
		 {
		 	head = newnode;
		 }	
		 else
		 {
		 	struct node* temp = head;
		 	if(pos == 1)
		 	{
		 	  head->next = newnode;
			   newnode->prev = head;	
			}
			else
			{
		 	for(int i=0;i<pos-1;i++)
		 	{
		 		temp = temp->next;
			}
			newnode->next = temp->next;
			newnode->prev = temp;
			temp->next = newnode;
		}
		 }
		}
		
		void delete_first()
		{
		  struct node* t = head;
		  head = head->next;
		  head->prev = NULL;
		  delete t;	
		}
		
		void delete_last()
		{
			struct node* temp = head;
			struct node* t;
			
			while(temp->next->next != NULL)	
			{
				temp = temp->next;
			}
			t = temp->next;
			temp->next = NULL;
			delete t;			
		}
		
		void delete_middle(int pos)
		{
			struct node* temp = head;
			struct node* t;
			for(int i=0;i<pos-1 && temp != NULL;i++)
			{
				temp = temp->next;		
			}
			t = temp->next;
			temp->next = t->next;
			if(temp->next != NULL)
			{
			  temp->next->prev = temp;	
			}
			delete t;
		}
		
		void reverse() {
        node* current = head;
        node* temp = NULL;
        while (current != NULL) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        if (temp != NULL) {
            head = temp->prev;
        }
    }

		void display()
		{
			struct node* temp = head;
			cout<<endl<<"data";
			while(temp != NULL)
			{
				cout<<endl<<temp->data<<endl;
				temp = temp->next;
			}
							
		}
		
		void search(int e)
		{
			struct node* temp = head;
			int count=0;
			while(temp != NULL)
			{
				if(temp->data == e)
				{
					cout<<endl<<temp->data<<" is found at position number "<<count;
				}
				temp = temp->next;
				count++;
			}
		}
		
		void sort_list()
		{
			struct node* temp = head;
			struct node* t;
			int var;
			while(temp != NULL)
			{
				t = temp->next;
				while(t != NULL)
				{
					if(t->data < temp->data)
					{
						var  = t->data;
						t->data = temp->data;
						temp->data = var;
					}
					t = t->next;
				}
				temp = temp->next;
			}
		}
};
int main()
{
	ll l1;
	int ch,t_data,pos,e;
	do{
		cout<<endl;
		cout<<"1. insert last"<<endl;
		cout<<"2. insert first"<<endl;
		cout<<"3. insert middle"<<endl;
		cout<<"4. delete last."<<endl;
		cout<<"5. delete first."<<endl;
		cout<<"6. delete middle."<<endl;
		cout<<"7. display"<<endl;
		cout<<"8. reverse."<<endl;
		cout<<"9. search."<<endl;
		cout<<"10. sort_list."<<endl;
		cout<<"_____________"<<endl;
		cout<<"enter the choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"enter the data : ";
		        cin>>t_data;
				l1.insert_last(t_data);
				break;
				
			case 2:
				cout<<"enter the data : ";
		        cin>>t_data;
				l1.insert_first(t_data);
				break;
				
			case 3:
				cout<<"enter the data : ";
		        cin>>t_data;
		        cout<<"enter the position : ";
		        cin>>pos;
				l1.insert_middle(t_data,pos);
				break;
				
			case 4:
				l1.delete_last();
				break;
				
			case 5:
				l1.delete_first();
				break;
				
			case 6:
				cout<<"enter the position : ";
		        cin>>pos;
				l1.delete_middle(pos);
				break;
				
			case 7:
				l1.display();
				break;
			
			case 8:
				l1.reverse();
                break;
                
            case 9:
            	cout<<"enter search element : ";
            	cin>>e;
            	l1.search(e);
            	
            case 10:
            	l1.sort_list();
            	break;
 		}
	}while(ch != 100);
	return 0;

}
