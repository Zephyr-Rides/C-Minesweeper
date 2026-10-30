
//头文件不要分号
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//宏定义不要分号
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
//函数的声明要加分号
void InitBoard(char board[ROWS][COLS],int r,int c,char set);
void DisplayBoard(char board[ROWS][COLS],int a, int b);
void SetMine(char board[ROWS][COLS],int r, int c);
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int r,int c);
void ExpandBoard(char mine[ROWS][COLS],char show[ROWS][COLS],int x,int y);
int Getminenumber(char mine[ROWS][COLS],int x,int y);
int checkwin(char show[ROWS][COLS],int r,int c);