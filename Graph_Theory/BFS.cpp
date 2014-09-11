/*
Name: Breadth First Search
Purpose: Graph Traversal
Division: Graph Theory
*/

struct pack
{
    int node;
    int cost;
    pack( int x, int y ) { node=x; cost=y; }
};

// global variables
vector <int> graph[ MAX_N ]; // adjacency list of the graph
bool visit[ MAX_N ]; // for keeping track of which node has been visited already
queue <pack> q;

int bfs( int Start, int End )
{
    // initailization
    memset( visit, false, sizeof visit );

    // algorithm
    q.push( pack( Start, 0 ) ); visit[ Start ]=true;
    while( !q.empty() )
    {
        pack now=q.front(); q.pop();

        if( now.node==End ) return now.cost;

        int u=now.node, c=now.cost;
        for( int i=0; i<graph[u]; i++ )
        {
            int v=graph[u][i];
            if( !visit[v] ) { q.push( pack( v, c+1 ) ); visit[v]=true; }
        }
    }

    // if end has not been visited yet
    return -1;
}

