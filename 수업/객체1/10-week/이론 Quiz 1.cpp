/*
Binary serach 함수 코드를 그대로 구현하여 실행해보고, 다시 재귀 함수로 수정하여 구현하세요.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int binarySearch(const int [], int, int, int, int);
void printHeader(int);
void printRow(const int [], int, int, int, int);

int main(){
    const int arraySize = 15;
    int a[arraySize];
    int key;

    for(int i = 0; i < arraySize; i++){
        a[i] = 2 * i;
    }

    cout << "Enter a number between 0 and 28: ";
    cin >> key;

    printHeader(arraySize);

    int result = binarySearch(a, key, 0, arraySize - 1, arraySize);

    if(result != - 1){
        cout << "\n" << key << " found in array element " << result << endl;
    }
    else
    {
        cout << "\n" << key << " not found" << endl;
    }

    return 0;
}

int binarySearch(const int b[], int searchKey, int low, int high, int size){
    int middle;

    while(low <= high){
        middle = (low + high) / 2;

        printRow(b, low, middle, high, size);

        if(searchKey == b[middle]) return middle;

        else
        {
            if (searchKey < b[middle])
            {
                high = middle - 1;
            }

            else
            {
                low = middle + 1;
            }
        }
    }

    return -1;
}

void printHeader(int size){
    cout << "\nSubscripts:\n";

    for(int j = 0; j < size; j++){
        cout << setw(3) << j << " ";
    }

    cout << "\n";

    for(int k = 1; k <= 4 * size; k++){
        cout << "-";
    }
    cout << endl;
}

