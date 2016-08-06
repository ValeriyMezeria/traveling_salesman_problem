#include <iostream>
#include <fstream>
#include <string>

#include "graph.h"

using namespace std;


vector<Point> Read(string filename)
{
	ifstream is(filename);
	vector<Point> result;
	Point tmp;
	int size;

	is >> size;
	result.resize(size);

	if (!is.bad())
	{
		for (int i = 0; i < size; i++)
		{
			is >> tmp.x >> tmp.y;
			result[i] = tmp;
		}
	}

	is.close();

	return result;
}

void Write(const pair<double, vector<int>>& result, string filename)
{
	ofstream os(filename, ios::trunc);

	os << round(result.first) << endl;

	for (int i = 0; i < result.second.size(); i++)
	{
		os << result.second[i];
		if (i != result.second.size() - 1)
			os << " ";
	}

	os.close();
}



bool isVertexVisited(const vector<int>& path, int vertex)
{
	for (int i = 0; i < path.size(); i++)
		if (path[i] == vertex)
			return true;

	return false;
}

pair<double, vector<int>> FindPseudoMinCycle(const Graph& graph, int start)
{
	pair<double, vector<int>> result;
	int cur_vertex, min_vertex;
	double min_dist;

	result.first = 0;
	result.second.push_back(start);
	cur_vertex = start;

	for (int i = 0; i < graph.getNumVertex() - 1; i++)
	{
		min_dist = INF;
		for (int j = 0; j < graph.getNumVertex(); j++)
		{
			if (!isVertexVisited(result.second, j) && j != cur_vertex)
				if (graph.getEdge(cur_vertex, j) < min_dist)
				{
				min_dist = graph.getEdge(cur_vertex, j);
				min_vertex = j;
				}
		}

		result.first += min_dist;
		result.second.push_back(min_vertex);
		cur_vertex = min_vertex;
	}

	result.first += graph.getEdge(cur_vertex, start);
	result.second.push_back(start);


	return result;
}

pair<double, vector<int>> Solution(const Graph& graph)
{
	pair<double, vector<int>> result, tmp;
	result.second.resize(graph.getNumVertex());

	result.first = INF;

	for (int i = 0; i < graph.getNumVertex(); i++)
	{
		tmp = FindPseudoMinCycle(graph, i);

		if (tmp.first < result.first)
			result = tmp;
	}
	

	return result;
}



int main(int argc, char* argv[])
{
	pair<double, vector<int>> res;
	vector<Point> a;
	string filename;

	//string filename = argv[1];
	filename = "input_01.txt";

	a = Read(filename);

	Graph val(a);

	res = Solution(val);

	Write(res, "output.txt");

	return 0;
}