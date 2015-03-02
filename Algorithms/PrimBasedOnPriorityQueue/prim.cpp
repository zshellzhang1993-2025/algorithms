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
	int cost;
	Entity () : cost ( MAX ) {}
	Entity ( int vertex, int cost ) : vertex ( vertex ), cost ( cost ) {}
	bool operator < ( Entity& e ) {
		return this->cost < e.cost;
	}
};

class GraphForMST1 {
public:
	GraphForMST1() {}

	GraphForMST1 ( char *vertex, Edge *e , int n ) {
		this->n = n;
		this->path = new int[n];
		this->cost = new int[n];
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

	~GraphForMST1() {
		delete[] this->vertex;
		delete[] this->cost;
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

	void Prim ( int vertex ) {
		Entity *entity = new Entity[n];
		for ( int i = 0; i < n; i++ ) {
			entity[i].vertex = i;
			cost[i] = MAX;
			path[i] = -1;
		}
		entity[vertex].cost = 0;
		cost[vertex] = 0;
		PriorityQueue<Entity> queue ( entity, 6 );
		while ( !queue.isEmpty() ) {
			Entity e = queue.Peek();
			queue.Pop();
			Edge *temp = ( edge + e.vertex )->next;
			while ( temp ) {
				if ( cost[temp->vertex] > temp->weight ) {
					cost[temp->vertex] = temp->weight;
					if ( queue.updateKey ( temp->vertex, Entity ( temp->vertex, cost[temp->vertex] ) ) )
						path[temp->vertex] = e.vertex;
				}
				temp = temp->next;
			}
		}
		delete[] entity;
	}

	void showMST() {
		for ( int i = 0; i < n; i++ ) {
			if ( path[i] == -1 )
				continue;
			cout << vertex[i] << "<-->" << vertex[path[i]] << endl;
		}
	}

private:
	char *vertex;
	Edge *edge;
	int n;			//to note down the amount of the vertex
	int *path;		//mark the path
	int *cost;		//the cost of each vertex from the object vertex
};

int main () {
	char vertex[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
	Edge *edge = new Edge[6];
	Edge *temp;
	/* vertex 0 */
	temp = new Edge ( 2, 10 );
	temp->next = ( edge + 0 )->next;
	( edge + 0 )->next = temp;
	temp = new Edge ( 1, 8 );
	temp->next = ( edge + 0 )->next;
	( edge + 0 )->next = temp;
	/* vertex 1 */
	temp = new Edge ( 3, 2 );
	temp->next = ( edge + 1 )->next;
	( edge + 1 )->next = temp;
	temp = new Edge ( 0, 8 );
	temp->next = ( edge + 1 )->next;
	( edge + 1 )->next = temp;
	/* vertex 2 */
	temp = new Edge ( 4, 2 );
	temp->next = ( edge + 2 )->next;
	( edge + 2 )->next = temp;
	temp = new Edge ( 5, 5 );
	temp->next = ( edge + 2 )->next;
	( edge + 2 )->next = temp;
	temp = new Edge ( 3, 4 );
	temp->next = ( edge + 2 )->next;
	( edge + 2 )->next = temp;
	temp = new Edge ( 0, 10 );
	temp->next = ( edge + 2 )->next;
	( edge + 2 )->next = temp;
	/* vertex 3 */
	temp = new Edge ( 2, 4 );
	temp->next = ( edge + 3 )->next;
	( edge + 3 )->next = temp;
	temp = new Edge ( 1, 2 );
	temp->next = ( edge + 3 )->next;
	( edge + 3 )->next = temp;
	temp = new Edge ( 4, 3 );
	temp->next = ( edge + 3 )->next;
	( edge + 3 )->next = temp;
	/* vertex 4 */
	temp = new Edge ( 3, 3 );
	temp->next = ( edge + 4 )->next;
	( edge + 4 )->next = temp;
	temp = new Edge ( 5, 1 );
	temp->next = ( edge + 4 )->next;
	( edge + 4 )->next = temp;
	temp = new Edge ( 2, 2 );
	temp->next = ( edge + 4 )->next;
	( edge + 4 )->next = temp;
	/* vertex 5 */
	temp = new Edge ( 2, 5 );
	temp->next = ( edge + 5 )->next;
	( edge + 5 )->next = temp;
	temp = new Edge ( 4, 1 );
	temp->next = ( edge + 5 )->next;
	( edge + 5 )->next = temp;

	GraphForMST1 g ( vertex, edge, 6 );

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

	g.Prim ( 0 );
	g.showMST();
	cout << endl;
	g.Prim ( 2 );
	g.showMST();

	return 0;
}
