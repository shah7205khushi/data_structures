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
class linklist{
 node *head;
 public:
  linklist()
  {
    head = NULL;
}
void add_first(int t_data)
{
node *newnode = new node(t_data);
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
void add_last(int t_data)
{
node *newnode = new node(t_data);
if(head == NULL)
{
head = newnode;
}
else
{
node *current = head;
      while(current->next != NULL)
    {
current = current->next;
   }
   current->next = newnode;
   newnode->next = NULL;
}
}
add_middle(int pos,int t_data)
{
node *newnode = new node(t_data);
if(head == NULL)
{
head = newnode;
}
else
{
node *current = head;
for(int i=0;i<pos-1;++i)
{
    current = current->next;
}
newnode->next = current->next;
current->next = newnode;
}
}
void delete_first()
{

head = head->next;
// delete head;
}


void delete_last()
{
node *current = head;
while(current->next->next != NULL)
{
current= current->next;
}
current->next = NULL;
// delete current;
//
}

void delete_middle(int pos)
{
node *current = head;
for(int i=0;i<pos-1;i++)
{
    current = current->next;
}

current->next = current->next->next;
}
display()
{
node *current = head;
while(current != NULL)
{
cout<<"e :"<<current->data;
current = current->next;
   cout<<"\n";
}
}
};
int main()
{
linklist ll;
int ch,t_data,pos;
do{
cout<<"\n 1.add_first.";
cout<<"\n 2.add_last.";
cout<<"\n 3.add_middle.";
cout<<"\n 4.display list.";
cout<<"\n 5.delete_frist.";
cout<<"\n 6.delete_last";
cout<<"\n 7.delete_middle";
cout<<"\n________________\n";
cout<<"enter ch : ";
cin>>ch;
switch(ch)
{
case 1:
cout<<"enter data :";
cin>>t_data;
ll.add_first(t_data);
break;

case 2:
cout<<"enter data :";
cin>>t_data;
  ll.add_last(t_data);
break;

case 3:
cout<<"enter data :";
cin>>t_data;
cout<<"enter pos :";
cin>>pos;
ll.add_middle(pos,t_data);
break;
case 4:
ll.display();
break;

case 5:
ll.delete_first();
break;
case 6:
ll.delete_last();
case 7:
cout<<"enter pos :";
cin>>pos;
ll.delete_middle(pos);
break;
}
}while(ch != 10);
return 0;
}
