#include <iostream>
using namespace std;

int main(){
    
    long long f_house;
    cin >> f_house;

    long long elephant_s = 0;

    while (f_house != 0) {
        if(f_house >= 5) {
            f_house -= 5;
            elephant_s += 1;
        }
        else if(f_house >= 4) {
            f_house -= 4;
            elephant_s += 1;
        }
        else if(f_house >= 3) {
            f_house -= 3;
            elephant_s += 1;
        }
        else if(f_house >= 2) {
            f_house -= 2;
            elephant_s += 1;
        }
        else if(f_house >= 1) {
            f_house -= 1;
            elephant_s += 1;
        }
    }

    cout << elephant_s << endl;

}