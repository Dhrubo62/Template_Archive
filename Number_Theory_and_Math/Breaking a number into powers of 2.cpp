/*
Name: Powers of 2 in a number
Purpose: 1. Breeaking a number into powers of 2
         2. Getting the bit positions of 1 in a number's binary representation
*/

long long num; cin>>num; // the number to be checked
long long i=1; /* everytime this number is compared in a &(AND) operation
with the number */

while( i<=num ) { // as long as i does not exceed the number
    if( num & i ) cout << i << " "; /* here i is compared in a & operation
    e.g.
    num = 1001101101
    i =   0000001000
    i has only one 1 in it. beacuse of the rules of AND operation all the bits
    int i which has 0 will return 0 and the 1 will return 1 if and only if the
    num has 1 in the same bit
    so if the num has 1 in the same bit, the result of the operation will be i

    num = 10001001
    i =   00001000
    --------------
    & =   00001000

    else AND will return 0
    */

    i = i << 1;
    /* everytime i's bit position is shifted one step in left.
    so i is being multiplied by 2

    before = 000010
    after =  000100

    the 1's position is being changed and in the next iteration num will be checked
    for this new position
    */
}
cout << endl;
