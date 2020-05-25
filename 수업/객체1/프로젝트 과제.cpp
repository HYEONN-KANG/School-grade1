#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

const int x = 5;
const int y = 5;

void originGrid(char [][y], char);  // grid �ʱ�ȭ
void printGrid(char [][y]);    // ���� ������ ���
void putGrid(char [][y], char, int wh_x, int wh_y);   // user�� grid�� X ����
void computGrid(char [][y], char);  // computer�� O ����
int whoWin(char [][y], char); // �̱� ����� �Ǵ� 
void gameEnd(int, time_t);  // ���� ����

int main(){
    cout << "-----------------------------" << endl <<
            "-----------------------------" << endl <<
            "----��ǻ�Ϳ� ���� ����!!!----" << endl <<
            "-----------------------------" << endl <<
            "-----------------------------" << endl;
    cout << "��ǻ�Ϳ� ������ ���鼭 �ǿ� o�� x�� ������, �켱 �� ���� 5���� ��� ä�� ������ �¸��մϴ�!" << endl <<
            "��ǻ�ʹ� O, ����� X" << endl <<
            "������ �غ� �糪��? �غ� ������ �ƹ�Ű�� �����ּ���!" << endl;

    getchar();
    system("cls");

    // game start
    srand(time(NULL));
    time_t start = time(NULL);

    char grid[x][y];
    originGrid(grid, 'I');  // grid �ʱ�ȭ

    int user_x, user_y; // user�κ��� �Է¹��� x, y ��ǥ ����
    char user_word = 'X', com_word = 'O';    // user�� com�� word ����

    while(true){
        printGrid(grid);  // user�� �� ����

USER_INPUT:
        cout << "X�� �� ��ǥ�� �Է����ּ���" << endl;
        cin >> user_x >> user_y;
        if(grid[user_x][user_y] == user_word || grid[user_x][user_y] == user_word){
            cout << " [ �ش� ��ġ�� �Ѽ� �����ϴ�.] " << endl;
            goto USER_INPUT;
        }
        putGrid(grid, user_word, user_x, user_y);
        if(whoWin(grid, user_word) == 2){   // user�� �̰�ٸ�?
            time_t end = time(NULL);
            system("cls");
            printGrid(grid);
            gameEnd(2, end - start);
            return 0;
        }
        system("cls");

        computGrid(grid, com_word); // com�� �� ����
        whoWin(grid, user_word);
        if(whoWin(grid, com_word) == 1){   // com�� �̰�ٸ�?
            time_t end = time(NULL);
            system("cls");
            printGrid(grid);
            gameEnd(1, end - start);
            return 0;
        }
        system("cls");
    }
}

void gameEnd(int who, time_t T){  // ���� ����
    if(who == 2){   // user�� �¸��ߴٸ�
        cout << "[User�� �̰���ϴ�. " << "���� �ҿ�ð� ��ü " << T << "���Դϴ�.]" << endl;
    }else if(who == 1){
        cout << "[Computer�� �̰���ϴ�. " << "���� �ҿ�ð� ��ü " << T << "���Դϴ�.]" << endl;
    }
}

void printGrid(char grid[][y]){   // grid �� ���
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

void originGrid(char grid[][y], char word){  // ó�� grid �ʱ�ȭ
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            grid[i][j] = word;
        }
    }
}

void putGrid(char grid[][y], char word, int wh_x, int wh_y){  // user�� grid�� X ����
    grid[wh_x][wh_y] = word;
}

void computGrid(char grid[][y], char word){  // computer�� O ����
RETRY:
    int com_x = rand() % 5;
    int com_y = rand() % 5;

    if(grid[com_x][com_y] == 'I'){  // ������ ���õ� ��ǥ�� �ƴ϶�� ���������� �Է�
        grid[com_x][com_y] = 'O';
    }else{  // ������ ���õ� ��ǥ��� �ٽ� �Է��� �ޱ�
        goto RETRY;
    }
}

int whoWin(char grid[][y], char word){ // �̱� ����� �Ǵ�. �ºΰ� �ȳ��ٸ� -1 , user�� �̰�ٸ� 2, com�� �̰�ٸ� 1
    int a = 0;

    for(int i = 0; i < x; i++){ // ���η� 5���� �������� �Ǵ�
        for(int j = 0; j < y; j++){
            if(grid[i][j] != word){
                a++;
            }
        }
        if(a != 0){
            a = 0;
        }
        else{
            if(word == 'O'){     // com�� �¸�
                return 1;
            }else if(word == 'X'){    // user�� �¸�
                return 2;
            }
        }
    }

    for(int i = 0; i < x; i++){ // ���η� 5���� �������� �Ǵ�
        for(int j = 0; j < y; j++){
            if(grid[j][i] != word){
                a++;
            }
        }
        if(a != 0){
            a = 0;
        }
        else{
            if(word == 'O'){     // com�� �¸�
                return 1;
            }else if(word == 'X'){    // user�� �¸�
                return 2;
            }
        }
    }

   if(grid[2][2] == word){
       for(int i = 0; i < x; i++){  // ���������� �������� �밢�� �Ǵ�
            if(grid[i][i] != word){
                a++;
            }
       }
       
       if(a != 0){
            a = 0;
        }
        else{
            if(word == 'O'){     // com�� �¸�
                return 1;
            }else if(word == 'X'){    // user�� �¸�
                return 2;
            }
        }

        for(int i = x; i > 0; i--){  // ���������� �ö󰡴� �밢�� �Ǵ�
            if(grid[i][i] != word){
                a++;
            }
       }
       
       if(a != 0){
            a = 0;
        }
        else{
            if(word == 'O'){     // com�� �¸�
                return 1;
            }else if(word == 'X'){    // user�� �¸�
                return 2;
            }
        }
   }

    return -1;
}