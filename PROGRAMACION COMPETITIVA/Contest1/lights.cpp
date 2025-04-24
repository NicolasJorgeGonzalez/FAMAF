#include <bits/stdc++.h>

#define fore(i, a, b) for (ll i = a; i <= b; i++)
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

    int n, q, result;
    result = 0;
    cin >> n;

    vector<int> lights;

    fore(i, 1, n)
    {
        int number;
        cin >> number;
        lights.push_back(number);
    }

    cin >> q;
    fore(i, 1, q)
    {
        int a, b;
        cin >> a >> b;
        fore(j, a + 1, b)
        {
            if (lights[j] == lights[j - 1])
            {
                result += 1;
            }
        }
        cout << result << endl;
    }

    return 0;
}