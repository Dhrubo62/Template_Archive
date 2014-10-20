/*
Name: Stable Marriage problem
Division: Graph Theory
Purpose: Too long to be explained. A way of connecting two sets of objects in one-on-one
         connection such that the connection is stable in terms of priority choice of the
         objects of the two sets
*/

int n;
// for him
queue <int> like[MAX]; /* for listing the serial of the girls for each one of the
                          boys */
// for her
int husband[MAX], prio[MAX][MAX]; // priority list for girls
                                  // priority of M for W is prio[W][M]
// for kaji office
queue <int> pola;

void kaji_office() {
    while( !pola.empty() ) {
        int m=pola.front(); // this man is unmarried
        int w=like[m].front(); like[m].pop(); // the top priority girl for this man
                                              // that he hasn't proposed yet
        int hus=husband[w]; // present husband of the girl

        if( !hus ) { // if the girl is alone then there is no problem to get married
            husband[w]=m;
            pola.pop();
        } else if( prio[w][m]<prio[w][hus] ) { // if the girl is married then she thinks
                                               // if she likes the man more than her husband
            husband[w] = m;
            pola.pop();
            pola.push( hus ); // divorced :v
        }
    }
}

int main() {

    cin>>n;
    // for him
    for( int i=1; i<=n; i++ ) {
        while( !like[i].empty() ) like[i].pop();
        for( int j=1; j<=n; j++ ) {
            int girl; cin>>girl;
            like[i].push( girl );
        }
        pola.push( i );
    }

    // for her
    for( int i=1; i<=n; i++ ) {
        husband[i]=0;
        for( int j=1; j<=n; j++ ) {
            int boy; cin>>boy;
            prio[i][boy]=j;
        }
    }

    kaji_office();

    for( int i=1; i<=n; i++ ) {
        cout << i << " " << husband[i] << endl;
    }

    return 0;
}
