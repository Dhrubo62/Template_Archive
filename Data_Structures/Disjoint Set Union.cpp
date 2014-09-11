/*
Name: Disjoint Set Union
Description: To save and retrieve information about two nodes being connected
             through some path.
Devision: Data Structures, Graph Theory
*/

int par[ MAX_N ]; // to save the parents of the nodes
int n; // number of nodes

void init()
{
    for( int i=0; i<n; i++ ) par[i] = i; // making everyone their own parent
}

int parent( int node )
{
    if( par[node]!=node ) par[node] = parent( par[node] ); // for saving topmost parent
    return par[node];
}

bool find_connected( int u, int v )
{
    if( parent(u) == parent(v) ) return true; // u and v are under same parent so they are connected
    return false;
}

void make_union( int u, int v )
{
    par[ parent(u) ] = parent(v); // making v's parent the parent of u's parent
                                  // so they will be under same parents (v's parent)
}
