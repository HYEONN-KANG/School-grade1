#include <iostream>

using std::cout;
using std::endl;

#include <cstring>

int main(){
    char *string1 = "abcdfjdkaferwasfdf";
    char *string2 = "four";
    char *string3 = "Boston";

    cout << "The length of \"" << string1
         << "\" is " << strlen(string1)
         << "\nThe length of \"" << string2
         << "\" is " << strlen(string2)
         << "\nThe length of \"" << string3
         << "\" is " << strlen(string3) << endl;

    return 0;
}