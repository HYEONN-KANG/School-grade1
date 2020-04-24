// 각 달의 마지막 날짜 구하기
#include <iostream>
using namespace std;

void LastDay_1month(int, int);
void LastDay_allmonth(int);

int main(){
    int year;
    cout << "Input year ? : ";
    cin >> year;

choose:
    int choose;
    cout << "if you want see all month? input 0, not? input 1 :";
    cin >> choose;
    if(choose == 1){
        int month;
        cout << "Input month ? : ";
        cin >> month;
        LastDay_1month(year, month);    // output only 1 month;
    }
    else if(choose == 0){
        LastDay_allmonth(year); // output all months in that year;
    }else{
        cout << "I think you entered it incorrectly.";
        goto choose;
    }
}

void LastDay_1month(int year, int month){
    switch(month){
        case 1:
            cout << "The last day of January " << year << " is the 31st." << endl;
            break;
        case 2:
            if(year % 4 == 0){
                if(year % 100 != 0){
                    cout << "The last day of February " << year << " is the 29st." << endl;
                }else if(year % 400 == 0){
                    cout << "The last day of February " << year << " is the 29st." << endl;
                }else{
                    cout << "The last day of February " << year << " is the 28st." << endl;
                }
            }else{
                cout << "The last day of February " << year << " is the 28st." << endl;
            }
            break;
        case 3:
            cout << "The last day of March " << year << " is the 31st." << endl;
            break;
        case 4:
            cout << "The last day of April " << year << " is the 30st." << endl;
            break;
        case 5:
            cout << "The last day of May " << year << " is the 31st." << endl;
            break;
        case 6:
            cout << "The last day of June " << year << " is the 30st." << endl;
            break;
        case 7:
            cout << "The last day of July " << year << " is the 31st." << endl;
            break;
        case 8:
            cout << "The last day of August " << year << " is the 31st." << endl;
            break;
        case 9:
            cout << "The last day of September " << year << " is the 30st." << endl;
            break;
        case 10:
            cout << "The last day of October " << year << " is the 31st." << endl;
            break;
        case 11:
            cout << "The last day of November " << year << " is the 30st." << endl;
            break;
        case 12:
            cout << "The last day of December " << year << " is the 31st." << endl;
            break;
    }
}

void LastDay_allmonth(int year){
    cout << "The last day of January " << year << " is the 31st." << endl;

    if(year % 4 == 0){  // February
                if(year % 100 != 0){
                    cout << "The last day of February " << year << " is the 29st." << endl;
                }else if(year % 400 == 0){
                    cout << "The last day of February " << year << " is the 29st." << endl;
                }else{
                    cout << "The last day of February " << year << " is the 28st." << endl;
                }
            }else{
                cout << "The last day of February " << year << " is the 28st." << endl;
            }

    cout << "The last day of March " << year << " is the 31st." << endl;
    cout << "The last day of April " << year << " is the 30st." << endl;
    cout << "The last day of May " << year << " is the 31st." << endl;
    cout << "The last day of June " << year << " is the 30st." << endl;
    cout << "The last day of July " << year << " is the 31st." << endl;
    cout << "The last day of August " << year << " is the 31st." << endl;
    cout << "The last day of September " << year << " is the 30st." << endl;
    cout << "The last day of October " << year << " is the 31st." << endl;
    cout << "The last day of November " << year << " is the 30st." << endl;
    cout << "The last day of December " << year << " is the 31st." << endl;
}