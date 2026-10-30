#include"game.h"//引用自定义头文件
void game(){
    //定义二维数组
   char mine[ROWS][COLS];
   char show[ROWS][COLS];
   //注意函数使用中数组的表示方法
   InitBoard(mine,ROWS,COLS,'0');
   InitBoard(show,ROWS,COLS,'*');
   DisplayBoard(show,ROW,COL);
   SetMine(mine,ROW,COL);
   FindMine(mine,show,ROW,COL);
}
int main(){
printf("----------------------------------------------\n");
printf("--------------1  game begin-------------------\n");
printf("--------------0  game over--------------------\n");
printf("----------------------------------------------\n");
int input = 0;
//这个srand在interesting中出现一次就行
srand((unsigned)time(NULL));
scanf("%d",&input);
if(input != 0){
    game();
}
else {printf("game over");}
    return 0;
}