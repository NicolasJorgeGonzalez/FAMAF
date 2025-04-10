#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    int n, i;
    cin >> n; 
    i = 1;
    
    string result = "";
    
    result += "I hate ";
    while (i != n)
    {
        result += "that ";
        result += "I love ";
        i++;
        if (i != n)
        {
            result += "that ";
            result += "I hate ";
            i++;
        }
    }
    
    result += "it";
    
    cout << result << "\n";

    return 0;
}  