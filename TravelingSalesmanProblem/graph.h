#pragma once

#include <vector>
#include <math.h>

using namespace std;

const int INF = 999999999;

struct Point
{
	double x;
	double y;
};

class Graph
{
private:
	vector<vector<double> > adjacency_matrix;

	double dist(Point p1, Point p2) const { return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2)); };

public:
	Graph();

	Graph(vector<Point>);


	~Graph();

	int getNumVertex() const;

	double getEdge(int, int) const;

	//int getMinDistVertex(int) const;
};