#include <iostream>
using namespace std;

void multiplyMatrix(int arr1[][5], int arr2[][5],int result[][5], int row);
void printMatrix(int result[][5], int row);

int main(){
    int arr1[5][5] = 
    { {1, 0, 4, 7, 3},
      {2, 7, 4, 0, 2},
      {4, 3, 3, 1, 1},
      {6, 6, 9, 2, 8},
      {5, 8, 1, 6, 0}};
    
    cout << "arr1:" << endl;
    printMatrix(arr1, 5);
    
    int arr2[5][5] = 
    { {6, 7, 3, 5, 4},
      {8, 8, 5, 4, 6},
      {0, 0, 2, 7, 5},
      {1, 5, 3, 1, 3},
      {5, 7, 4, 7, 3}};
    
    cout << "arr2: " << endl;
    printMatrix(arr2, 5);

    int result[5][5] = {0};

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            result[i][j] += arr1[i][j] * arr2[j][i];
        }
    }

    multiplyMatrix(arr1, arr2, result, 5);

    cout << "arr1 * arr2:" << endl;
    printMatrix(result, 5);

    return 0;
}

void multiplyMatrix(int arr1[][5], int arr2[][5], int result[][5], int row){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < row; j++){
            for(int k = 0; k < row; k++){
                result[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
}

void printMatrix(int arr[][5], int row){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }cout << endl;
}