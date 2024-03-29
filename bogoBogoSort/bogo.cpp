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

void copyArray(int array[], int size, int dest[])
{
    for (size_t i = 0; i < size; i++)
    {
        dest[i] = array[i];
    }
}

bool compareArray(int array1[], int array2[], int size)
{
    for (size_t i = 0; i < size; i++)
    {
        if (array1[i] != array2[i])
        {
            return false;
        }
    }
    return true;
}
bool arraySortedBogo(int array[], int size)
{
    int* copy = nullptr;
    copy = new (nothrow) int[size];
    copyArray(array, size, copy);

    do
    {
        shuffleArray(copy, size);
        bogoBogo(copy, size - 1);
    } while (!(copy[size - 1] > copy[size - 2]));
    /*cout << endl;
    displayArray(copy, size);
    cout << "vs." << endl;
    displayArray(array, size);*/
    if (compareArray(array, copy, size))
    {
        delete[] copy;
        return true;
    }
    delete[] copy;
    return false;
}
void bogoBogo(int array[], int size)
{
    if (size <= 1)
    {
        return;
    }

    while (!arraySortedBogo(array, size))
    {
        shuffleArray(array, size);
    }
}