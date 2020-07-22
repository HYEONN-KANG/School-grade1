#include <iostream>
using namespace std;

int main(){
    int a[3];
    for(int i = 0; i < 3; i++){
        cin >> a[i];
    }

    int b[2];
    cin >> b[0] >> b[1];

    int min = a[0] + b[0];
    int result;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++){
            result = a[i] + b[j];
            if(result < min) min = result;
        }
    }

    cout << min - 50 << endl;
}