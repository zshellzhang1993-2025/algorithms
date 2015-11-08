#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include <limits.h>
using namespace std;

struct Edge {
    int vertex;
    int weight;
    Edge ( int v, int w ) : v ( v ), weight ( w ) {}
};

struct Vertex {
    char name;
    list<Edge> *edges;
    Vertex ( char n, list<Edge> *e ) : name ( n ), edges ( e ) {}
}

class Graph {
    int v_num;
    list<Edge> *edges;
    void topologicalSort ( int v, bool visited[], stack<int> &stk );
public:
    Graph ( int v_num );
    virtual ~Graph();
    void addEdge ( int u, int v, int weight );
    void shortestPath ( int s, vector<int> &path );
};

int main() {
    Graph g ( 6 );
    g.addEdge ( 0, 1, 1 );
    g.addEdge ( 0, 3, 2 );
    g.addEdge ( 1, 2, 6 );
    g.addEdge ( 3, 1, 4 );
    g.addEdge ( 3, 4, 3 );
    g.addEdge ( 2, 4, 1 );
    g.addEdge ( 2, 5, 2 );
    g.addEdge ( 4, 5, 1 );
    int s = 0;
    cout << "Shortest distances from source " << s << " \n";

    vector<int> path;
    g.shortestPath ( s, path );

    return 0;
}


Graph::Graph ( int v_num ) {
    this->v_num = v_num;
    adj = new list<AdjListNode>[v_num];
}

Graph::~Graph() {
    delete adj;
}

void Graph::addEdge ( int u, int v, int weight ) {
    AdjListNode node ( v, weight );
    adj[u].push_back ( node );
}

void Graph::topologicalSort ( int v, bool visited[], stack<int> &stk ) {
    visited[v] = true;
    list<AdjListNode>::iterator it;
    for ( it = adj[v].begin(); it != adj[v].end(); ++it ) {
        AdjListNode node = *it;
        if ( !visited[node.getV()] )
            topologicalSortRecall ( node.getV(), visited, stk );
    }
    stk.push ( v );
}

void Graph::shortestPath ( int s, vector<int> &path ) {
    stack<int> stk;
    int dist[v_num];
    int min_vex;

    bool *visited = new bool[v_num];
    for ( int i = 0; i < v_num; i++ )
        visited[i] = false;

    for ( int i = 0; i < v_num; i++ )
        if ( visited[i] == false )
            topologicalSortRecall ( i, visited, stk );

    for ( int i = 0; i < v_num; i++ )
        dist[i] = INT_MAX;
    dist[s] = 0;
    path.push_back ( s );

}
