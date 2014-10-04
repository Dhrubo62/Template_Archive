/*
Name: Segment Tree (basic)
Purpose: Let some numbers are stored in an array. This data structure creates
         and utilizes a tree from the array where each node contains the sum of a particular
         segment (from one index to some other) of the array .
Division: Data Structures
*/

long long n; // number of elements in the array
long long arr[ MAX ]; // the main array
long long tree[ MAX*3 ]; // the tree

// constructing the tree
// here Start is the node at present, Start and End marks the segment of the array for this node
void make_tree( int node, int Start, int End ) {
    // if it is a leaf node then the size of the segment is one
    // so the value is directly stored
    if( Start==End ) { tree[node]=arr[Start]; return; }

    // the left node, the right node and the middlepoint of the curent segment
    int left=node*2; int right=left+1;
    int mid=( Start+End )/2;

    // constructing child nodes
    make_tree( left, Start, mid );
    make_tree( right, mid+1, End );

    // a segment's value is the sum of the child segements' values
    tree[node] = tree[left] + tree[right];
}

// finding the sum of a segment
// node,Start,End mark the cureent node of tree just as previous
// i and j are the starting and ending index of the segment of the array whose sum needs to calculated
long long sum( int node, int Start, int End, int i, int j ) {
    // if the cureent segment is fully inside the required segment it's relevant
    if( Start>=i && End<=j ) return tree[node];
    // if the current segment is totally out of range then it's irrelevant
    if( End<i || Start>j ) return 0;

    // else the current segment contains part of the required statement
    // so we have go deeper in the tree from this node to find the relevant segment/s
    int left=node*2; int right=left+1;
    int mid=( Start+End )/2;
    return sum( left, Start, mid, i, j )+sum( right, mid+1, End, i, j );
}


// updating a single index in the array
// also updating the values of the segments containing this index
// i ia the index and val is the value to put there
void update( int node, int Start, int End, int i, int val ) {
    // if the current segment does not contain the index
    if( Start>i || End<i ) return;
    // if we have reached the exact node containing the value
    if( Start==i && i==End ) { tree[node]=val; return; }

    // if the current segment contains the index then we go deeper and
    // also update the sum value of this node later
    int left=node*2; int right=left+1;
    int mid=( Start+End )/2;
    update( left, Start, mid, i, val );
    update( right, mid+1, End, i, val );

    tree[node] = tree[left] + tree[right];
}
