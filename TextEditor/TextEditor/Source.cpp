#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main(int argc, char** argv)
{
    ifstream file;
    int x = 0;
    int filesize = stoi(argv[3]);


    char* awful = new (nothrow) char[filesize];

    if (awful == nullptr)
        exit(2);

    file.open(argv[1]);



    if (!file.is_open())
    {
        exit(1);
    }

    while (!file.eof())
    {
        file.read(awful, filesize - 1);
        awful[filesize - 1] = 0;
        if (1)
        {
            ofstream out;
            out.open( string("Output\\") + argv[2] + to_string(x) + ".txt");
            x++;

            out << awful;

            out.close();
        }
    }

    file.close();
}