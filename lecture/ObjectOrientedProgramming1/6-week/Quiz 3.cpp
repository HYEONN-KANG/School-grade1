#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

int main(){
    int mean;
    cout << "Input your mean : ";
    cin >> mean;

    srand(time(NULL));
    int count = 0;
    int z = 0;
    while(count < 10){
        int x = rand() % 101;
        int y = pow(x-mean, 2);
        z += y;
        cout << "Sum of squares in x = " << x << ": " << z << endl;
        count++;
    }
}