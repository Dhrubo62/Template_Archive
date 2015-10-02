/*
Name: Longest Increasing Subsequence
Division: Dynamic Programming
Purpose: From a given sequence, finding the largest sequence that is increasing
         by values of members but contains the original order between the members

Note: Iterative process. Complexity O(n^2)
*/

ll n, val[MAX], dp[MAX], next[MAX], max_ind, max_len;

void LIS() {
    max_ind=0, max_len=1;
    rep(i,n) { dp[i]=1; next[i]=-1; }

    // backward loop
    repr(i,n) {
        // backward loop
        repr(j,i) if( val[j]<val[i] && dp[j]<dp[i]+1 ) {
            dp[j] = dp[i] + 1;
            next[j] = i;
            if( dp[j]>max_len ) {
                max_len=dp[j];
                max_ind=j;
            }
        }
    }
}

void PRINT() {
    printf( "Size: %lld\n", max_len );
    while( max_ind!=-1 ) {
        printf( "%lld\n", val[max_ind] );
        max_ind = next[max_ind];
    }
}
