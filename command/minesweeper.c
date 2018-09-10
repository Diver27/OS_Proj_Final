#include "stdio.h"

#define row 12
#define col 12
#define MINENUM 10//棋盘中雷的总数
char displayMap[row][col] = { 0 };
char realMap[row][col] = { 0 };
char originalMineMap[row][col] = {'0','0','0','0','0','0','0','0','0','0','0','0',
                                  '0','1','0','0','0','0','0','0','0','0','0','0',
                                  '0','0','0','0','0','0','1','0','0','0','0','0',
                                  '0','0','0','0','0','0','1','0','0','0','0','0',
                                  '0','0','0','1','0','0','0','0','0','0','0','0',
                                  '0','0','0','0','0','0','0','0','0','1','0','0',
                                  '0','0','0','0','0','1','0','0','0','0','0','0',
                                  '0','0','0','0','0','0','0','0','0','0','1','0',
                                  '0','0','0','1','0','0','0','0','0','0','0','0',
                                  '0','0','0','0','0','0','0','1','0','0','0','0',
                                  '0','0','0','0','0','1','0','0','0','0','0','0',
                                  '0','0','0','0','0','0','0','0','0','0','0','0'};


void printStartPage() {
        printf("________                           \n"
           "___  __ )______ ______ _______ ___ \n"
           "__  __  |_  __ \\_  __ \\__  __ `__ \\\n"
           "_  /_/ / / /_/ // /_/ /_  / / / / /\n"
           "/_____/  \\____/ \\____/ /_/ /_/ /_/ \n"
           "________                                \n"
           "__  ___/___      _______ _____ ________ \n"
           "_____ \\ __ | /| / /_  _ \\_  _ \\___  __ \\\n"
           "____/ / __ |/ |/ / /  __//  __/__  /_/ /\n"
           "/____/  ____/|__/  \\___/ \\___/ _  .___/ \n"
           "                               /_/      \n");
    printf("*********************************************************\n");
    printf("******* 1.Play    2.Command List    0.Exit     **********\n");
    printf("*********************************************************\n");
}

void printDisplayMap(){//打印玩家棋盘
    printf("0  ");
    for (int i = 1; i <row-1; i++)
    {
        printf("%d ", i);//打印横标（0--10）
    }
    printf("\n");
    for (int i = 1; i <row-2; i++)//打印竖标（1--10）
    {
        printf("%d  ", i);
        for (int j = 1; j < col-1; j++)
        {
            printf("%c ", displayMap[i][j]);//玩家棋盘数组
        }
        printf("\n");
    }
    printf("10 ");//开始打印最后一行
    for (int i = 1; i < row-1; i++)
    {
        printf("%c ", displayMap[10][i]);
    }
    printf("\n");
}

void printRealMap(){//打印设计者棋盘
    printf("   ");
    for (int i = 1; i <row - 1; i++)
    {
        printf("%d ", i);//打印横标（0--10）
    }
    printf("\n");
    for (int i = 1; i <row - 2; i++)//打印竖标（1--10）
    {
        printf("%d  ", i);
        for (int j = 1; j < col - 1; j++)
        {
            printf("%c ", realMap[i][j]);
        }
        printf("\n");
    }
    printf("10 ");//开始打印最后一行
    for (int i = 1; i < row - 1; i++)
    {
        printf("%c ", realMap[10][i]);
    }
    printf("\n");
}

void printCommandList(){
    printf("*************************************************************\n"
           "***************          CommandList          ***************\n"
           "*************************************************************\n"
           "e    Shift back to the menu.\n"
	   "m    Show the game map.\n"
           "s    Sweep the location (x, y), followed by the input of \"x y\".\n"
           "p    Pin the location (x, y) where you think hides a bomb.\n"
           "u    Remove your pin on (x, y).\n"
           "c    Show the command list.\n"
           "h    Print the real map.\n"
           "n    Sweep a block safely.\n"
    );
}

void init(){
    //初始化两个棋盘
    for (int i = 1; i < row - 1; i++) {
        for (int j = 1; j < col - 1; j++) {
            displayMap[i][j] = '*';
            realMap[i][j] = '0';
        }
    }
    //布雷
    for (int i = 1; i < row - 1; i++) {
        for (int j = 1; j < col - 1; j++) {
            if(originalMineMap[i][j] == '1'){
                realMap[i][1 + (5 + 2 * j) % 10] = '1';
                originalMineMap[i][j] = '0';
                originalMineMap[i][1 + (5 + 2 * j) % 10] = '1';
                break;
            }
        }
    }
    /*
    int mineNum = MINENUM;//雷总数
    while (mineNum)
    {
        int x = rand() % 10 + 1;
        int y = rand() % 10 + 1;
        if (realMap[x][y] == '0')
        {
            realMap[x][y] = '1';
            mineNum--;
        }
    }
    */
}

int countNearByMines(int x, int y){//检测周围8个区域雷的个数
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (!(i == 0 && j ==0) && x + i >= 1 && x + i <= 10 && y + j >= 1 && y + j <= 10 && realMap[x + i][y + j] == '1') {
                count++;
            }
        }
    }
    return count;
}

void clearUnknown(int x, int y){
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (!(i == 0 && j ==0) && x + i <= 10 && y + j >= 1 && y + j <= 10 && realMap[x + i][y + j] == '0' && displayMap[x + i][y + j] == '*') {
                displayMap[x + i][y + j] = countNearByMines(x + i, y + j) + '0';
                if (displayMap[x + i][y + j] == '0') {
                    clearUnknown(x + i, y + j);
                }
            }
        }
    }
}

void safeSweep(int x, int y){//避免第一次炸死
    int flag = 1;
    if (realMap[x][y] == '1'){//第一次踩到雷
        realMap[x][y] = '0';
        while (flag > 0){//在其余有空的地方设置一个雷
            for (int i = 1; i < row - 1; i++) {
                for (int j = 1; j < col - 1; j++) {
                    if (realMap[i][j] == '0' && ( displayMap[i][j] == '*' || displayMap[i][j] == 'M')){//找不是雷的地方布雷
                        realMap[i][j] = '1';
                        flag--;
                        break;
                    }
                }
                if(flag == 0) break;
            }
            break;
        }
    }
    displayMap[x][y] = countNearByMines(x, y) + '0';
    clearUnknown(x, y);
}

int countLeftUnknown(){//判断剩余未知区域的个数，个数为雷数时玩家赢
    int count = 0;
    for (int i = 1; i <= row - 1; i++) {
        for (int j = 1; j <= col - 1; j++) {
            if (displayMap[i][j] == '*' || displayMap[i][j] == 'M') {
                count++;
            }
        }
    }
    return count;
}

int sweepMine(int x, int y){//扫雷函数，踩到雷返回1，没有踩到雷返回0
    int count = 0;
    if (realMap[x][y] == '0'){//没踩到雷
        displayMap[x][y] = countNearByMines(x, y) + '0';//数字对应的ASCII值和数字字符对应的ASCII值相差48，即'0'的ASCII值
        clearUnknown(x, y);
    }
    else return 1;
    return 0;
}

void clearScreen(){
    for (int i = 0; i < 25; i++) {
        printf("\n");
    }
}

void pin(int x, int y) {
    if(displayMap[x][y] == '*'){
        displayMap[x][y] = 'M';
    }
}

void unpin(int x, int y){
    if(displayMap[x][y] == 'M'){
        displayMap[x][y] = '*';
    }
}



void game() {
    init();
    int startFlag = 1;
    clearScreen();
    printDisplayMap();
    while (1) {
        int result = 0;
        char bufr[128];
	memset(bufr,0,128);
        read(0, bufr, 128);
	clearScreen();
        if (bufr[0] == 's') {
	    if(!((bufr[2] - '0') >= 1 && (bufr[2] -'0') <= 10 && (bufr[4] - '0') >= 1 && (bufr[4] - '0') <= 10)){
	        printf("Your input is out of boud. Please make sure x and y are between 1 and 10.\n");
		continue;
	    }
            if(startFlag == 1){
                safeSweep(bufr[2]-'0',bufr[4]-'0');
                startFlag--;
            } else{
                result = sweepMine(bufr[2]-'0',bufr[4]-'0'); //踩到雷返回1，没有踩到雷返回0
            }
	    printDisplayMap();
        } else if (bufr[0] == 'e'){
            return;
        } else if (bufr[0] == 'h'){
            printRealMap();
        } else if (bufr[0] == 'p'){
	    if(!((bufr[2] - '0') >= 1 && (bufr[2] -'0') <= 10 && (bufr[4] - '0') >= 1 && (bufr[4] - '0') <= 10)){
	        printf("Your input is out of boud. Please make sure x and y are between 1 and 10.\n");
		continue;
	    }
            pin(bufr[2]-'0',bufr[4]-'0');
	    printDisplayMap();
        } else if (bufr[0] == 'u'){
	    if(!((bufr[2] - '0') >= 1 && (bufr[2] -'0') <= 10 && (bufr[4] - '0') >= 1 && (bufr[4] - '0') <= 10)){
	        printf("Your input is out of boud. Please make sure x and y are between 1 and 10.\n");
		continue;
	    }
            unpin(bufr[2]-'0',bufr[4]-'0');
	    printDisplayMap();
        } else if (bufr[0] == 'c'){
            printCommandList();
	    continue;
        } else if (bufr[0] == 'n'){
	    clearScreen();
            safeSweep(bufr[2]-'0',bufr[4]-'0');
	    printDisplayMap();
	} else if (bufr[0] == 'm'){
	    printDisplayMap();
	    continue;
        } else {
	    printf("No such command. Please try again.\n");
	    printDisplayMap();
	    continue;
	}
        if (countLeftUnknown() == MINENUM){
    		printf("___       __               \n"
           		"__ |     / /______ _______ \n"
           		"__ | /| / / _  __ \\__  __ \\\n"
           		"__ |/ |/ /  / /_/ /_  / / /\n"
           		"____/|__/   \\____/ /_/ /_/ \n"
           		"                           \n");
            printRealMap();
	    printf("Type \"e\" to go back to menu;\n");
        }
        if (result){
            printf("________                           \n"
           "___  __ )______ ______ _______ ___ \n"
           "__  __  |_  __ \\_  __ \\__  __ `__ \\\n"
           "_  /_/ / / /_/ // /_/ /_  / / / / /\n"
           "/_____/  \\____/ \\____/ /_/ /_/ /_/ \n"
           "                                   \n");
            printRealMap();
	    printf("Type \"e\" to go back to menu;\n");
        }
        //clearScreen();
        //printDisplayMap();
    }
}

int main() {
    int input = 0;
    printStartPage();
    while(1) {
        char bufr[128];
	memset(bufr,0,128);
        read(0, bufr, 128);
        //switch (input) {
        if(bufr[0]=='1'){
            game();
           }else if(bufr[0]=='2'){
            printCommandList();
            }else if(bufr[0]=='0'){
            return 0;//退出游戏
            }
	else{
            printf("Invalid command\n");
        }
        printStartPage();
    }
}
