#include <bits/stdc++.h>
using namespace std;

int main(){
    int w;
    cin >> w;

    //w es par
    if (w%2 == 0 && w != 2){
        cout << "YES" << endl;
    }

    //w es inpar
    else{
        cout << "NO" << endl;
    }
}