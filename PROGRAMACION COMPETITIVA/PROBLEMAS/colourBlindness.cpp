#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;

        vector<char> fila1(n);
        vector<char> fila2(n);


        for (int j = 0; j < n; j++)
        {
            cin >> fila1[j];
        }
        for (int j = 0; j < n; j++)
        {
            cin >> fila2[j];
        }
        
        bool result = true;
        for (int m = 0; m < n; m++)
        {
            if (fila1[m] == fila2[m])
            {
                result = true;
            }
            else if ((fila1[m] == 'G') && (fila2[m] == 'B'))
            {
                result = true;
            }
            else if ((fila2[m] == 'G') && (fila1[m] == 'B'))
            {
                result = true;
            }
            else
            {
                result = false;
                break;
            }   
        }
        
        if (result == true)
        {
            cout << "YES" << "\n";
        }
        else
        {
            cout << "NO" << "\n";
        }
    }   

    return 0;
}  