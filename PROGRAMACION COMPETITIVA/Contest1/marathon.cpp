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
        int a, b, c, d, result;
        result = 0;
        cin >> a >> b >> c >> d;

        if (a <= b)
        {
            result += 1;
        }
        if (a <= c)
        {
            result += 1;
        }
        if (a <= d)
        {
            result += 1;
        }
        cout << result << "\n";
    }

    return 0;
}