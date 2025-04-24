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

    int t;
    cin >> t;

    fore(i, 0, t)
    {
        int a, b, c, result;
        cin >> a >> b >> c;

        if (abs(a) < (abs(b - c) + c))
        {
            result = 1;
        }
        else if (abs(a) > (abs(b - c) + c))
        {
            result = 2;
        }
        else
        {
            result = 3;
        }
        cout << result << "\n";
    }

    return 0;
}