#include <bits/stdc++.h>
#include <direct.h>
using namespace std;

int main()
{
    char* directory = "";
    int check = mkdir(directory);
    if (check == 0){
        cout << "Folder created\n";
    }
    else{
        cout << "Error : " << strerror(errno) << '\n';
    }
    return 0;
}
