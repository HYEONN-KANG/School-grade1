// find the approximate value of pi up to given n using the following Leibniz series;
#include <iostream>
using namespace std;

double my_pi(int);
int main(){
    int num;
    cout << "Input number : ";
    cin >> num;

    cout << "pi = " << my_pi(num) << endl;
}

double my_pi(int x){
    double output;
    int count = 1;
    output = 0.0;
    for(int i = 1; i <= 2*x + 1; i += 2){
        if(count % 2 == 1){
            output = output + (1/i) + (1%i);
        }else{
            output = output - (1/i) - (1%i);
        }
        count++;
    }
    output = 4 * output;
    return output;
}