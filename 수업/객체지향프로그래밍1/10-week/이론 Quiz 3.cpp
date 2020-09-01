/*
매트릭스 덧셈 연산의 구현
다음의 array1, array2는 함수 내에서 고정.
Array3을 계산하여 출력

array1[0][0] + array2[0][0] = array3[0][0]
*/

#include <iostream>

using namespace std;

const int row = 3;
const int columns = 3;

void printArray(int [][columns], const int, const int);
void sumArray(int [][columns], int [][columns], const int, const int);

int main(){
    int array1[row][columns] =
    { {1, 0, -1},
      {2, 2, -3},
      {3, 4, 0} };
    
    int array2[row][columns] =
    { {3, 4, -1},
      {1, -3, 0},
      {-1, 1, 2} };

    cout << "array1 is:" << endl;
    printArray(array1, row, columns);
    cout << "array2 is:" << endl;
    printArray(array2, row, columns);

    int array3[row][columns];

    for(int i = 0; i < row; i++){
        for(int j = 0; j < columns; j++){
            array3[i][j] = array1[i][j] + array2[i][j];
        }
    }
    cout << "array3 is:" << endl;
    printArray(array3, row, columns);

    return 0;
}

void printArray(int array[][columns], const int row, const int columns){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < columns; j++){
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}