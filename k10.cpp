#include<iostream>
using namespace std;

#define MAX 10

class queue
{
	int item[MAX];
	int front,rear;
	public:
		queue()
		{
			front = -1;
			rear = -1;
		}
		
		bool isfull()
		{
			return rear == MAX-1;
		}
		
		bool isempty()
		{
			return front == -1 || front>rear;
		}
		
		void enqueue(int element)
		{
			if (isfull())
			{
				cout<<"queue is full"<<endl;
				return;
			}
			else
			{
				if(front == -1)front = 0;
				item[++rear] = element;
			}
		}
		
		int dequeue()
		{
			if(isempty())
			{
				cout<<"queue is empty"<<endl;
				return -1;
			}
			else
			{
				return item[front++];
			}
		}
};

void bfs(int adj[][MAX], bool visited[],int start,int n)
{
	queue q1;
	q1.enqueue(start);
	visited[start] = true;
	
	while(!q1.isempty())
	{
		start = q1.dequeue();
		cout<<start<<"\t";
	
	
	for(int i=0;i<n;++i)
	{
		if(adj[start][i]==1 && !visited[i])
		{
			q1.enqueue(i);
			visited[i] = true;
		}
	}
	
	}
}

int main()
{
	bool visited[MAX] = {0};
	int adj[MAX][MAX],n;
	
	cout<<"enter the number of vertices"<<endl;
	cin>>n;
	
	if(n>MAX)
	{
		cout<<"vertices shoud be less than or equle to" <<MAX<<endl;
		return 1;
	}
	
	cout<<"enter the adjacency matrix:"<<endl;
	
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			cin>>adj[i][j];
		}
	}
	
	    cout << "BFS starting from vertex 0:\n";
        bfs(adj,visited,0,n);

		return 0;
}

/*

enter the number of vertices
5
enter the adjacency matrix:
1 0 1 0 1
0 1 0 1 0
1 1 0 0 1
0 0 1 1 0
1 0 1 0 0
BFS starting from vertex 0:
0       2       4       1       3



*/

