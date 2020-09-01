// ppt 22~23page 샘플코드를 그대로 구현해보세요.
// Treating character arrays as strings.
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
    char string1[20];
    char string2[] = "string literal";

    cout << "Enter the string \"hello there\": ";
    cin >> string1; // reads "hello"

    // output strings
    cout << "string1 is : " << string1 << "\nstrilng2 is : " << string2;
    cout << "\nstring1 with spaces between characters is : \n";

    // output characters until nulll character is reached
    for(int i = 0; string1[i] != '\0'; i++){
        cout << string1[i] << ' ';
    }

    cin >> string1; // reads "there"
    cout << "\nstring1 is : " << string1 << endl;

    return 0;
}