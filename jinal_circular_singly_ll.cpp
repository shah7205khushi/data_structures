//CIRCULAR LINKED LIST IN C++

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
class circular_singly_linked_list{
	struct node *head;
	public:
		circular_singly_linked_list()
		{
			head = NULL;
		}
		
		
		//DISPLAY LINKED LIST
		void display(void)
		{
//			struct node *current = head;
			if(head == NULL)
			{
				cout<<"\nnothing to display...\n";
			}
			else
			{
				struct node *current = head;
				do{
					cout<<current->data <<" -> ";
					current = current->next;
				}while(current != head);
			}
		}
		
		//INSERT AT START
		void insert_at_start(int t_data)
		{
			struct node *newnode = new node(t_data);
			if(head == NULL)
			{
				newnode->next = newnode;
				head = newnode;
			}
			else
			{
				newnode->next = head;// makes linked list circular
				struct node *current = head;
				while(current->next != head)
				{
					current = current->next;
				}
//				newnode->next = head;
				current->next = newnode;
				head = newnode;
			}
		}
		
		//INSERT AT MIDDLE
		void insert_at_middle(int t_data,int pos)
		{
//			
				if(pos < 1)
				{
					cout<<"\ninvalid position...\n";
					return;
				}
				
				if(pos  == 1)
				{
					insert_at_start(t_data);
					return;
				}
				
			struct node *newnode = new node(t_data);
				struct node *current = head;
				int count = 1;
				do{
					count++;
					current = current->next;
				}while(current != NULL && count < pos - 1);
				
				newnode->next = current->next;
				current->next = newnode;
				
			}
		
		
		//INSERT AT end
		void insert_at_end(int t_data)
		{
			struct node *newnode = new node(t_data);
			if(head == NULL)
			{
				newnode->next = newnode;
				head = newnode;
			}
			else
			{
				newnode->next = head;// makes linked list circular
				struct node *current = head;
				while(current->next != head)
				{
					current = current->next;
				}
//				newnode->next = head;
				current->next = newnode;
			}
		}
		
		
		
		
		
		// DELETE AT START 
void d_s(void)
{
    if(head == NULL)
    {
        cout<<"\nlist is empty...\n";
    }
    else
    {
        struct node *temp = head;
        if(head->next == head) // Only one node in the list
        {
            head = NULL;
        }
        else
        {
            struct node *current = head;
            while(current->next != head)
            {
                current = current->next;
            }
            head = head->next;
            current->next = head;
        }
        delete temp;
    }
}

		
		
		
		void d_m(int pos)
{
    if(head == NULL)
    {
        cout<<"\nlist is empty...\n";
    }
    else if(pos == 1) // Delete the first node
    {
//        struct node *temp = head;
//        head = head->next;
//        delete temp;

 			d_s();
 			return;
    }
    else
    {
        struct node *current = head;
        int count = 1;
        while(current->next != head && count < pos - 1)
        {
            count++;
            current = current->next;
        }

        // Check if the position is valid
//        if(current->next == head || count != pos - 1)
//        {
//            cout << "\nInvalid position...\n";
//            return;
//        }

        struct node *d_n = current->next;
        current->next = d_n->next;
        delete d_n;
    }
}

	
	// DELETE LAST ELEMENT
void d_e(void)
{
    if(head == NULL)
    {
        cout<<"\nlist is empty...\n";
    }
    else if(head->next == head) // Only one node in the list
    {
        delete head;
        head = NULL;
    }
    else
    {
        struct node *temp = head;
        struct node *prevNode = NULL;
        while(temp->next != head)
        {
            prevNode = temp;
            temp = temp->next;
        }
        prevNode->next = head; // Update the next pointer of second-to-last node
        delete temp;
    }
}


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
	circular_singly_linked_list ll;
//	ll.insert_at_start(8);
//	ll.insert_at_start(6);
//	ll.insert_at_start(1);
//	ll.insert_at_start(85);
//	ll.insert_at_start(56);
//	
//	ll.display();
//	cout<<"\n";
//	ll.insert_at_middle(7000,3);
//	
//	ll.display();
//	
//	
//	cout<<"\n";
//	ll.insert_at_end(24);
//	
//	ll.display();
//	
//	
//	cout<<"\n";
//	ll.insert_at_end(25);
//	
//	ll.display();
//	
//	cout<<"\n";
//	ll.d_s();
//	
//	ll.display();
//	
//	cout<<"\n";
//	ll.d_s();
//	
//	ll.display();
//	
//	cout<<"\n";
//	ll.d_s();
//	
//	ll.display();
//
//cout<<"\n";
//	ll.d_e();
//	
//	ll.display();
//	
//	cout<<"\n";
//	ll.d_e();
//	
//	ll.display();
//	
//	cout<<"\n";
//	ll.d_m(2);
//	
//	ll.display();
//
//	cout<<"\n";
//	ll.d_m(2);
//	
//	ll.display();
//	
//	ll.insert_at_start(8);
//	ll.insert_at_start(6);
//	ll.insert_at_start(1);
//	ll.insert_at_start(85);
//	ll.insert_at_start(56);
//	
//	ll.display();
//	cout<<"\n";
//	
//	cout<<"\n";
//	ll.d_m(1);
//	
//	ll.display();
//	
//	cout<<"\n";
//	ll.d_m(1);
//	
//	ll.display();
//	
//	cout<<"\n";
//	ll.d_m(1);
//	
//	ll.display();
//	cout<<"\n";
//	ll.sort();
//		ll.display();
//		cout<<"\n";
//	ll.reverse();
//	ll.display();
//	cout<<"\n";
	
	ll.insert_at_start(8);
	ll.insert_at_start(6);
	ll.insert_at_start(1);
	ll.insert_at_start(85);
	ll.insert_at_start(56);
	ll.display();
	cout<<"\n";
	
	cout<<"\n";
	ll.reverse();
	ll.display();
	
	cout<<"\n";
	ll.sort();
	ll.display();

	return 0;
}

