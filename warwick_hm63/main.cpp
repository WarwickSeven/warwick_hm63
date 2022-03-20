#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void WriteToFile(const string & fn, const string & str)
{
    ofstream fout;
    fout.open(fn);
    if (fout.is_open())
    {
        fout << str;
        fout.close();
    }
}

void combineFiles(const string &fn1, const string &fn2, const string &fn3)
{
    ifstream fin1(fn1);
    ifstream fin2(fn2);
    ofstream fout(fn3);
        
    if (fin1.is_open() && fin2.is_open() && fout.is_open())
    {
        string buf1, buf2;
        while (!fin1.eof())
        {
            getline(fin1, buf1);
            fout << buf1 << endl;
        }
        fin1.close();
        
        while (!fin2.eof())
        {
            getline(fin2, buf2);
            fout << buf2 << endl;
        }
        fin1.close();
        fout.close();
    }
        else
        {
            cerr << "file read error.";
            exit(1);
        }
    cin.get();
}

int main()
{
    string fileName1, fileName2, fileName3;
    cout << "Enter file 1 name: ";
    cin >> fileName1;
    cout << "Enter file 2 name: ";
    cin >> fileName2;
    cout << "Enter file 3 name: ";
    cin >> fileName3;
    
    const string str1 = "The Fractal Audio Axe-FX III Mark II Turbo is the best guitar processor in a world";
    WriteToFile(fileName1, str1);
    
    const string str2 = "But the Fractal Audio FM9 is the best money buy";
    WriteToFile(fileName2, str2);
    
    combineFiles(fileName1, fileName2, fileName3);
    
    return 0;
}
 
