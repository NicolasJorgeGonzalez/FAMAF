#include <bits/stdc++.h>

#define fore(i,a,b) for(ll i=a; i<b; i++)
#define SZ(a) ((int)a.size())

typedef long long ll;
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin.tie(0);cout.tie(0);

    int n, k, i = 1;
    cin >> n >> k;

    string s;
    cin >> s;

    while((k != 0) && (i != n))
    {
        if (s[0] != 1)
        {
            s[0] = 1;
            k--;
        }
        else
        {
            i++;
            if (s[i] != 0)
            {
                s[i] = 0;
                k--;
            }
        }
    }

    cout << s << "\n";

    return 0;
}