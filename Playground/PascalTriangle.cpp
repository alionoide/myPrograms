#include <iostream>

using namespace std;



int main()
{
    int arr[100];
    int tmp[100];
    int numrows;
    int i, j;

    for ( i = 0; i < 100; i++)
    {
        arr[i] = 0;
        tmp[i] = 0;
    }


    arr[0] = 1;
    tmp[0] = 1;


    // get number of rows to print

    cout << "Numrows: ";
    cin >> numrows;

    // print the triangle

    for ( i = 0; i < numrows + 1; i++)
    {
        // calculate the next row
        for ( j = 1; j < i; j++)
        {
            tmp[j] = arr[j] + arr[j - 1];
        }

        // set the row to the temp val then print
        for (j = 0; j < i; j++)
        {
            if (j == 0)
                cout << "[";

            arr[j] = tmp[j];
            cout << arr[j];

            if (j <= (i - 2))
                cout << ", ";
            else
                cout << "]" << endl;
        }
    }
}