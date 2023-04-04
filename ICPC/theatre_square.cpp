#include <iostream>
using namespace std;

int main(){
    long long ancho;
    cin >> ancho;
    
    long long alto;
    cin >> alto;

    long long baldosa;
    cin >> baldosa;

    long long aancho = 0;
    long long aalto = 0;
    long long bal_ancho = 0;
    long long bal_alto = 0;

    for (int i = 0; i < ancho; i++)
    {
        while (aancho < ancho)
        {
            aancho += baldosa;
            bal_ancho += 1;
        }
        break;
    }
    
    for (int i = 0; i < alto; i++)
    {
        while (aalto < alto)
        {
            aalto += baldosa;
            bal_alto += 1;
        }
        break;
    }

    long long total = bal_alto * bal_ancho;
    cout << total << endl;
}