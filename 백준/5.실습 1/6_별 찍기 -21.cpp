#include <iostream>

int main(){
    using namespace std;

    int N;
    cin >> N;

    int mok, namuji;
    mok = N / 2;
    namuji = N % 2;

    if(mok == 0 && namuji == 1) {
        cout << "*\n";     // N = 1일 때
        return 0;
    }
    
    for(int i = 1; i <= N; i++){
    // 위에 줄에 일단 몫 만큼 별 출력.
        for(int j = 1; j <= mok; j++){
            cout << "* ";   
        }if(namuji == 1){   // namuji가 1일 때
            cout << "*\n";
            for(int k = 1; k <= N - (mok + namuji); k++) cout << " *";
            cout << "\n";
        }else{              // 나머지가 0일 때
            cout << "\n";
            for(int k = 1; k <= N - mok; k++) cout << " *";
            cout << "\n";
        }
    }
}