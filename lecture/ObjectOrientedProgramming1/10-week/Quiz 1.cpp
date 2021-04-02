#include <iostream>
#include <ctime>
using namespace std;

int main(){
    srand(time(0));

    int num[20];
    for(int i = 0; i < 20; i++){
        num[i] = rand()%11 - 5;
    }

    cout << "generage array nums[20] : [";
    for(int i = 0 ;i < 20; i++){
        if(i == 19) {
            cout << num[i] << "]";
            break;
        }
        cout << num[i] << " ";
    }cout << endl << endl;

    cout << "A solution set is:" << endl;
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 20; j++){
            if(i == j) continue;

            for(int k = 0; k < 20; k++){
                if(i == k || j == k) continue;

                else if(num[i] + num[j] + num[k] == 1){
                    cout << "[" << num[i] << ", " << num[j] << ", " << num[k] << "]" << endl;
                }
            }
        }
    }
}