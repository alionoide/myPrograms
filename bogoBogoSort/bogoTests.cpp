#include "bogo.h"

int main()
{
    const int size = 5;
    
    int array[size] = { 1,  3,  2, 4,  6/*,  5,  7,  8,  9 /*10,
                       11, 12, 13, 14, 15, 16, 17, 18, 19, 20*/};

    /*while (!arraySorted(array, size))
    {
        shuffleArray(array, size);

        displayArray(array, size);
    }*/

    
    bogoBogo(array, size);

    cout << endl << "Array successfully sorted:" << endl;

    displayArray(array, size);

    return 0;
}
