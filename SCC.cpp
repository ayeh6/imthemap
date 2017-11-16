#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void DFS(vector<int> graph[], vector<int> &vertice, int a, bool visit[])
{
	visit[a] = true;
	for(int i = 0; i < graph[a].size(); i++)
	{
		if(!visit[graph[a][i]])
		{
			DFS(graph, vertice, graph[a][i],visit);
		}
	}
	vertice.push_back(a);
}

int main() {
	int vert;
	int edge;

	//input num of vertices and edges
	cin >> vert;
	cin >> edge;

	int output[vert];
	vector<int> adjacent[edge];
	vector<int> vertices[vert];
	vector<int> order;
	vector<int> temp;
	vector< vector<int> > StrongConComp;
	bool visit[vert] = {0};

	for(int i = 0; i < vert; i++)
	{
		//adds each index(vertice) to the array
		output[i] = i;
	}

	int v1;
	int v2;
	for(int i = 0; i < edge; i++)
	{
		//adds each edge between vertices
		cin >> v1;
		cin >> v2;
		adjacent[v1].push_back(v2);
	}

	for(int i = 0; i < vert; i++)
	{
		//reset visits
		visit[i] = false;
	}

	for(int i = 0; i < vert; i++)
	{
		if(!visit[i])
		{
			//perform depth first search
			DFS(adjacent, order, i, visit);
		}
	}

	for(int i = 0; i < vert; i++)
	{
		for(int j = 0; j < adjacent[i].size(); j++)
		{
			vertices[adjacent[i][j]].push_back(i);
		}
	}

	for(int i = 0; i < vert; i++)
	{
		//reset visited array
		visit[i] = false;
	}

	//reverse the order of order
	temp = order;
	order.clear();
	while(!temp.empty())
	{
		order.push_back(temp.back());
		temp.pop_back();
	}

	for(int i = 0; i < order.size(); i++)
	{
		if(!visit[order[i]])
		{
			vector<int> component;
			DFS(vertices, component, order[i], visit);
			StrongConComp.push_back(component);
		}
	}

	int comp;
	int min;
	int temp1;
	for(int i = 0; i < StrongConComp.size(); i++)
	{
		for(int j = 0; j < StrongConComp[i].size(); j++)
		{
			comp = StrongConComp[i][j];
			for(int k = 0; k < vert; k++)
			{
				if(output[k] == comp)
				{
					//find the minimum of the strong connected group
					min = INT_MAX;
					for(int m = 0; m < StrongConComp[i].size(); m++)
					{
						temp1 = StrongConComp[i].at(m);
						if(min > temp1)
						{
							min = temp1;
						}
					}
					output[k] = min;

				}
			}
		}
	}

	//final output
	for(int i = 0; i < vert; i++)
	{
		cout << output[i] << endl;
	}

	return 0;
}
