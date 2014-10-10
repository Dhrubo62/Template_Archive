/*
Name: Checking on the acyclic graph and finding a cycle
Purpose: Checks on a graph if there exists any cycle in it. If finds a cycle
         prints the cycle. ( can print only one cycle from the graph, no all )
Division: Graph Theory (an implementation of dfs)
*/

vint g[100]; // the graph in adjacency list
int clr[100], p[100], n, m, Start, End; // color, parent, vertices, edges, start and end point of cycle

bool dfs( int u ) {
    clr[u] = 1; // 1 means a dfs has started from this vertice but hasnot ended yet
    rep( i, sz( g[u] ) ) {
        int v = g[u][i];
        if( clr[v]==0 ) { // 0 means it has not yet been visited any time
            p[v]=u; // making path
            if( dfs(v) ) return true;
        }
        else if( clr[v]==1 ) { // 1 means a dfs was started from this vertice and has reached this vertice again before ending
                               // we can smell a cycle here XD
            Start = v; End = u;
            return true;
        }
    }
    clr[u]=2; // 2 means everything that could possibly be done has been done for this vertice
    return false;
}

int main( void ) {
    set_values { clr[ALL]=0; p[ALL]=-1; }
    input_graph();

    arep( i, n ) if( dfs(i) ) break; // trying to start dfs from all possible vertices

    if( Start==-1 ) { cout<<"no cycle"<<endl; return 0; }

    // constructing the path
    vint path;
    pb( path, Start );
    for( int node=End; node!=Start; node=p[node] ) pb( path, node );
    pb( path, Start );

    revp( path ); // reverse to get original direction
    rep( i, sz( path ) ) cout << path[i] << " "; cout << endl; // print
}
