//{ ---------- C headers
# include <cstdio>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <cctype>
//}

//{ ---------- C++ headers
# include <iostream>
# include <string>
# include <algorithm>
# include <vector>
# include <queue>
# include <stack>
# include <map>
# include <sstream>
# include <set>
# include <utility>
//}
using namespace std;

//{ ---------- Types
# define ll long long
# define ff first
# define ss second
//}

//{ ---------- Input
# define II ( { int a; scanf("%d",&a); a; } )
# define LL ( { ll a; scanf("%lld",&a); a; } )
# define DD ( { double a; scanf("%lf",&a); a; } )
//}

//{ ---------- Misc Functions
# define sqr( a ) a*a
# define cube( a ) a*a*a
# define memo( a, x ) memset( a, x, sizeof a )
//}

//{ ---------- I/O Streams
# define read freopen("input.txt","r",stdin)
# define write freopen("output.txt","w",stdout)
//}

//{ ---------- Constants
# define inf( a, type ) type a = pow( 2, 8*sizeof( type )-1 )-1
//}

//{ ---------- Movements
/*int dx[]={1,-1,0,0}, dy[]={0,0,1,-1};*/ // 4 way movement
/*int dx[]={1,0,-1,0,1,-1,1,-1}, dy[]={0,1,0,-1,1,1,-1,-1};*/ // 8 way movement
//}

//---------------------------------- Start of the program

# define MAX 100

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
