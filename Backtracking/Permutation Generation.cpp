/*
Name: Permutation Generation
Division: Backtracking
Purpose: To generate all permutations of a given set
*/

int list[MAX]; // the set
int n; // total number of objects on the set
int r; // total number of objects on the permutation
int res[MAX]; // result array to hold permutation
bool take[MAX];

void permute() {
    if( sz==r ) { // permutation ready to be printed
        // print the result array
        return;
    }

    for( int i=0; i<n; i++ ) {
        if( !take[i] ) { // i has not been taken yet so we take it
            take[i] = true; // taking the element
            res[sz++] = list[i]; // adding it to the permutation

            permute(); // solving for the rest

            take[i] = false; // after calculation drop the item for later use
            sz--; // removing it from the permutation
        }
    }
}

int main() {
    sz=0; // clearing the result array
    permute();
}
