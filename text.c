#include"game.h"
 void game(){
    char mine[ROWS][COLS];
    char show[ROWS][COLS];
    InitBoard(mine,ROWS,COLS,'0');
    InitBoard(show,ROWS,COLS,'*');
    Displayboard(show,ROW,COL);
    SetMine(mine,ROW,COL);
    //Displayboard(mine,ROW,COL);
    FindMine(mine,show,ROW,COL);
    }
int main(){
printf("游戏开始\n");
printf("----------------------------------\n");
printf("-----------1  游戏开始-------------\n");
printf("-----------0  退出游戏-------------\n");
printf("----------------------------------\n");
srand((unsigned)time(NULL));
int input = 0;
scanf("%d", &input);
if(input == 0){
    printf("游戏结束，已退出");
}
else{
    printf("开始游戏\n");
    game();

}

return 0;
}