#include <iostream>
#include <stack>
#include <list>
#include <climits>
using namespace std;

int wow;
int aye;

class Graph
{
	int vert;
	int lowest;
	bool boolL;
	list<int> *edge;
	int output[];

	void inputStack(int v, bool visited[], stack<int> &Stack);
	void printOrder(int v, bool visited[],bool boolL);

public:
	Graph(int vert);
	void addEdge(int v1, int v2);
	void printSCC();
	Graph getTranspose();
};

Graph::Graph(int vert)
{
	this->vert = vert;
	output[vert];
	edge = new list<int>[vert];
}

void Graph::printOrder(int v, bool visited[], bool boolL)
{
	visited[v] = true;
	cout << v << " ";
	wow++;
	output[aye] = v;
	aye++;
	list<int>::iterator i;
	for(i = edge[v].begin(); i != edge[v].end(); ++i)
	{
		if(!visited[*i])
		{
			printOrder(*i,visited,boolL);
		}
	}
}

Graph Graph::getTranspose()
{
	Graph g(vert);
	for(int v = 0; v < vert; v++)
	{
		list<int>::iterator i;
		for(i = edge[v].begin(); i != edge[v].end(); ++i)
		{
			//cout << "v is: " << v << " i is: " << *i << endl;
			g.edge[*i].push_back(v);
		}
	}
	return g;
}

void Graph::addEdge(int v1, int v2)
{
	edge[v1].push_back(v2);
}

void Graph::inputStack(int v, bool visited[], stack<int> &Stack)
{
	visited[v] = true;
	list<int>::iterator i;
	for(i = edge[v].begin(); i != edge[v].end(); ++i)
	{
		if(!visited[*i])
		{
			inputStack(*i, visited, Stack);
		}
	}
	Stack.push(v);
}

void Graph::printSCC()
{
	stack<int> Stack;
	int num[vert];
	int actual[vert];
	for(int i = 0; i < vert; i++)
	{
		num[i] = 0;
	}
	wow = 0;
	aye = 0;
	int low = INT_MAX;
	bool *visited = new bool[vert];
	//cout << "vert is: " << vert << endl;
	for(int i = 0; i < vert; i++)
	{
		visited[i] = false;
	}

	for(int i = 0; i < vert; i++)
	{
		if(visited[i] == false)
		{
			inputStack(i,visited,Stack);
		}
	}

	Graph G = getTranspose();

	for(int i = 0; i < vert; i++)
	{
		visited[i] = false;
	}
	int k = 0;
	while(Stack.empty() == false)
	{
		int v = Stack.top();
		boolL = false;
		//cout << "top of stack: " << v << endl;
		Stack.pop();

		if(visited[v] == false)
		{
			G.printOrder(v,visited,boolL);
			num[k] = wow;
			k++;
			wow = 0;
			cout << endl;
		}
	}
	cout << "made it through while" << endl;
	for(int i = 0; i < vert; i++)
	{
		//cout << num[i] << endl;
	}
	//cout << endl;
	for(int i = 0; i < vert; i++)
	{
		//cout << G.output[i] << endl;
	}
	int a = 0;
	int b = 0;
	int c = 0;
	while(num[a] != 0)
	{
		cout << "its here" << endl;
		low = INT_MAX;
		for(int i = 0; i < num[a]; i++)
		{
			if(low > G.output[b])
			{
				//cout << "low changes to " << G.output[b] << endl;
				low = G.output[b];
			}
			b++;
		}
		for(int i = 0; i < num[a]; i++)
		{
			actual[G.output[c]] = low;
			c++;
		}
		a++;
	}
	for(int i=0; i<vert; i++)
	{
		cout << actual[i] << endl;
	}
	//cout << endl;
}

int main()
{
	int numV;
	int numE;
	int v1, v2;
	cin >> numV;
	cin >> numE;
	Graph gr(numV);
	for(int i = 0; i < numE; i++)
	{
		cin >> v1;
		cin >> v2;
		gr.addEdge(v1,v2);
	}
	gr.printSCC();

}
