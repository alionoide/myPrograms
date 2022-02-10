#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin;
    int temp;
    int* ptr;
    int size;
             
    fin.open("data.txt", ios::binary);
             
    fin.seekg(0, ios::end);
             
    size = fin.tellg() / sizeof(int);
             
    ptr = new (nothrow) int[size];
    
    fin.seekg(0, ios::beg);
                          
    fin.read((char*)ptr, size * sizeof(int));
                          
    for (size_t i = 0; i < size; i++)
    {                     
        cout << ptr[i] << endl;
    }        
             
    delete[] ptr;
    fin.close();
}