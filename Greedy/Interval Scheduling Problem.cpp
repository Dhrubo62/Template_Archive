/*
Name: Interval Scheduling Problem
Purpose: A list of tasks is given with start and end time.
         The goal is to find maximum how many tasks need to be done at the same
         time if overlapping between the tasks is not possible.
Division: Greedy method
*/

// we have to sort the times of task starting and ending
struct task {
    long long time; // this will hold the time
    bool mark; // this is 0 if the time is start time
               // 1 if the time is a ending time
} point[MAX_N+MAX_N+10]; // array of times
int ind; // how many elements in the array
int n; // number of tasks

/* the process of the algorithm */

// input
ind=0;
for all the tasks {
    input-> Start, End; // start time and end time of the task

    point[ind].time=Start; point[ind++].mark=0; // pushing the starting time in the array
    point[ind].time=End; point[ind++].mark=1; // pushing the ending time in the array
}

// sorting
bool comp( task a, task b ) {
    if( a.time==b.time ) return a.mark<b.mark; /* this will put a starting time in front of
    an ending time with same time point.
    This is necesary in the general case where a task ends at a time T and at T another task starts
    but it is not possible to finish one and take one at the same time. In that case advancing a Start
    point over a End point in the array will contribute to the counting of overlapping. */

    else return a.time<b.time;
}

// counting process
int MAX=0, cnt=0;
sort( point, point+ind, comp );
for( int i=0; i<ind; i++ ) {
    if( point[i].mark==0 ) { cnt++; MAX=max(MAX,cnt); } // a task has started
    else cnt--; // a task has ended
}

MAX // is the must be done number of overlappings

