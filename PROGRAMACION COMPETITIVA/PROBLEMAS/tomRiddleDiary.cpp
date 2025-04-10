#include <bits/stdc++.h>

#define fore(i,a,b) for(ll i=a; i<(b); i++)
#define SZ(a) ((int)a.size())

typedef long long ll;
using namespace std;

int main(){
	ios::sync_with_stdio(0);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;

    set<string> nombres;

    fore(i,0,n){
        string nombre;
        cin >> nombre;
        if ((nombres.count(nombre)) >= 1)
        {
            nombres.insert(nombre);
            cout << "YES" << "\n";
        }
    	else
        {
            nombres.insert(nombre);
            cout << "NO" << "\n";
        }
    }

    return 0;
}