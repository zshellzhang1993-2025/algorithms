#include <iostream>
#include <stack>
using namespace std;

#define MAX 2147483647

struct Edge {		//I use a adjacent list to store a logic graph
	int vertex;
	int weight;
	Edge *next;
	Edge() : vertex ( 0 ), weight ( 0 ), next ( NULL ) {}
	Edge ( int vertex, int weight ) : vertex ( vertex ), weight ( weight ) {}
};

enum State { working, free }; //to mark what status the current vertex is

class Graph2 {
public:
	Graph2() {}

	Graph2 ( char *vertex, Edge *e , int n ) {
		this->n = n;
		this->path = new int[n];
		this->vertex = new char[n];
		for ( int i = 0; i < n; i++ )
			this->vertex[i] = vertex[i];

		this->edge = new Edge[n];
		for ( int i = 0; i < n; i++ ) {
			Edge *temp = ( e + i )->next;
			while ( temp ) {
				Edge *node = new Edge ( temp->vertex, temp->weight );
				node->next = ( edge + i )->next;
				( edge + i )->next = node;
				temp = temp->next;
			}
		}
	}

	~Graph2() {
		delete[] this->vertex;
		delete[] this->dist;
		delete[] this->path;
		Edge *next;
		Edge *current;
		for ( int i = 0; i < n; i++ ) {
			next = ( this->edge + i )->next;
			while ( next ) {
				current = next;
				next = next->next;
				delete current;
			}
		}
		delete[] this->edge;
	}

	bool SPFA ( int vertex ) {
		int *dist = new int[n];
		for ( int i = 0; i < n; i++ )
			dist[i] = MAX;
		dist[vertex] = 0;
		path[vertex] = -1;

		State *state = new State[n];
		for ( int i = 0; i < n; i++ )
			state[i] = free;
		state[vertex] = working;

		bool hasNegtiveCircle = SPFA ( dist, state, path , vertex );//core

		delete[] state;
		return hasNegtiveCircle;
	}

	void showPathAndDist() {
		stack<int> s;
		for ( int i = 0; i < n; i++ ) {
			if ( path[i] == -1 )
				continue;
			int temp = i;
			while ( temp != -1 ) {
				s.push ( temp );
				temp = path[temp];
			}
			cout << "Shortest Path for " << vertex[i] << ": ";
			cout << this->vertex[s.top()];
			s.pop();
			while ( !s.empty() ) {
				cout << " -> " << this->vertex[s.top()];
				s.pop();
			}
			cout << endl;
		}
	}

private:
	bool SPFA ( int *dist, State *state, int *path , int vertex ) {
		bool hasNegtiveCircle = false;
		Edge *temp = ( edge + vertex )->next;
		while ( temp && !hasNegtiveCircle ) {
			if ( temp->weight + dist[vertex] < dist[temp->vertex] ) {
				if ( state[temp->vertex] == working )
					return true;
				dist[temp->vertex] = temp->weight + dist[vertex];
				path[temp->vertex] = vertex;
				state[temp->vertex] = working;
				hasNegtiveCircle = SPFA ( dist, state, path, temp->vertex );
				state[temp->vertex] = free;
			}
			temp = temp->next;
		}
		return hasNegtiveCircle;
	}

private:
	char *vertex;
	Edge *edge;
	int n;			//to note down the amount of the vertex
	int *path;		//mark the shortest path
	int *dist;		//the distance of each vertex from the object vertex
};

int main () {
	char vertex[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
	Edge *edge = new Edge[6];
	Edge *temp = new Edge ( 1, 8 );
	temp->next = ( edge + 0 )->next;
	( edge + 0 )->next = temp;
	temp = new Edge ( 2, 10 );
	temp->next = ( edge + 0 )->next;
	( edge + 0 )->next = temp;
	temp = new Edge ( 3, 2 );
	temp->next = ( edge + 1 )->next;
	( edge + 1 )->next = temp;
	temp = new Edge ( 4, 2 );
	temp->next = ( edge + 2 )->next;
	( edge + 2 )->next = temp;
	temp = new Edge ( 5, 5 );
	temp->next = ( edge + 2 )->next;
	( edge + 2 )->next = temp;
	temp = new Edge ( 2, -4 );
	temp->next = ( edge + 3 )->next;
	( edge + 3 )->next = temp;
	temp = new Edge ( 3, -3 );
	temp->next = ( edge + 4 )->next;
	( edge + 4 )->next = temp;
	temp = new Edge ( 5, 1 );
	temp->next = ( edge + 4 )->next;
	( edge + 4 )->next = temp;

	Graph2 g ( vertex, edge, 6 );		//construct a graph with a negtive circle
	if ( !g.SPFA ( 0 ) )
		g.showPathAndDist();
	else
		cout << "hasNegtiveCircle!" << endl;

	Edge *next;
	Edge *current;
	for ( int i = 0; i < 6; i++ ) {
		next = ( edge + i )->next;
		while ( next ) {
			current = next;
			next = next->next;
			delete current;
		}
	}
	delete[] edge;

	edge = new Edge[6];
	temp = new Edge ( 1, 8 );
	temp->next = ( edge + 0 )->next;
	( edge + 0 )->next = temp;
	temp = new Edge ( 2, 10 );
	temp->next = ( edge + 0 )->next;
	( edge + 0 )->next = temp;
	temp = new Edge ( 3, 2 );
	temp->next = ( edge + 1 )->next;
	( edge + 1 )->next = temp;
	temp = new Edge ( 4, 2 );
	temp->next = ( edge + 2 )->next;
	( edge + 2 )->next = temp;
	temp = new Edge ( 5, 5 );
	temp->next = ( edge + 2 )->next;
	( edge + 2 )->next = temp;
	temp = new Edge ( 2, -4 );
	temp->next = ( edge + 3 )->next;
	( edge + 3 )->next = temp;
	temp = new Edge ( 3, 3 );
	temp->next = ( edge + 4 )->next;
	( edge + 4 )->next = temp;
	temp = new Edge ( 5, 1 );
	temp->next = ( edge + 4 )->next;
	( edge + 4 )->next = temp;

	Graph2 g2 ( vertex, edge, 6 );		//construct a graph without a negtive circle
	if ( !g2.SPFA ( 0 ) )
		g2.showPathAndDist();
	else
		cout << "hasNegtiveCircle!" << endl;

	for ( int i = 0; i < 6; i++ ) {
		next = ( edge + i )->next;
		while ( next ) {
			current = next;
			next = next->next;
			delete current;
		}
	}
	delete[] edge;

	return 0;
}
