/*
Name: Minimum Spanning Tree (Kruskal's Algorithm)
Description: Finding the minimum spanning tree in a graph
Division: Graph Theory

Note: DSU data structure will be used
*/



// Data and functions for Disjoint Set Union
int par[ MAX_N ];
int parent( int node )
{
    if( par[node]!=node ) par[node] = parent( par[node] );
    return par[node];
}

// Data and functions for MST Algorithm
struct edge
{
    int u,v,c;
    edge(int x,int y,int k)
    {
        u=x, v=y, c=k;
    }
};
vector <edge> e; // edge list
int n; // number of nodes

bool compare(edge a,edge b) // for sorting the edges in weight accending order
{
    return a.w<b.w;
}

void init()
{
    for( int i=0; i<n; i++ ) par[i]=i; // parent clearing
    sort( e.begin(), e.end(), compare ); // sorting the edges
}




int mst()
{
    init();
    int MST=0, connected_nodes=0;

    for( int i=0; i<e.size() && connected_nodes!=n-1; i++ )
    {
        int u=e[i].u, v=e[i].v, c=e[i].c;
        if( parent(u) != parent(v) )
        {
            par[ parent(u) ] = parent(v);
            MST += c;
            connected_nodes++;
        }
    }

    return MST;
}
