#include"game.h"

//函数的定义里数组类型要明确
void InitBoard(char board[ROWS][COLS],int r,int c,char set){
    int i,j =0;
    //避免数组越界，下标比实际少一，11-1=10，只写<会更正确
    for(i = 0;i < r;i++){
        for(j = 0;j<c;j++){
            board[i][j] = set;
        }
    }
}

void DisplayBoard(char board[ROWS][COLS],int a ,int b){
    int i,j = 0;
for(j = 0;j<=b;j++){
    printf("%d ",j);}
 printf("\n");
for(i = 1;i<= a;i++){
    printf("%d ",i);
    for(j = 1;j <= b;j++){
        printf("%c ",board[i][j]);
    }
    printf("\n");
}
}

void SetMine(char board[ROWS][COLS],int r, int c){
int count = 10;
while(count > 0){
   int x = rand()%r+1;
   int y = rand()%c+1;
    if(board[x][y]== '0'){
        board[x][y]='1';
        count--;
    }else
    continue;
}
}

int Getminenumber(char mine[ROWS][COLS],int x,int y){
int number = 0;
for(int i=x-1;i<=x+1;i++){
  for(int j=y-1;j<=y+1;j++){
        if(i == x&&j == y)
       continue;
        if(mine[i][j] =='1')
        number++;
   }
}
    return number;
}



//这个函数贮存只需要形参存在函数内部就行
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int r,int c){
int x,y =0;
int first_click = 1;
//int win = 0;
//int number =0;
while(1){
    printf("请输入行和列");
    scanf("%d%d",&x,&y);
if(x>=1&&x<=9&&y>=1&&y<=9){
    if(show[x][y]=='*'){
 // 3. 保护第一次有效点击
        if (first_click == 1) {
            if (mine[x][y] == '1') {
                // 第一次恰好踩到雷，就重新布雷
                InitBoard(mine, ROWS, COLS, '0');
                SetMine(mine, r, c);

                // 如果重新布雷后这里还是雷，就继续重新布雷
                while (mine[x][y] == '1') {
                    InitBoard(mine, ROWS, COLS, '0');
                    SetMine(mine, r, c);
                }
            }

            // 第一次有效点击已经得到安全保证
            first_click = 0;
        }
        if(mine[x][y]=='0'){
            //number = mine[x-1][y-1]+mine[x-1][y]+mine[x-1][y+1]+mine[x][y-1]+mine[x][y+1]+mine[x+1][y-1]+mine[x+1][y]+mine[x+1][y+1]-8*'0';
            //number=Getminenumber(mine,ROWS,COLS);
            //show[x][y] = number+'0';
            //win++;
            ExpandBoard(mine,show,x,y);//拓展为零的周围八个格子
            DisplayBoard(show,ROW,COL);
            if(checkwin(show,r,c)){
                printf("排雷成功游戏胜利");
                break;
            }
            }else{
            printf("踩雷了游戏结束\n");
            DisplayBoard(mine,ROW,COL);
            break;
        }
    }else{
    printf("已排查请重试");
    continue;}
}else
printf("坐标非法，请重新输入");
continue;
}
}

void ExpandBoard(char mine[ROWS][COLS],char show[ROWS][COLS],int x,int y){
int count = Getminenumber(mine,x,y);
show[x][y]='0'+count;
if(count ==0){
for(int i=x-1;i<=x+1; i++){
    for(int j=y-1;j<=y+1; j++){
      if(i>=1&&i<=9&&j>=1&&j<=9){
    if(show[i][j]=='*'){
       
                ExpandBoard(mine,show,i,j);//展开[x][y]周围的格子
            }  
    }
    else continue;
}
}

}}

int checkwin(char show[ROWS][COLS],int r,int c){
int star_count = 0;
for(int i=1;i<=r;i++){
for(int j = 1;j<=c;j++){
if(show[i][j] =='*'){
    star_count++;
}
}
}
if(star_count  ==10){
    return 1;
}
return 0;

}

 