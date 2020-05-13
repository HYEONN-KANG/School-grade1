/*
bubble sort 함수를 구현하고, 메인 함수에서 호출하여 사용. 순환적 arraySize만큼 모두 하지 않고, sorting이 완성되면 순환을 중단.
*/

#include <iostream>

using std::cout;
using std::endl;

#include <iomanip>
using std::setw;

void bubbleSort(int [], const int);

int main(){
    const int arraySize = 10;
    int a[arraySize] = {2, 4, 6, 8, 10, 12, 89, 68, 45, 37};

    cout << "Original:" << setw(4);
    // output original array
    for(int i = 0; i < arraySize; i++){
        cout << a[i] << " ";
    }
    cout << endl;

    // bubble sort
    bubbleSort(a, arraySize);
    
    return 0;
}

void bubbleSort(int arr[], const int arraySize){
    int temp;
    int exchange = 0;
    int end;

    for(int i = 0; i < arraySize; i++){
        exchange = 0;

        for(int k = 0; k < arraySize - 1; k++){
            if(arr[k] > arr[k+1]){
                temp = arr[k];
                arr[k] = arr[k+1];
                arr[k+1] = temp;
                exchange++;
            }
        }
        if(exchange == 0){
            end = i;
            break;
        }
        cout << "Pass " << i + 1 << ":" << setw(6);
        for(int pass = 0; pass < arraySize; pass++){
            cout << arr[pass] << " ";
        }
        cout << endl;
    }
    cout << "Pass " << end << "까지 순회하며 더 이상 순회하지 않음." << endl;
}