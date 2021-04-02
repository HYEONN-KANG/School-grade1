#include <iostream>
using namespace std;

int main(){
    int A, B, C;
    cin >> A >> B >> C;

    int result = A*B*C;

    int arr[20];
    int c[10] = {0};
    
    for(int i = 0; i < 20; i++){
        arr[i] = result % 10;
        result = result / 10;

        switch(arr[i]){
            case 0:
                c[0]++;
                break;
            case 1:
                c[1]++;
                break;
            case 2:
                c[2]++;
                break;
            case 3:
                c[3]++;
                break;
            case 4:
                c[4]++;
                break;
            case 5:
                c[5]++;
                break;
            case 6:
                c[6]++;
                break;
            case 7:
                c[7]++;
                break;
            case 8:
                c[8]++;
                break;
            case 9:
                c[9]++;
                break;
        }
        if(result == 0) break;
    }

    for(int i = 0; i < 10; i++){
        cout << c[i] << "\n";
    }
}