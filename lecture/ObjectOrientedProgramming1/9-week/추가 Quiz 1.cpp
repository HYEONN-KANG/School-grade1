// array1 : abadasdaeasds 로 하고, 이 중 a의 수를 출력, 첫번째 as의 index를 리턴.

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    char array1[] = "abadasdaeasds";

    cout << "Original:" << setw(4);
    for(int i = 0; i < 14; i++){
        cout << array1[i] << " ";
    }

    int count = 0;

    int num1, num2;

    for(int i = 0; i < 14; i++){
        if('a' == array1[i]) {
            count++;
        }
    }

    for(int i = 0; i < 13; i++){
        if(array1[i] == 'a'){
            if(array1[i+1] == 's'){
                num1 = i;
                num2 = i+1;
                break;
            }
        }
    }

    cout << "\na의 수:" << setw(4) << count << 
    "\n첫번째 as의 index:" << setw(4) << num1 << " " << num2 << endl;
}