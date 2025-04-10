#include <bits/stdc++.h>

#define fore(i,a,b) for(ll i=a; i<b; i++)
#define SZ(a) ((int)a.size())

typedef long long ll;
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin.tie(0);cout.tie(0);

    int n, p, level;

    set<int> levels;

    cin >> n;

    cin >> p;
    fore(j,0,p)
    {
        cin >> level;
        levels.insert(level);
    }

    cin >> p;
    fore(j,0,p)
    {
        cin >> level;
        levels.insert(level);
    }

    if (SZ(levels) == n)
    {
        cout << "I become the guy." << "\n";
    }
    else
    {
        cout << "Oh, my keyboard!" << "\n";
    }

    return 0;
}