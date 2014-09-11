/*
Name: Depth First search
Description: Recursion Based Graph Traversal
Section: Graph Theory
*/

// global variables
vector <int> graph[ MAX_N ]; // adjacency list of the graph
bool visit[ MAX_N ]; // for keeping track of which node has been visited already

void dfs( int node )
{
    visit[node] = true;
    for( int i=0; i<graph[node].size(); i++ )
    {
        int dest = graph[node][i];
        if( !visit[dest] ) dfs( dest );
    }
}

int main( void )
{
    memset( visit, false, sizeof visit );
    dfs( starting_node );
}
