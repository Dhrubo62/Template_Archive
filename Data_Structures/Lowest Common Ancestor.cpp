/*
Lowest Common Ancestor
*/

int n, p[100][100], maxi, l[100];
vi g[100];
bool visit[100];

void dfs( int node, int level ) {
    visit[node] = true;
    l[node] = level;
    for( int i=0; i<g[node].size(); i++ ) {
        int v = g[node][i];
        if( !visit[v] ) {
            p[v][0]=node;
            dfs(v , level+1 );
        }
    }
}

void init( int root ) {
    memo(visit,false);
    p[root][0] = -1;
    dfs(root, 0);  // filling 2^0 parent of sparse table and node levels

    maxi=0;
    for( int pow=1; (1<<pow)<n; pow++ ) {   // filling all the other columns of the table
        maxi = pow;
        for( int u=0; u<n; u++ ) {
            if( p[u][pow-1]!=-1 ) p[u][pow] = p[ p[u][pow-1] ][pow-1];
            else p[u][pow] = -1;
        }
    }
}

int LCA( int u, int v ) {
    // carrying up u and v to the same level
    if( l[u] < l[v] ) { int temp=u; u=v; v=temp; }  // if u has low level = u is higher than v
    for( int pow=maxi; pow>=0; pow-- ) {
        if( l[u]-(1<<pow) >= l[v] ) u = p[u][ pow ];
    }

    if( u==v ) return u;    // happens when one of them is a parent of another

    // carrying up them both to their common parent
    for( int pow=maxi; pow>=0; pow-- ) {
        if( p[u][pow]!=-1 && p[u][pow]!=p[v][pow] ) {
            u = p[u][pow];
            v = p[v][pow];
        }
    }
    return p[u][0];
}
