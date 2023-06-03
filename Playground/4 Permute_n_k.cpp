#include <iostream>
using namespace std;

void permute( int *p, int *used, int n, int k, int pos );

int main()
{
    int p[100] = {0};
    int used[100] = {0};
    int n = 5;
    int k = 3;
    int pos = 0;

    permute( p, used, n, k, pos );

    return 0;
}

void permute( int *p, int *used, int n, int k, int pos )
{
    int i;

    if( pos == k)
    {
        for( i=0; i<k; i++)
            cout << p[i] << " ";
        cout << endl;
        return;
    }

    for( i=0; i<n; i++)
    {
        if( used[i] == 0 )
        {
            p[pos] = i;
            used[i] = 1;
            permute( p, used, n, k, pos+1 );
            used[i] = 0;
        }
    }
}
