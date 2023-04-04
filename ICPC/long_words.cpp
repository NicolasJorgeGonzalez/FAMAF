#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		string palabra;
		cin >> palabra;
		
		int largo = palabra.length();
		
		// aca hay que comprimir
		if (largo > 10) {
			cout << palabra[0] << largo-2 << palabra[largo-1] << endl;
		}
		
		// aca hay que dejar como esta
		else {
			cout << palabra << endl;
		}
	}
}
