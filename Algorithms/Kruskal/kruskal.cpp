#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

struct Edge {
	int vertex;
	int weight;
	Edge *next;
	Edge() : vertex ( 0 ), weight ( 0 ), next ( NULL ) {}
	Edge ( int vertex, int weight ) : vertex ( vertex ), weight ( weight ) {}
	Edge ( int vertex ) : vertex ( vertex ), weight ( 0 ) {}
	void setValue ( int vertex ) {
		this->vertex = vertex;
		this->weight = 0;
	}
};

struct UnionFindSet {
	int parent;
	int rank;
	UnionFindSet() {}
	UnionFindSet ( int parent ) : parent ( parent ), rank ( 0 ) {}
	void setValue ( int parent ) {
		this->parent = parent;
		this->rank = 0;
	}
};

struct EdgeVertex {
	int start;
	int end;
	int cost;
	EdgeVertex() {}
	EdgeVertex ( int start, int end, int cost ) : start ( start ), end ( end ), cost ( cost ) {}
};

int cmp ( const void *a , const void *b ) {
	EdgeVertex *c = ( EdgeVertex* ) a;
	EdgeVertex *d = ( EdgeVertex* ) b;
	if ( c->cost != d->cost )
		return c->cost - d->cost;
	else
		return 0;
}

class GraphForMST2 {
public:
	GraphForMST2() {}

	GraphForMST2 ( char *vertex, Edge *e , int n ) {
		this->n = n;
		this->path = new Edge[n];
		this->vertex = new char[n];
		for ( int i = 0; i < n; i++ ) {
			this->vertex[i] = vertex[i];
			this->path[i].setValue ( i );
		}

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

	~GraphForMST2() {
		delete[] this->vertex;
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
		for ( int i = 0; i < n; i++ ) {
			next = ( this->path + i )->next;
			while ( next ) {
				current = next;
				next = next->next;
				delete current;
			}
		}
		delete[] this->path;
	}

	void Kruskal() {
		makeSet();
		int count = 0;
		EdgeVertex *list = edgeSort ( &count );
		for ( int i = 0; i < count; i++ ) {
			if ( Find ( list[i].start ) != Find ( list[i].end ) ) {
				Edge *temp = new Edge ( list[i].start );
				temp->next = ( path + list[i].end )->next;
				( path + list[i].end )->next = temp;
			}
			Union ( list[i].start, list[i].end );
		}
	}

	void showMST() {
		for ( int i = 0; i < n; i++ ) {
			if ( ( path + i )->next == NULL )
				continue;
			Edge *next = ( this->path + i )->next;
			while ( next ) {
				cout << vertex[i] << "<-->" << vertex[next->vertex] << endl;
				next = next->next;
			}
		}
	}

private:
	EdgeVertex* edgeSort ( int *count ) {
		vector<EdgeVertex> sortList;
		for ( int i = 0; i < n; i++ ) {
			Edge *temp = ( edge + i )->next;
			while ( temp ) {
				if ( temp->vertex < i ) {
					temp = temp->next;
					continue;
				} else {
					sortList.push_back ( EdgeVertex ( i, temp->vertex, temp->weight ) );
					temp = temp->next;
				}
			}
		}
		*count = sortList.size();
		EdgeVertex *list = new EdgeVertex[*count];
		for ( int i = 0; i < *count; i++ )
			list[i] = sortList[i];
		qsort ( list, *count, sizeof ( list[0] ), cmp );
		return list;
	}

	void makeSet() {
		this->set = new UnionFindSet[n];
		for ( int i = 0; i < n; i++ )
			set[i].setValue ( i );
	}

	int Find ( int vertex ) {		//optimize with path compression
		int temp = vertex;
		while ( set[temp].parent != temp )
			temp = set[temp].parent;
		int root = temp;
		while ( vertex != root ) {
			temp = vertex;
			vertex = set[vertex].parent;
			set[temp].parent = root;
		}
		return root;
	}

	void Union ( int start, int end ) {
		int rootStart = Find ( start );
		int rootEnd = Find ( end );
		if ( rootStart == rootEnd )
			return;
		if ( set[start].rank > set[end].rank )
			set[end].parent = rootStart;
		else {
			set[start].parent = rootEnd;
			if ( set[start].rank == set[end].rank )
				set[end].rank++;
		}
	}

private:
	char *vertex;
	Edge *edge;
	int n;			//to note down the amount of the vertex
	Edge *path;		//mark the path
	UnionFindSet* set;//the union-find-set
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

	GraphForMST2 g ( vertex, edge, 6 );

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

	g.Kruskal ();
	g.showMST();

	return 0;
}
