#include "Graph.h"


Graph::Graph(int vertices)
{
	graph.resize(vertices);
}

Graph::~Graph()
{
}

void Graph::addVertice(int v, int u)
{
	graph[v].push_back(u);
	graph[u].push_back(v);
}

void Graph::bfs(int v)
{
	std::list<int>::iterator i;
	bool* visited = new bool[graph.size()];
	for (int i = 0; i < graph.size(); i++) {
		visited[i] = false;
	}
	visited[v] = true;
	std::deque<int> queue;
	queue.push_back(v);
	int vertex;
	while (!queue.empty()) {
		vertex = queue.front();
		std::cout << vertex << std::endl;
		queue.pop_front();

		for (i = graph[vertex].begin(); i != graph[vertex].end(); i++) {
			if (!visited[*i]) {
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
	delete visited;
}

void Graph::dfs(int v)
{
	bool* visited = new bool[graph.size()];
	for (int i = 0; i < graph.size(); i++) {
		visited[i] = false;
	}
	dfsHelper(v, visited);
	delete visited;
}

void Graph::dfsHelper(int v, bool * visited)
{
	visited[v] = true;
	std::cout << v << std::endl;
	std::list<int>::iterator i;
	for (i = graph[v].begin(); i != graph[v].end(); i++) {
		if (!visited[*i]) {
			dfsHelper(*i, visited);
		}
	}
}

