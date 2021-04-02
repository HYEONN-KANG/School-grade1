#include <iostream>

int main(){
    using namespace std;

    int H, M;
    cin >> H >> M;

    if(M >= 45){
        M = M - 45;
        cout << H << " " << M << endl;
    }else{
        if(H >= 1){
            int min = 45 - M;
            M = 60;
            H--;
            M -= min;
            cout << H << " " << M << endl;
        }else if(H == 0){
            int min = 45 - M;
            M = 60;
            H = 23;
            M -= min;
            cout << H << " " << M << endl;
        }
    }
}