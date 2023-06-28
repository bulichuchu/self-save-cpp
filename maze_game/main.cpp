#include <iostream>
#include<cstdlib>
#include<fstream>
using namespace std;

int player_dir=0;
int score = 0;
const int M = 50;
const int N = 50;
const char maze_wall = '#';
const char maze_player = '@';
const char maze_path = ' ';
const char maze_treasure = '$';
const char maze_enemy = 'x';
const char savedFile[] = "D:/CLionProjects/maze_game/saved_game.txt";

double getrand(double min, double max);
void generateMap(char matrix[][N], int m, int n, int difficulty);
void displayMap(char matrix[][N], int m, int n);
bool saveGame(char matrix[][N], int m, int n);
bool loadGame(char matrix[][N]);
int statusGame(char matrix[][N], int m, int n);
bool movePlayer(char matrix[][N], int m, int n, int dir);
void moveEnemy(char matrix[][N], int m, int n);
bool isWall(char matrix[][N], int x, int y);
bool isOutside(char matrix[][N], int x, int y);
bool isTreasure(char matrix[][N], int x, int y);
bool isEnemy(char matrix[][N], int x, int y);



double getrand(double min, double max){
    return min + (max - min) * rand() / RAND_MAX;//加上min到max之间的数
}



//生成迷宫，m 和 n 分别表示迷宫的行数和列数
//difficulty 代表难易程度，可以采用不同级别表示
void generateMap(char matrix[][N], int m, int n, int difficulty) {

    for (int row = 0; row < m; ++row) {
        for (int column = 0; column < n; ++column) {
            if (rand() % 3 == 0) {
                matrix[row][column] = maze_wall;
            } else {
                matrix[row][column] = maze_path;
            }
        }
    }//随机生成迷宫

    for (int row = 0; row < m; ++row) {
        for (int column = 0; column < n; ++column) {
            if((matrix[row][column] == maze_path)&&(rand() % 2 == 0)&&difficulty!=0){
                matrix[row][column] = maze_enemy;
                difficulty--;
            }
        }
    }//随机生成敌人，difficulty数就是敌人数

    for (int i = 0; i < 5; ++i) {
        int row = rand() % m;
        int column = rand() % n;
        if (matrix[row][column] == maze_path) {
            matrix[row][column] = maze_treasure;
        } else {
            --i;
        }
    }
    //随机生成宝藏，宝藏数是5，difficulty数越大宝藏越小


    int row = rand() % m;
    int column = rand() % n;
    if (matrix[row][column] == maze_path && matrix[row][column]!=maze_enemy)
        matrix[row][column] = maze_player;
    else
        matrix[0][0] = maze_player;
    //随机生成玩家，玩家只有一个，位置随机

}

//打印迷宫
void displayMap(char matrix[][N], int m, int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j];
        }
        cout << endl;
    }
}


//游戏存档，将游戏的当前状态存储到 saved_game.txt 文件中
//如果游戏存档成功，则返回 true；否则，返回 false
bool saveGame(char matrix[][N], int m, int n) {
    ofstream fout(savedFile);
    if (!fout) {
        return false;
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            fout << matrix[i][j];
        }
        fout << endl;
    }
    cout << "游戏已存档" << endl;
    fout.close();
    return true;
}

//读档游戏，读取 saved_game.txt 游戏存档文件，恢复游戏
//如果游戏读档成功，则返回 true；否则，返回 false
bool loadGame(char matrix[][N]) {
    ifstream fin(savedFile);
    if (!fin) {
        return false;
    }
    for (int i = 0; i < M; ++i) {
        fin.getline(matrix[i], N);
    }
    fin.close();
    cout << "游戏已读档" << endl;
    return true;
}


//判断游戏当前状态：找到宝藏返回 1；与敌人相撞返回 2；继续游戏返回 3
int statusGame(char matrix[][N], int m, int n) {
    int player_x, player_y;
    for (int row = 0; row < m; ++row) {
        for (int column = 0; column < n; ++column) {
            if (matrix[row][column] == maze_player) {
                player_x = column;
                player_y = row;
            }
        }
    }

    switch (player_dir) {
        case 1:
            if (isEnemy(matrix, player_x, player_y + 1)) {
                return 2;
            }
            if (isTreasure(matrix, player_x, player_y + 1)) {
                return 1;
            }
            break;
        case 2:
            if (isEnemy(matrix, player_x, player_y - 1)) {
                return 2;
            }
            if (isTreasure(matrix, player_x, player_y - 1)) {
                return 1;
            }
            break;
        case 3:
            if (isEnemy(matrix, player_x + 1, player_y)) {
                return 2;
            }
            if (isTreasure(matrix, player_x + 1, player_y)) {
                return 1;
            }
            break;
        case 4:
            if (isEnemy(matrix, player_x - 1, player_y)) {
                return 2;
            }
            if (isTreasure(matrix, player_x - 1, player_y)) {
                return 1;
            }
            break;
    }
}

//判断位置(x, y)是否是墙，y 表示行号，x 表示列号
bool isWall(char matrix[][N], int x, int y) {
    if (matrix[y][x] == maze_wall) {
        return true;
    }
    return false;
}

//判断位置(x, y)是否出界，y 表示行号，x 表示列号
bool isOutside(char matrix[][N], int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= M) {
        return true;
    }
    return false;
}

//判断位置(x, y)是否是敌人，y 表示行号，x 表示列号
bool isEnemy(char matrix[][N], int x, int y) {
    if (matrix[y][x] == maze_enemy) {
        return true;
    }
    return false;
}

//判断位置(x, y)是否是宝藏，y 表示行号，x 表示列号
bool isTreasure(char matrix[][N], int x, int y) {
    if (matrix[y][x] == maze_treasure) {
        return true;
    }
    return false;
}

//移动玩家的位置，如果移动成功，返回 true；否则返回 false
//dir 表示输入的方向，（1,2,3,4）分别对应（上,下,左,右）
bool movePlayer(char matrix[][N], int m, int n, int dir=0) {//**
    int x, y;
    char ch;
    cout<<"请输入移动方向："<<endl;
    cout<<"W上"<<endl;
    cout<<"S下"<<endl;
    cout<<"A左"<<endl;
    cout<<"D右"<<endl;
    cin>>ch;
    if (ch=='W'||ch=='w')dir=1;
    else if (ch=='S'||ch=='s')dir=2;
    else if (ch=='A'||ch=='a')dir=3;
    else dir=4;
    player_dir=dir;

    for (int row = 0; row < m; ++row) {
        for (int column = 0; column < n; ++column) {
            if (matrix[row][column] == maze_player) {
                x = column;
                y = row;
            }
        }
    }//找到玩家的位置

    switch (dir) {
        case 1:
            if (isOutside(matrix, x, y - 1) || isWall(matrix, x, y - 1)) {
                cout<<"撞墙或出界了"<<endl;
                return false;
            }
            if (isEnemy(matrix, x, y - 1)) {
                matrix[y][x] = maze_enemy;
                matrix[y - 1][x] = maze_player;
                break;
            }
            if (isTreasure(matrix,x,y-1)){
                matrix[y][x] = maze_treasure;
                matrix[y - 1][x] = maze_player;
                break;
            }
            matrix[y][x] = maze_path;
            matrix[y - 1][x] = maze_player;
            break;
        case 2:
            if (isOutside(matrix, x, y + 1) || isWall(matrix, x, y + 1)) {
                cout<<"撞墙或出界了"<<endl;
                return false;
            }
            if (isEnemy(matrix, x, y + 1)) {
                matrix[y][x] = maze_enemy;
                matrix[y + 1][x] = maze_player;
                break;
            }
            if (isTreasure(matrix,x,y + 1)){
                matrix[y][x] = maze_treasure;
                matrix[y + 1][x] = maze_player;
                break;
            }
            matrix[y][x] = maze_path;
            matrix[y + 1][x] = maze_player;
            break;
        case 3:
            if (isOutside(matrix, x - 1, y) || isWall(matrix, x - 1, y)) {
                cout<<"撞墙或出界了"<<endl;
                return false;
            }
            if (isEnemy(matrix, x - 1, y)) {
                matrix[y][x] = maze_enemy;
                matrix[y][x - 1] = maze_player;
                break;
            }
            if (isTreasure(matrix,x - 1, y)){
                matrix[y][x] = maze_treasure;
                matrix[y][x-1] = maze_player;
                break;
            }
            matrix[y][x] = maze_path;
            matrix[y][x - 1] = maze_player;
            break;
        case 4:
            if (isOutside(matrix, x + 1, y) || isWall(matrix, x + 1, y)) {
                cout<<"撞墙或出界了"<<endl;
                return false;
            }
            if (isEnemy(matrix, x + 1, y)) {
                matrix[y][x] = maze_enemy;
                matrix[y][x + 1] = maze_player;
                break;
            }
            if (isTreasure(matrix,x + 1, y)){
                matrix[y][x] = maze_treasure;
                matrix[y][x+1] = maze_player;
                break;
            }
            matrix[y][x] = maze_path;
            matrix[y][x + 1] = maze_player;
            break;
    }

    return true;
}

//随机移动所有敌人的位置,每次移动一个位置
void moveEnemy(char matrix[][N], int m, int n) {
    for (int row = 0; row < m; ++row) {
        for (int column = 0; column < n; ++column) {
            if (matrix[row][column] == maze_enemy) {
                int dir = rand() % 4 + 1;
                switch (dir) {
                    case 1:
                        if (isOutside(matrix, column, row - 1) || isWall(matrix, column, row - 1)||
                        isTreasure(matrix,column,row-1)||isEnemy(matrix,column,row-1)) {
                            break;
                        }
                        matrix[row][column] = maze_path;
                        matrix[row - 1][column] = maze_enemy;
                        break;
                    case 2:
                        if (isOutside(matrix, column, row + 1) || isWall(matrix, column, row + 1)||
                        isTreasure(matrix,column,row+1)||isEnemy(matrix,column,row+1)) {
                            break;
                        }
                        matrix[row][column] = maze_path;
                        matrix[row + 1][column] = maze_enemy;
                        break;
                    case 3:
                        if (isOutside(matrix, column - 1, row) || isWall(matrix, column - 1, row)||
                        isTreasure(matrix,column-1,row)||isEnemy(matrix,column-1,row)) {
                            break;
                        }
                        matrix[row][column] = maze_path;
                        matrix[row][column - 1] = maze_enemy;
                        break;
                    case 4:
                        if (isOutside(matrix, column + 1, row) || isWall(matrix, column + 1, row)||
                        isTreasure(matrix,column+1,row)||isEnemy(matrix,column+1,row)) {
                            break;
                        }
                        matrix[row][column] = maze_path;
                        matrix[row][column + 1] = maze_enemy;
                        break;
                    default:
                        break;
                }
            }
        }
    }
}

int main() {
    char matrix[M][N],restrat_matrix[M][N];
    int m, n, difficulty;
    cout << "请输入迷宫的行数和列数：";
    cin >> m >> n;
    cout << "迷宫的难易程度：" << endl <<
         " 1: 简单" << endl <<
         " 2: 中等" << endl <<
         " 3: 困难" << endl <<
         "请选择本次游戏的难度：";
    cin >> difficulty;
    generateMap(matrix, m, n, difficulty);

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j){
            restrat_matrix[i][j]=matrix[i][j];
        }
    }

    cout << endl << "---------------游戏开始！---------------" << endl << endl;
    displayMap(matrix, m, n);
    int choice;
    do {

        cout<<"请选择操作："<<endl;
        cout<<"1.移动"<<endl;
        cout<<"2.保存"<<endl;
        cout<<"3.读取"<<endl;
        cout<<"4.重新开始"<<endl;
        cout<<"5.退出"<<endl;
        cin>>choice;
        switch(choice){
            case 1:
                movePlayer(matrix,m,n);
                if (statusGame(matrix,m,n)==1){
                    cout<<"恭喜你，找到宝藏！"<<endl;
                   score++;
                }
                if (statusGame(matrix,m,n)==2){
                    cout<<"碰到敌人，游戏结束！"<<endl;
                    cout<<"你的分数是："<<score<<endl;
                    system("pause");
                    return 0;
                }

                moveEnemy(matrix,m,n);
                displayMap(matrix,m,n);
                break;
            case 2:
                saveGame(matrix,m,n);
                displayMap(matrix, m, n);
                break;
            case 3:
                loadGame(matrix);
                displayMap(matrix, m, n);
                break;
            case 4:
                cout<<"游戏重新开始！"<<endl;
                for (int i = 0; i < M; ++i) {
                    for (int j = 0; j < N; ++j){
                        matrix[i][j]=restrat_matrix[i][j];
                    }
                }
                displayMap(matrix, m, n);
                break;
            case 5:
                cout<<"你的分数是："<<score<<endl;
                system("pause");
                return 0;
            default:
                cout<<"输入错误，请重新输入！"<<endl;
        }
    }
    while(choice!=0);
}