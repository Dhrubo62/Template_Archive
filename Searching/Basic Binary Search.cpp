/*
Name: Binary Search
Purpose: To search an element in a sorted array
Division: Searching Algorithms
*/

int arr[MAX_N], n; // the sorted array and size of it

// this version searches if a number exists in the array
void srch( int num ) {
    int lo=0, hi=n-1;
    while( lo<=hi ) {
        int mid=(lo+hi)/2;
        if( arr[mid]==num ) return true;
        else if( arr[mid]<num ) lo=mid+1;
        else hi=mid-1;
    }
    return false;
}

// this version searches the lowest index in the array that holds the number
void low( int num ) {
    int lo=0, hi=n-1, best=-1;
    while( lo<=hi ) {

        int mid=(lo+hi)/2;

        /*
        // if greater than the number
        lo.............mid.............hi
        ......num........................

        // if equal to the number but to search for lower indices
        lo............mid..............hi
        .....num......num................

        in both cases the left portion is to be searched
        */

        if( arr[mid]>=num ) {
            if( arr[mid]==num ) best=mid;
            hi=mid-1;
        } else lo=mid+1;
    } return best;
}

// this version searches for the highest index in the array that holds the number
void high( int num ) {
    int lo=0, hi=n-1, best=-1;
    while( lo<=hi ) {
        int mid=( lo+hi )/2;

        /*
        // if less than the number
        lo............mid..............hi
        .....................num.........

        // if equal to the number but to search for higher indices
        lo.............mid................hi
        ...............num......num.........

        in both cases the right portion is to be searched
        */
        if( arr[mid]<=num ) {
            if( arr[mid]==num ) best=mid;
            lo=mid+1;
        } else hi=mid-1;
    } return best;
}


