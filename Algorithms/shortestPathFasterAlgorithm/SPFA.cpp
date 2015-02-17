#include <iostream>
#include <queue>
using namespace std;

#define MAX 2147483647

struct Edge {		//I use a adjacent list to store a logic graph
	int vertex;
	int weight;
	Edge *next;
	Edge() : vertex ( 0 ), weight ( 0 ), next ( NULL ) {}
	Edge ( int vertex, int weight ) : vertex ( vertex ), weight ( weight ) {}
};

class Graph2 {
public:
	Graph2() {}

	Graph2 ( char *vertex, Edge *e ) {
		this->vertex = vertex;
		this->edge = e;
	}

	~Graph2() {
		delete[] this->vertex;
		Edge *next;
		Edge *current;
		for ( int i = 0; i < n; i++ ) {
			next = this->edge[i]->next;
			while ( next ) {
				current = next;
				next = next->next;
				delete current;
			}
		}
		delete[] this->edge;
	}

	bool SPFA ( int vertex ) {
		queue<int> table ( vertex );

		int dist[n] = new int[n];
		for ( int i = 0; i < n; i++ )
			dist[i] = MAX;
		dist[vertex] = 0;

		bool judgeValid[n] = new bool[n];
		for ( int i = 0; i < n; i++ )
			judgeValid[i] = true;

		int path[n] = new int[n];
		path[vertex] = -1;

		while ( !table.empty() ) {
			int current = table.pop();
			if ( !judgeValid[current] ) {
				judgeValid[current] = true;
				continue;
			}
			Edge *temp = edge[current]->next;
			while ( temp ) {
				if ( temp->weight + dist[current] < dist[temp->vertex] ) {
					if ( dist[temp->vertex] == MAX ) {
						dist[temp->vertex] = temp->weight + dist[current];
						table.push ( temp->vertex );
					} else {
						table.push ( temp->vertex );
						judgeValid[temp->vertex] = false;
					}
					path[temp->vertex] = current;
				}
				temp = temp->next;
			}
		}


	}

private:
	char *vertex;
	Edge *edge;
	int n;		//to note down the amount of the vertex
};

int main () {
	return 0;
}
