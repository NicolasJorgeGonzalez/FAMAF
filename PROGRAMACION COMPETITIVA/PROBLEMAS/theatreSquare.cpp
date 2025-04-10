#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n, m, a;
    cin >> n >> m >> a;

    long long baseNece, altuNece, result;
    if ((n % a) != 0)
    {
        baseNece = (n / a) + 1;
    }
    else
    {
        baseNece = n / a;
    }
    
    if ((m % a) != 0)
    {
        altuNece = (m / a) + 1;
    }
    else
    {
        altuNece = m / a;
    }
    
    result   = baseNece * altuNece;
    
    cout << result << endl;

    return 0;
}

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);

//     int n, m, a, result;
//     cin >> n >> m >> a;
//     result = 0;

//     int areaPlaza, areaLoza, areaAux;
//     areaPlaza = n * m;
//     areaLoza  = a * a;
//     areaAux   = 0;

//     while (areaPlaza > areaAux)
//     {
//         result++;
//         areaAux += areaLoza;
//     }
    
//     cout << result << endl;

//     return 0;
// }