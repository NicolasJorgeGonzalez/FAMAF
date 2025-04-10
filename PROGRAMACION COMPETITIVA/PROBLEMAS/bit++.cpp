#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    int result;

    cin >> n;
    result = 0;

    for (size_t i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if ((s == "++X") || (s == "X++"))
        {
            result++;
        }
        if ((s == "--X") || (s == "X--"))
        {
            result--;
        }
    }
    cout << result << endl;

    return 0;
}