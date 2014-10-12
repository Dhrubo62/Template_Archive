/*
Name: Length Union of given Line Segments
Division: Geometry
Description: Given starting and ending points of line segments in 1D, it calculates
             the length union of the segments.
             An application of Interval Scheduling Greedy.
*/

int n; // number of segments
vector < pair<int,bool> > v; // the start and end points stored

int len() {
    sort( v.begin(), v.end() ); // sorting the points
    /* For points with same value, placing an start point before
    an end point or vise varsa both will be correct in this algo
    unlike the original Interval Scheduling Greedy algorithm */
    int ttl=0, seg=0;
    for( int i=0; i<(n<<1); i++) {
        if( seg ) ttl += v[i].ff - v[i-1].ff; /* if at least one
        segment is ongoing then a little part is to be added */

        if( v[i].ss ) seg++;
        else seg--;
    }
    return ttl;
}

int main() {

    // inputing the points
    cin>>n;
    for( int i=0; i<n; i++ ) {
        int t;
        cin>>t; v.push_back( pair<int,bool>(t,true) );
        cin>>t; v.push_back( pair<int,bool>(t,false) );
    }

    cout << len() << endl;

    return 0;
}
