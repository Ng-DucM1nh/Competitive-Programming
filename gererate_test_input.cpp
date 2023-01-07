#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int gen (int lo, int hi)
{
    return rng() % (hi - lo + 1) + lo;
}

int main()
{
    int NUMTEST = 100;
    for (int test=1; test<=NUMTEST; test++){
        ofstream inp("inp.txt");
        // generate data for input
        int x = gen(1, 100);
        inp << x;
        inp.close();

        // compare output
        system("sol.exe"); system("bf.exe");
        if (system("fc out.txt ans.txt") == 0){
            cout << "AC\n";
        }
        else{
            cout << "WA\n";
            break;
        }
    }
}
