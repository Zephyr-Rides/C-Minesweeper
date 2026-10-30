#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
void InitBoard(char board[ROWS][COLS],int row,int col,char set);
void Displayboard(char board[ROWS][COLS],int row,int col);
void SetMine(char board[ROWS][COLS],int r,int c);
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int r,int c);
int Getminenumber(char mine[ROWS][COLS],int r,int c);