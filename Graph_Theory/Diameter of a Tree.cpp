/*
Name: Finding diameter of a tree
Catagory: Graph Theory
*/

vector <int> g[MAX];
int max_cost, most_distant_node, d1, d2;
bool visit[MAX];

void dfs( int u, int cost ) {
    visit[u]=true;
    if( cost>max_cost ) { max_cost=cost; most_distant_node=u; }

    for( int i=0; i<g[u].size(); i++ ) {
        int v=g[u][i];
        if( !visit[v] ) dfs( v, cost+1 );
    }
}

int main() {
    /*
    Theory: The most distant node from any node of the tree is either one of the two
            diameter nodes of the tree
    */
    // starting from any node and finding its most distant node
    memo(visit,false);
    max_cost=0;
    dfs( any_node, 0 );

    // now we have got one of the two diameters in most_distant_node
    d1 = most_distant_node;

    // to find the other one we just need to run a dfs from here
    memo(visit,false);
    max_cost=0;
    dfs( d1, 0 );

    d2 = max_distant_node;

    return 0;
}
