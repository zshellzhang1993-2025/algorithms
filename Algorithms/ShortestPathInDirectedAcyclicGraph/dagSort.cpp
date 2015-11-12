#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include <limits.h>
using namespace std;

struct Edge {
    int vertex_num;
    int weight;
    Edge ( int v, int w ) : vertex_num ( v ), weight ( w ) {}
};

struct Vertex {
    char name;
    list<Edge> inDegrees;
};

struct Topo {
    int vertex_num;
    bool explored;
    Topo ( int v, bool e ) : vertex_num ( v ), explored ( e ) {}
};

class Graph {
    Vertex *vertex;
    int v_num;
    bool topologicalSort ( int begin, int end, vector<int> &seq );

public:
    Graph ( int v_num );
    virtual ~Graph();
    void addEdge ( int u, int v, int weight );
    bool shortestPath ( int begin, int end, vector<char> &path );
    char getVertexName ( int num );
};

int main() {
    Graph g ( 6 );
    g.addEdge ( 1, 0, 1 );
    g.addEdge ( 3, 0, 2 );
    g.addEdge ( 2, 1, 1 );
    g.addEdge ( 1, 3, 4 );
    g.addEdge ( 4, 3, 3 );
    g.addEdge ( 4, 2, 1 );
    g.addEdge ( 5, 2, 4 );
    g.addEdge ( 5, 4, 1 );

    int begin = 0;
    int end = 4;
    cout << "Shortest path from source " << g.getVertexName ( begin ) << " to " <<
         g.getVertexName ( end ) << "\n";

    vector<char> path;
    if ( g.shortestPath ( begin, end, path ) ) {
        for ( vector<char>::iterator iter = path.begin(); iter != path.end(); iter++ )
            cout << *iter << '\t';
        cout << endl;
    } else
        cout << "have no shortest path!" << endl;

    return 0;
}


Graph::Graph ( int v_num ) {
    this->v_num = v_num;
    vertex = new Vertex[v_num];
    for ( int i = 0; i < v_num; i++ )
        vertex[i].name = ( char ) ( 65 + i );
}

Graph::~Graph() {
    //delete vertex;
}

char Graph::getVertexName ( int num ) {
    return vertex[num].name;
}

void Graph::addEdge ( int u, int v, int weight ) {
    Edge edge ( v, weight );
    vertex[u].inDegrees.push_back ( edge );
}

bool Graph::topologicalSort ( int begin, int end, vector<int> &seq ) {

    bool *visited = new bool[v_num];
    for ( int i = 0; i < v_num; i++ )
        visited[i] = false;

    int explore_at = -1;
    vector<Topo> stk;//just use vector to simulate stack
    int current = 0;

    while ( !stk.empty() || explore_at < v_num ) {
        if ( !stk.empty() ) {
            if ( !stk[stk.size() - 1].explored ) {
                current = stk[stk.size() - 1].vertex_num;
                stk[stk.size() - 1].explored = true;
                visited[current] = true;
                for ( list<Edge>::iterator iter = vertex[current].inDegrees.begin();
                        iter != vertex[current].inDegrees.end(); iter++ ) {
                    if ( !visited[iter->vertex_num] )
                        stk.push_back ( Topo ( iter->vertex_num, false ) );
                    else {
                        vector<Topo>::iterator it;
                        for (  it = stk.begin(); it != stk.end(); it++ ) {
                            if ( iter->vertex_num == it->vertex_num )
                                return false;
                        }
                    }
                }
            } else {
                current = stk[stk.size() - 1].vertex_num;
                if ( current == begin )
                    seq.push_back ( current );
                else if ( current == end ) {
                    if ( !seq.size() )
                        return false;
                    else {
                        seq.push_back ( current );
                        return true;
                    }
                } else if ( seq.size() != 0 )
                    seq.push_back ( current );

                stk.pop_back();
            }
        } else if ( explore_at < v_num ) {
            explore_at++;
            if ( !visited[explore_at] )
                stk.push_back ( Topo ( explore_at, false ) );
        }
    }
    return false;
}

bool Graph::shortestPath ( int begin, int end, vector<char> &path ) {
    vector<int> seq;
    int dist[v_num];
    int min = 0;

    if ( !topologicalSort ( begin, end, seq ) )
        return false;

    for ( int i = 0; i < v_num; i++ )
        dist[i] = -1;
    dist[seq[0]] = 0;

    for ( vector<int>::iterator iter = seq.begin() + 1; iter != seq.end(); iter++ ) {
        min = INT_MAX;
        for ( list<Edge>::iterator it = vertex[*iter].inDegrees.begin();
                it != vertex[*iter].inDegrees.end(); it++ ) {
            if ( dist[it->vertex_num] != -1 && dist[it->vertex_num] + it->weight < min )
                min = dist[it->vertex_num] + it->weight;
        }
        dist[*iter] = min;
    }

    int target = seq[seq.size() - 1];
    stack<int> stk;
    stk.push ( target );

    while ( target != seq[0] ) {
        for ( list<Edge>::iterator iter = vertex[target].inDegrees.begin();
                iter != vertex[target].inDegrees.end(); iter++ ) {
            if ( dist[iter->vertex_num] != -1
                    && dist[target] == dist[iter->vertex_num] + iter->weight ) {
                stk.push ( iter->vertex_num );
                target = iter->vertex_num;
                break;
            }
        }
    }

    while ( !stk.empty() ) {
        path.push_back ( vertex[stk.top()].name );
        stk.pop();
    }

    return true;
}
