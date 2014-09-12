/*
Name: Trie (Prefix Tree) - Linked List implementation
Purpose: Storing and searching strings in a directory with complexity
         equal to the string's length
Division: Data Structures
*/

struct node
{
    bool endmark;
    node *next[ MAX_CHAR ];
    node()
    {
        endmark=false;
        for( int i=0; i<MAX_CHAR; i++ ) next[i]=NULL;
    }
} *root ;

void add( char *str )
{
    int len = strlen( str );
    node *cur = root;
    for( int i=0; i<len; i++ )
    {
        int ch = str[i] - VALUE_OF_FIRST_CHAR_IN_THE_RANGE; // for using as index
        if( cur->next[ch] == NULL ) cur->next[ch] = new node();
        cur = cur->next[ch];
    }
    cur->endmark = true;
}

bool srch( char *str )
{
    int len = strlen( str );
    node *cur = root;
    for( int i=0; i<len; i++ )
    {
        int ch = str[i] - VALUE_OF_FIRST_CHAR_IN_THE_RANGE; // for using as index
        if( cur->next[ch] == NULL ) return false;
        cur = cur->next[ch];
    }
    return cur->endmark;
}

void del( node *cur )
{
    for( int i=0; i<MAX_CHAR; i++ ) if( cur->next[i] != NULL ) del( cur->next[i] );
    delete( cur );
}

int main(void)
{
    root = new node();
    // using the structure....
    del( root ); // cleaning the tree
}
