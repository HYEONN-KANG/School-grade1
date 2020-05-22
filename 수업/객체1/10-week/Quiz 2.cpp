#include <iostream>
#include <ctime>

int main(){
    using namespace std;

    srand(time(0));

    int array[10];
    for(int i = 0; i < 10; i++){
        array[i] = rand()%5;
    }

    cout << "generate array [10] = [";
    for(int i = 0 ;i < 10; i++){
        if(i == 9){
            cout << array[i] << "]" << endl;
            break;
        }
        cout << array[i] << ", ";
    }

    int new_array[10] = {0};
    for(int i = 0; i < 10; i++){
        new_array[i] = -1;
    }

    int count;
    for(int i = 0; i < 10; i++){
        count = 0;

        for(int j = 0; j < 10; j++){
            if(array[i] == new_array[j]){
                count++;
            }
        }

        if(count == 0){
            new_array[i] = array[i];
        }
    }

    cout << "The new array is [";
    for(int i = 0; i < 10; i++){
        if(new_array[i] != -1){
            cout << new_array[i] << " ";
           
        }
    }cout << "]" << endl;
}