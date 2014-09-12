/*
Name: Trie (Prefix Tree) - Array implementation
Purpose: Storing and searching strings in a directory with complexity
         equal to the string's length
Division: Data Structures
*/

struct node
{
    bool endmark;
    int next[ MAX_CHAR ];
    node()
    {
        endmark=false;
        for( int i=0; i<MAX_CHAR; i++ ) next[i]=-1;
    }
} trie[ MAX_N ] ;

int ttl;
void init() { ttl=0; trie[ttl++]=node(); } // initialization

void add( char *str )
{
    int len = strlen( str );
    int cur=0;
    for( int i=0; i<len; i++ )
    {
        int ch = str[i] - VALUE_OF_FIRST_CHAR_IN_THE_RANGE; // for using as index
        if( trie[cur].next[ch] == -1 )
        {
            trie[ ttl ] = node(); // creating new node
            trie[cur].next[ch] = ttl++; // linking the node to cur
        }
        cur = trie[cur].next[ch];
    }
    trie[cur].endmark = true;
}

bool srch( char *str )
{
    int len = strlen( str );
    int cur=0;
    for( int i=0; i<len; i++ )
    {
        int ch = str[i] - VALUE_OF_FIRST_CHAR_IN_THE_RANGE; // for using as index
        if( trie[cur].next[ch] == -1 ) return false;
        cur = trie[cur].next[ch];
    }
    return trie[cur].endmark;
}

int main(void)
{
    init();
    // using the structure....
}
