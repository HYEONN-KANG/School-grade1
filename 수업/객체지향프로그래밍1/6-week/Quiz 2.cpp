#include <iostream>
using namespace std;

void sumofsquares(int, int);
int main(){
    int mean = 2;
    for(int x = 2; x < 10; x++){
        sumofsquares(x, mean);
    }
    return 0;
}

void sumofsquares(int x, int mean){
    static int nStatic = 0;
    nStatic += (x - mean) * (x - mean);
    cout << "Sum of squares in " << "x = " << x << ": " << nStatic << endl;
}