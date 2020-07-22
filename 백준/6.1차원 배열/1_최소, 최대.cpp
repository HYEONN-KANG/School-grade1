#include <iostream>

int main(){
    using namespace std;

    int N;
    cin >> N;

    int arr;
    cin >> arr;

    int max = arr;
    int min = arr;

    for(int i = 1; i < N; i++){
        cin >> arr;
        if(arr > max) max = arr;
        if(arr < min) min = arr;
    }

    cout << min << " " << max << "\n";
}