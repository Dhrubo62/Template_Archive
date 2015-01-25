/*
Name: Strongly Connected Components (Kosaraju's algorithm)
Catagory: Graph Theory
*/

vector <int> g[MAX], gr[MAX], component;
bool visit[MAX];
int n, m;
stack <int> order;

void dfs1( int u ) {
    visit[u]=true;
    for( int i=0; i<g[u].size(); i++ ) if( !visit[ g[u][i] ] ) dfs1( g[u][i] );
    order.push( u );
}

void dfs2( int u ) {
    visit[u]=true;
    component.push_back(u);
    for( int i=0; i<gr[u].size(); i++ ) if( !visit[ gr[u][i] ] ) dfs2( gr[u][i] );
}

int main() {

    //read;

    n=II; m=II;
    for( int i=0; i<m; i++ ) {
        int u=II, v=II;
        g[u].push_back(v);
        // reverse graph
        gr[v].push_back(u);
    }

    // first dfs
    for( int i=0; i<n; i++ ) if( !visit[i] ) dfs1(i);

    // second dfs
    memo(visit,false);
    while( !order.empty() ) {
        if( !visit[ order.top() ] ) {
            component.clear();
            dfs2( order.top() );

            // printing components
            for( int i=0; i<component.size(); i++ ) cout << component[i] << " ";
            cout << endl;
        }
        order.pop();
    }

    return 0;
}
