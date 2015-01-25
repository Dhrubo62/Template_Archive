/*
Longest Common Subsequence
*/

char str[2][1000], ans[1000], sz;
int dp[1000][1000], dir[1000][1000];
bool visit[1000][1000];

int call( int i, int j ) {
    if( str[0][i]=='\0' || str[1][j]=='\0' ) return 0;
    if( visit[i][j] ) return dp[i][j];

    visit[i][j]=true;
    if( str[0][i]==str[1][j] ) return dp[i][j] = 1 + call(i+1,j+1);
    else return dp[i][j] = max( call(i+1,j), call(i,j+1) );
}

void print( int i, int j ) {
    if( str[0][i]=='\0' || str[1][j]=='\0' ) {
        ans[sz]='\0';
        cout << ans << endl;
        return;
    }

    if( str[0][i]==str[1][j] ) {
        //if( ans[sz]==str[0][i] ) return;
        ans[sz++]=str[0][i];
        print( i+1, j+1 );
        sz--;
    } else if( dp[i+1][j] > dp[i][j+1] ) print( i+1 , j );
    else if( dp[i+1][j] < dp[i][j+1] ) print( i, j+1 );
    else {
        print( i+1, j );
        print( i, j+1 );
    }
}

int main() {

    while( cin>>str[0]>>str[1] ) {
        memo(visit,false);
        cout << call(0,0) << endl;
        sz=0;
        memo(ans,0);
        print( 0, 0 );
    }

    return 0;
}
