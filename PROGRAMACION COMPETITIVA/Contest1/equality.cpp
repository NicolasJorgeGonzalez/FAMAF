#include <bits/stdc++.h>

#define fore(i, a, b) for (ll i = a; i < b; i++)
#define SZ(a) ((int)a.size())

typedef long long ll;
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    set<char> aux2;
    fore(i, 0, n)
    {
        aux2.insert(s[i]);
    }
    int size = aux2.size();
    if (size != k)
    {
        cout << 0 << "\n";
    }
    else
    {
        multiset<char> aux;

        fore(i, 0, n)
        {
            aux.insert(s[i]);
        }

        int mini;
        mini = aux.count(*(aux.begin()));

        while (aux.size() != 0)
        {
            int act = aux.count(*(aux.begin()));
            mini = min(mini, act);
            aux.erase(*(aux.begin()));
        }

        cout << mini * k << "\n";
    }

    return 0;
}