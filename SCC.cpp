#include <iostream>
#include <stack>
#include <list>
using namespace std;

class Graph
{
	int vert;
	list<int> *edge;

	void inputStack(int v, bool visited[], stack<int> &Stack);
	void printOrder(int v, bool visited[]);

public:
	Graph(int vert);
	void addEdge(int v1, int v2);
	void printSCC();
	Graph getTranspose();
};

Graph::Graph(int vert)
{
	this->vert = vert;
	edge = new list<int>[vert];
}

void Graph::printOrder(int v, bool visited[])
{
	visited[v] = true;
	cout << v << " ";

	list<int>::iterator i;
	for(i = edge[v].begin(); i != edge[v].end(); ++i)
	{
		if(!visited[*i])
		{
			printOrder(*i,visited);
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

	bool *visited = new bool[vert];
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

	while(Stack.empty() == false)
	{
		int v = Stack.top();
		cout << "top of stack: " << v << endl;
		Stack.pop();

		if(visited[v] == false)
		{
			G.printOrder(v,visited);
			cout << endl;
		}
	}
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
