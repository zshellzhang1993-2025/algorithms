#include <iostream>
#include <stack>
#include <priorityQueue.h>
#include <priorityQueue.cpp>
using namespace std;

#define MAX 1073741824

struct Edge {
	int vertex;
	int weight;
	Edge *next;
	Edge() : vertex ( 0 ), weight ( 0 ), next ( NULL ) {}
	Edge ( int vertex, int weight ) : vertex ( vertex ), weight ( weight ) {}
};

struct Entity {
	int vertex;
	int dist;
	Entity () : dist ( MAX ) {}
	Entity ( int vertex, int dist ) : vertex ( vertex ), dist ( dist ) {}
	bool operator < ( Entity& e ) {
		return this->dist < e.dist;
	}
};

class GraphForShotestPath2 {
public:
	GraphForShotestPath2() {}

	GraphForShotestPath2 ( char *vertex, Edge *e , int n ) {
		this->n = n;
		this->path = new int[n];
		this->dist = new int[n];
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

	~GraphForShotestPath2() {
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

	void Dijkstra ( int vertex ) {
		Entity *entity = new Entity[n];
		for ( int i = 0; i < n; i++ ) {
			entity[i].vertex = i;
			dist[i] = MAX;
			path[i] = -1;
		}
		entity[vertex].dist = 0;
		dist[vertex] = 0;
		PriorityQueue<Entity> queue ( entity, 6 );
		while ( !queue.isEmpty() ) {
			Entity e = queue.Peek();
			queue.Pop();
			Edge *temp = ( edge + e.vertex )->next;
			while ( temp ) {
				if ( dist[temp->vertex] > dist[e.vertex] + temp->weight ) {
					dist[temp->vertex] = dist[e.vertex] + temp->weight;
					if ( queue.updateKey ( temp->vertex, Entity ( temp->vertex, dist[temp->vertex] ) ) )
						path[temp->vertex] = e.vertex;
				}
				temp = temp->next;
			}
		}
		delete[] entity;
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
	char *vertex;
	Edge *edge;
	int n;			//to note down the amount of the vertex
	int *path;		//mark the shortest path
	int *dist;		//the distance of each vertex from the object vertex
};

int main () {
	char vertex[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
	Edge *edge = new Edge[6];
	Edge *temp = new Edge ( 2, 10 );
	temp->next = ( edge + 0 )->next;
	( edge + 0 )->next = temp;
	temp = new Edge ( 1, 8 );
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
	temp = new Edge ( 2, 4 );
	temp->next = ( edge + 3 )->next;
	( edge + 3 )->next = temp;
	temp = new Edge ( 3, 3 );
	temp->next = ( edge + 4 )->next;
	( edge + 4 )->next = temp;
	temp = new Edge ( 5, 1 );
	temp->next = ( edge + 4 )->next;
	( edge + 4 )->next = temp;

	GraphForShotestPath2 g ( vertex, edge, 6 );

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

	g.Dijkstra ( 0 );
	g.showPathAndDist();
	cout << endl;
	g.Dijkstra ( 2 );
	g.showPathAndDist();

	return 0;
}
