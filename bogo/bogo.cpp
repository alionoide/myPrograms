#include "bogo.h"

//write functions here

void shuffleArray( int array[], int size)
{
    int i;

    static default_random_engine engine( time(0) );
    uniform_int_distribution<int> pos(0,size-1);

    for ( i = 0; i < size; i++)
    {
        swap( array[ pos(engine) ], array[ pos(engine) ] );
    }
    
}

bool arraySorted( int array[], int size)
{
    int i;

    for( i = 0; i < size - 1; i++ )
        if( array[i] > array[i + 1] )
            return false;
    return true;
}

void displayArray( int array[], int size )
{
    int i;

    for ( i = 0; i < size; i++)
    {
        cout << array[i] << ", ";
    }

    cout << endl;
}