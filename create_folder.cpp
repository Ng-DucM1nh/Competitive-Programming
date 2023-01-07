#include <bits/stdc++.h>
#include <direct.h>
using namespace std;

int main()
{
    char* directory = "C:/Users/ACER/Documents/CP/test/PLUS";
    int check = mkdir(directory);
    if (check == 0){
        cout << "Folder created\n";
    }
    else{
        cout << "Error : " << strerror(errno) << '\n';
    }
    return 0;
}
