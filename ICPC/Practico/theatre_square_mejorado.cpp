#include <iostream>
using namespace std;

int main(){
    long long alto, ancho, baldosa, n_baldosas;
    cin >> alto >> ancho >> baldosa;

    n_baldosas = ((alto + baldosa - 1)/baldosa) * ((ancho + baldosa - 1)/baldosa);

    cout << n_baldosas << endl;
}