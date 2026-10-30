#include "game.h"

//初始化棋盘，mine全为‘0’，show全为‘*’
void InitBoard(char board[ROWS][COLS],int row,int col,char set){
    int i,j = 0;
for(i = 0; i <= 11;i++){
for(j = 0;j <= 11;j++){
    board[i][j] = set;
}
}
}

//展示show的图表
void Displayboard(char board[ROWS][COLS],int row,int col){
int i,j = 0;
//打印列
for(i = 0; i<= col;i++){
    printf("%d  ",i);
}
printf("\n");
for(i = 1;i<=row;i++){
printf("%d  ",i);
for(j = 1;j<= col;j++){
printf("%c  ",board[i][j]);
}
printf("\n");
}
}

//布置雷，运用随机数生成
void SetMine(char board[ROWS][COLS],int r,int c){
int count = 10;
while(count>0){
int x = rand()%r + 1;
int y = rand()%c + 1;
if(board[x][y] =='0'){
board[x][y] = '1';
count--;}
}
}

//排雷
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int r,int c){
int x = 0;
int y = 0;
int win = 0;
int number = 0;
while(win<71){
printf("请输入行和列");
scanf("%d%d",&x,&y);
if(x>=1&&x<=9&& y>=1&&y<=9){
    if(show[x][y]!='*')
printf("该坐标无效，请重新输入");
else{
    if(mine[x][y]=='1'){
        printf("对不起踩雷了");
        break;
    }else{
        number = mine[x-1][y-1]+mine[x-1][y]+mine[x-1][y+1]+mine[x][y-1]+mine[x][y+1]+mine[x+1][y-1]+mine[x+1][y]+mine[x+1][y+1]-8*'0';
    show[x][y] = number+'0';
    win++;
    Displayboard(show,ROW,COL);
    }
}
}
else{
    printf("不合法");
    continue;
}
}
}

