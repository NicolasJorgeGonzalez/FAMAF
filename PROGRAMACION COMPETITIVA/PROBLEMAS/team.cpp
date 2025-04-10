#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    int result;
    result = 0;
    cin >> n;

    for (size_t i = 0; i < n; i++)
    {
        int p, v, t;
        int aux;
        aux = 0;
        cin >> p >> v >> t;
        if (p == 1)
        {
            aux++;
        }
        if (v == 1)
        {
            aux++;
        }
        if (t == 1)
        {
            aux++;
        }
        if (aux >= 2)
        {
            result++;
        }
    }
    cout << result << endl;
    return 0;
}