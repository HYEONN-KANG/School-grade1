#include <iostream>

using std::cout;
using std::endl;

#include <cstring>

int main(){
    char s1[20] = "Happy ";
    char s2[] = "New year ";
    char s3[40] = "";

    cout << "s1 = " << s1 << "\ns2 = " << s2;

    strcat(s1, s2);

    cout << "\n\nAfter strcat(s1, s2):\ns1 = " << s1
         << "\ns2 = " << s2;

    strncat(s3, s1, 6);

    cout << "\n\nAfter strncat(s3, s1, 6):\ns1 = " << s1
         << "\ns3 = " << s3;
    
    strcat(s3, s1);
    cout << "\n\nAfter strcat(s3, s1):\ns1 = " << s1
         << "\ns3 = " << s3;

    return 0;
}