#pragma once
#include "resource.h"
void DrawLine(HDC hdc, int x1, int x2, int y1, int y2);
void DrawBoard(HDC hdc);
void Startgame();
void Fallbrick(int dy, int dx, int dr);
void brick1(int x_con, int y_con, int rota);
void brick2(int x_con, int y_con, int rota);
void brick3(int x_con, int y_con, int rota);
void brick4(int x_con, int y_con, int rota);
void brick5(int x_con, int y_con, int rota);
void brick6(int x_con, int y_con, int rota);
void brick7(int x_con, int y_con, int rota);
void resetBrick();
void deleteMess();
void paintBrick(int pole[4]);
void checkPos();
void checkLines();
void deleteRow(int index[4], int lines);
void switchLines(int index);
int sumRow(int index);
void DrawNextBrick(HDC hdc, int padding, int size, int x, int starty);
void endGame();
bool kubovaPicovina(int dy, int dx, int dr);
int borders(int x);