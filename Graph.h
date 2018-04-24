#pragma once
#include <vector>
#include <list>
#include<deque>
#include<iostream>
class Graph
{
public:
	Graph(int vertices);
	~Graph();
	void addVertice(int v, int u);
	void bfs(int v);
	void dfs(int v);
private:
	void dfsHelper(int v, bool* visited);
	std::vector<std::list<int>> graph;
};

