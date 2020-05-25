#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

const int x = 5;
const int y = 5;

void originGrid(char [][y], char);  // grid 초기화
void printGrid(char [][y]);    // 현재 빙고판 출력
void putGrid(char [][y], char, int wh_x, int wh_y);   // user가 grid에 X 놓기
void computGrid(char [][y], char);  // computer가 O 놓기
int whoWin(char [][y], char); // 이긴 사람이 판단 
void gameEnd(int, time_t);  // 게임 종료

int main(){
    cout << "-----------------------------" << endl <<
            "-----------------------------" << endl <<
            "----컴퓨터와 빙고 게임!!!----" << endl <<
            "-----------------------------" << endl <<
            "-----------------------------" << endl;
    cout << "컴퓨터와 번갈아 가면서 판에 o와 x를 놓으며, 우선 한 줄의 5개를 모두 채운 유저가 승리합니다!" << endl <<
            "컴퓨터는 O, 당신은 X" << endl <<
            "게임할 준비가 됬나요? 준비가 됬으면 아무키나 눌러주세요!" << endl;

    getchar();
    system("cls");

    // game start
    srand(time(NULL));
    time_t start = time(NULL);

    char grid[x][y];
    originGrid(grid, 'I');  // grid 초기화

    int user_x, user_y; // user로부터 입력받을 x, y 좌표 변수
    char user_word = 'X', com_word = 'O';    // user와 com의 word 지정

    while(true){
        printGrid(grid);  // user가 둘 차례

USER_INPUT:
        cout << "X를 둘 좌표를 입력해주세요" << endl;
        cin >> user_x >> user_y;
        if(grid[user_x][user_y] == user_word || grid[user_x][user_y] == user_word){
            cout << " [ 해당 위치에 둘수 없습니다.] " << endl;
            goto USER_INPUT;
        }
        putGrid(grid, user_word, user_x, user_y);
        if(whoWin(grid, user_word) == 2){   // user가 이겼다면?
            time_t end = time(NULL);
            system("cls");
            printGrid(grid);
            gameEnd(2, end - start);
            return 0;
        }
        system("cls");

        computGrid(grid, com_word); // com이 둘 차례
        whoWin(grid, user_word);
        if(whoWin(grid, com_word) == 1){   // com가 이겼다면?
            time_t end = time(NULL);
            system("cls");
            printGrid(grid);
            gameEnd(1, end - start);
            return 0;
        }
        system("cls");
    }
}

void gameEnd(int who, time_t T){  // 게임 종료
    if(who == 2){   // user가 승리했다면
        cout << "[User가 이겼습니다. " << "게임 소요시간 전체 " << T << "초입니다.]" << endl;
    }else if(who == 1){
        cout << "[Computer가 이겼습니다. " << "게임 소요시간 전체 " << T << "초입니다.]" << endl;
    }
}

void printGrid(char grid[][y]){   // grid 판 출력
    cout << "x\\y" << " [0]   [1]   [2]   [3]   [4]" << endl;
    for(int i = 0; i < x; i++){
        cout << "[" << i << "]";
        for(int j = 0; j < y; j++){
            if(grid[i][j] == 'I') {
                if(j != y-1) cout << "-----|" ;
                else         cout << "-----" ;
            }
            else{
                if(j != y-1) cout << "  " << grid[i][j] << "  |";
                else         cout << "  " << grid[i][j];
            }
        }
        cout << endl;
    }
}

void originGrid(char grid[][y], char word){  // 처음 grid 초기화
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            grid[i][j] = word;
        }
    }
}

void putGrid(char grid[][y], char word, int wh_x, int wh_y){  // user가 grid에 X 놓기
    grid[wh_x][wh_y] = word;
}

void computGrid(char grid[][y], char word){  // computer가 O 놓기
RETRY:
    int com_x = rand() % 5;
    int com_y = rand() % 5;

    if(grid[com_x][com_y] == 'I'){  // 이전에 선택된 좌표가 아니라면 정상적으로 입력
        grid[com_x][com_y] = 'O';
    }else{  // 이전에 선택된 좌표라면 다시 입력을 받기
        goto RETRY;
    }
}

int whoWin(char grid[][y], char word){ // 이긴 사람이 판단. 승부가 안났다면 -1 , user가 이겼다면 2, com이 이겼다면 1
    int a = 0;

    for(int i = 0; i < x; i++){ // 가로로 5개가 놓였는지 판단
        for(int j = 0; j < y; j++){
            if(grid[i][j] != word){
                a++;
            }
        }
        if(a != 0){
            a = 0;
        }
        else{
            if(word == 'O'){     // com의 승리
                return 1;
            }else if(word == 'X'){    // user의 승리
                return 2;
            }
        }
    }

    for(int i = 0; i < x; i++){ // 세로로 5개가 놓였는지 판단
        for(int j = 0; j < y; j++){
            if(grid[j][i] != word){
                a++;
            }
        }
        if(a != 0){
            a = 0;
        }
        else{
            if(word == 'O'){     // com의 승리
                return 1;
            }else if(word == 'X'){    // user의 승리
                return 2;
            }
        }
    }

   if(grid[2][2] == word){
       for(int i = 0; i < x; i++){  // 오른쪽으로 내려오는 대각선 판단
            if(grid[i][i] != word){
                a++;
            }
       }
       
       if(a != 0){
            a = 0;
        }
        else{
            if(word == 'O'){     // com의 승리
                return 1;
            }else if(word == 'X'){    // user의 승리
                return 2;
            }
        }

        for(int i = x; i > 0; i--){  // 오른쪽으로 올라가는 대각선 판단
            if(grid[i][i] != word){
                a++;
            }
       }
       
       if(a != 0){
            a = 0;
        }
        else{
            if(word == 'O'){     // com의 승리
                return 1;
            }else if(word == 'X'){    // user의 승리
                return 2;
            }
        }
   }

    return -1;
}