/*
Randomly generate an integer array nums[10]. Its values are in [-5, 5]. Find the contiguous subarray (containing at least one number) which has the smallest sum and 
Print or return its sum.

Example:
Input: [-2, 5,-3,2,-4,2,1,5,4],
Output: -5
Explanation: [-3, 2, -4] has the smallest sum = -5.
*/
#include <iostream>
#include <ctime>
using namespace std;

void printArray(int [], int);
int sumofArray(int [], int, int);

int main(){
    srand(time(NULL));

    int array[10];
    for(int i = 0; i < 10; i++){
        array[i] = rand() % 11 - 5;
    }

    printArray(array, 10);  // 배열 출력

    int min = 6;
    int min_index = -1;
    for(int i = 0; i < 10; i++){
        if(array[i] < min){
            min = array[i];
            min_index = i;
        }
    }

    cout << "Output: " << sumofArray(array, 10, min_index) << endl;
}

int sumofArray(int array[], int sizeofArray, int indexofmin){
    // 오른쪽으로 계속 더하기
    int sum1, minofsum1 = 6;
    for(int i = indexofmin; i < sizeofArray; i++){
        sum1 += array[i];
        if(sum1 < minofsum1){
            minofsum1 = sum1;
        }
    }

    // 왼쪽으로 계속 더하기
    int sum2, minofsum2 = 6;
    for(int i = indexofmin; i >= 0; i--){
        sum2 += array[i];
        if(minofsum2 > sum2){
            minofsum2 = sum2;
        }
    }

    // min이 가운데 끼어 있을 때
    int min3, min4;
    if(indexofmin > 0 && indexofmin < sizeofArray - 1){
        int sum = array[indexofmin] + array[indexofmin - 1] + array[indexofmin + 1];
        // 먼저 오른쪽으로
        min3 = sum;
        for(int i = indexofmin + 2; i < sizeofArray; i++){
            sum += array[i];
            if(min3 > sum){
                min3 = sum;
            }
        }

        // 왼쪽으로
        sum = array[indexofmin] + array[indexofmin - 1] + array[indexofmin + 1];
        min4 = sum;
        for(int i = indexofmin - 2; i >= 0; i--){
            sum += array[i];
            if(min4 > sum){
                min4 = sum;
            }
        }
    }

    int firstmin = (minofsum1 > minofsum2)? minofsum2 : minofsum1;
    int secondmin = (min3 > min4)? min4 : min3;

    return (firstmin > secondmin)? secondmin : firstmin;
}

void printArray(int array[], int sizeofArray){
    cout << "Input: [";
    for(int i = 0; i < sizeofArray; i++){
        if(i == sizeofArray - 1){
            cout << array[i] << "]" << endl;
            break;
        }
        else{cout << array[i] << ", ";}
    }
}