#include <iostream>

using std::cout;
using std::endl;

#include <cstring>

int main(){
    char x[] = "Happy Birthday to you!";
    char y[25];
    char z[10];

    strcpy(y ,x);

    cout << "The string in array x is: " << x
         << "\nThe string in array y is: " << y;

    strncpy(z, x, 14);
    z[14] = '\0';

    cout << "\nThe string in array z is: " << z << endl;
}