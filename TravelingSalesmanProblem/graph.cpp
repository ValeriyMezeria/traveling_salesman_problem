#include "graph.h"

Graph::Graph()
{

}

Graph::Graph(vector<Point> val)
{
	adjacency_matrix.resize(val.size());

	for (int i = 0; i < adjacency_matrix.size(); i++)
		adjacency_matrix[i].resize(val.size());

	for (int i = 0; i < adjacency_matrix.size(); i++)
		for (int j = 0; j < adjacency_matrix.size(); j++)
			adjacency_matrix[i][j] = 0;

	for (int i = 0; i < val.size(); i++)
		for (int j = 0; j < adjacency_matrix.size(); j++)
			if (i != j)
				adjacency_matrix[i][j] = adjacency_matrix[j][i] = dist(val[i], val[j]);

}

Graph::~Graph()
{
	for (int i = 0; i < adjacency_matrix.size(); i++)
		adjacency_matrix[i].clear();

	adjacency_matrix.clear();
}

int Graph::getNumVertex() const
{
	return adjacency_matrix.size();
}

double Graph::getEdge(int i, int j) const
{
	if (i < adjacency_matrix.size() && j < adjacency_matrix.size())
		return adjacency_matrix[i][j];
	else
		return -1;
}