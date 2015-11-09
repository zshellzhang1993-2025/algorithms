#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include <limits.h>
using namespace std;

struct Edge {
    int vertex;
    int weight;
    Edge ( int v, int w ) : vertex ( v ), weight ( w ) {}
};

struct Vertex {
    char name;
    list<Edge> inDegrees;
    Vertex() {}
    Vertex ( char n, list<Edge> e ) : name ( n ), inDegrees ( e ) {}
};

class Graph {
    int v_num;
    Vertex *vertex;
    void topologicalSort ( int v, bool visited[], vector<int> &seq );

public:
    Graph ( int v_num );
    virtual ~Graph();
    void addEdge ( int u, int v, int weight );
    void shortestPath ( vector<char> &path );
};

int main() {
    Graph g ( 6 );
    g.addEdge ( 1, 0, 1 );
    g.addEdge ( 3, 0, 2 );
    g.addEdge ( 2, 1, 6 );
    g.addEdge ( 1, 3, 4 );
    g.addEdge ( 4, 3, 3 );
    g.addEdge ( 4, 2, 1 );
    g.addEdge ( 5, 2, 2 );
    g.addEdge ( 5, 4, 1 );

    //int begin = 0;
    //int end = 5;
    //cout << "Shortest path from source " << begin << " to " << end << "\n";

    vector<char> path;
    g.shortestPath ( path );

    for ( vector<char>::iterator iter = path.begin(); iter != path.end(); iter++ )
        cout << *iter << '\t';
    cout << endl;

    return 0;
}


Graph::Graph ( int v_num ) {
    this->v_num = v_num;
    vertex = new Vertex[v_num];
    for ( int i = 0; i < v_num; i++ )
        vertex[i].name = ( char ) ( 65 + i );
}

Graph::~Graph() {
    delete vertex;
}

void Graph::addEdge ( int u, int v, int weight ) {
    Edge edge ( v, weight );
    vertex[u].inDegrees.push_back ( edge );
}

void Graph::topologicalSort ( int v, bool visited[], vector<int> &seq ) {
    visited[v] = true;
    for ( list<Edge>::iterator iter = vertex[v].inDegrees.begin();
            iter != vertex[v].inDegrees.end(); iter++ ) {
        int adjVertex = iter->vertex;
        if ( !visited[adjVertex] )
            topologicalSort ( adjVertex, visited, seq );
    }
    seq.push_back ( v );
}

void Graph::shortestPath ( vector<char> &path ) {
    vector<int> seq;
    int dist[v_num];
    int min = 0;

    bool *visited = new bool[v_num];
    for ( int i = 0; i < v_num; i++ )
        visited[i] = false;

    for ( int i = 0; i < v_num; i++ )
        if ( visited[i] == false )
            topologicalSort ( i, visited, seq );

    for ( int i = 0; i < v_num; i++ )
        dist[i] = 0;

    for ( vector<int>::iterator iter = seq.begin() + 1; iter != seq.end(); iter++ ) {
        min = INT_MAX;
        for ( list<Edge>::iterator it = vertex[*iter].inDegrees.begin();
                it != vertex[*iter].inDegrees.end(); it++ ) {
            if ( dist[it->vertex] + it->weight < min )
                min = dist[it->vertex] + it->weight;
        }
        dist[*iter] = min;
    }

    int target = seq[v_num - 1];
    stack<int> stk;
    stk.push ( target );

    while ( target != seq[0] ) {
        for ( list<Edge>::iterator iter = vertex[target].inDegrees.begin();
                iter != vertex[target].inDegrees.end(); iter++ ) {
            if ( dist[target] == dist[iter->vertex] + iter->weight ) {
                stk.push ( iter->vertex );
                target = iter->vertex;
            }
        }
    }
    stk.push ( target );
    while ( !stk.empty() ) {
        path.push_back ( vertex[stk.top()].name );
        stk.pop();
    }
}
