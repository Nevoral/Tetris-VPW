// Tetris.cpp : Definuje vstupní bod pro aplikaci.
//
#include <iostream>
#include <thread>
#include <vector>
using namespace std;

#include <stdio.h>
#include <Windows.h>
#include "resource.h"
#include "framework.h"
#include "Tetris.h"

#define MAX_LOADSTRING 100
const int offset_x = 190;
const int offset_y = 65;
int dx, dy, dr;
int x, y, pol, rot;
int score, level, line;
bool game;

const int rows = 21;
const int collumns = 10;

//int randBlock[5000];
int randBlock[7] = { 0,1,2,3,4,5,6 };
int game_board[rows][collumns] = { {0,0,0,0,0,0,0,0,0,0},
									   {0,0,0,0,0,0,0,0,0,0},
									   {0,0,0,0,0,0,0,0,0,0},
									   {0,0,0,0,0,0,0,0,0,0},
									   {0,0,0,0,0,0,0,0,0,0},
									   {0,0,0,0,0,0,0,0,0,0},
									   {0,0,0,0,0,0,0,0,0,0},
									   {0,0,0,0,0,0,0,0,0,0},
									   {0,0,0,0,0,0,0,0,0,0},
									   {0,0,0,0,0,0,0,0,0,0},
									   {0,0,0,0,0,0,0,0,0,0},
									   {0,0,0,0,0,0,0,0,0,0},
									   {0,0,0,0,0,0,0,0,0,0},
									   {0,0,0,0,0,0,0,0,0,0},
									   {0,0,0,0,0,0,0,0,0,0},
									   {0,0,0,0,0,0,0,0,0,0},
									   {0,0,0,0,0,0,0,0,0,0},
									   {0,0,0,0,0,0,0,0,0,0},
									   {0,0,0,0,0,0,0,0,0,0},
									   {0,0,0,0,0,0,0,0,0,0},
									   {8,8,8,8,8,8,8,8,8,8} };

int lastPos[4] = { 0,0,0,0 };
int newPos[4] = { 0,0,0,0 };
void DrawNextBrick(HDC hdc, int padding, int size, int x, int starty) {
	RECT rc;
	BYTE red, green, blue;
	switch (randBlock[pol + 1] + 1)
	{
	case 1:
		red = 252;
		green = 186;
		blue = 3;
		break;
	case 2:
		red = 201;
		green = 48;
		blue = 6;
		break;
	case 3:
		red = 57;
		green = 201;
		blue = 4;
		break;
	case 4:
		red = 4;
		green = 90;
		blue = 201;
		break;
	case 5:
		red = 87;
		green = 0;
		blue = 163;
		break;
	case 6:
		red = 191;
		green = 4;
		blue = 176;
		break;
	case 7:
		red = 2;
		green = 201;
		blue = 195;
		break;
	default:
		red = 255;
		green = 255;
		blue = 255;
		break;
	}
	for (int i = 0; i < 4; i++) {
		switch (red)
		{
		case 252:
			switch (i)
			{
			case 0:
				rc.left = x + 53;
				rc.right = rc.left + size - padding;
				rc.top = starty + 17;
				rc.bottom = rc.top + size - padding;
				break;
			case 1:
				rc.left = x + 53;
				rc.right = rc.left + size - padding;
				rc.top = starty + 17 + i * size;
				rc.bottom = rc.top + size - padding;
				break;
			case 2:
				rc.left = x + 53;
				rc.right = rc.left + size - padding;
				rc.top = starty + 17 + i * size;
				rc.bottom = rc.top + size - padding;
				break;
			default:
				rc.left = x + 53;
				rc.right = rc.left + size - padding;
				rc.top = starty + 17 + i * size;
				rc.bottom = rc.top + size - padding;
				break;
			}
			break;
		case 201:
			switch (i)
			{
			case 0:
				rc.left = x + 53;
				rc.right = rc.left + size - padding;
				rc.top = starty + 87;
				rc.bottom = rc.top + size - padding;
				break;
			case 1:
				rc.left = x + 53 - i * size;
				rc.right = rc.left + size - padding;
				rc.top = starty + 87;
				rc.bottom = rc.top + size - padding;
				break;
			case 2:
				rc.left = x + 53 + 1 * size;
				rc.right = rc.left + size - padding;
				rc.top = starty + 87;
				rc.bottom = rc.top + size - padding;
				break;
			default:
				rc.left = x + 53;
				rc.right = rc.left + size - padding;
				rc.top = starty + 52;
				rc.bottom = rc.top + size - padding;
				break;
			}
			break;
		case 57:
			switch (i)
			{
			case 0:
				rc.left = x + 35;
				rc.right = rc.left + size - padding;
				rc.top = starty + 52;
				rc.bottom = rc.top + size - padding;
				break;
			case 1:
				rc.left = x + 70;
				rc.right = rc.left + size - padding;
				rc.top = starty + 52;
				rc.bottom = rc.top + size - padding;
				break;
			case 2:
				rc.left = x + 35;
				rc.right = rc.left + size - padding;
				rc.top = starty + 87;
				rc.bottom = rc.top + size - padding;
				break;
			default:
				rc.left = x + 70;
				rc.right = rc.left + size - padding;
				rc.top = starty + 87;
				rc.bottom = rc.top + size - padding;
				break;
			}
			break;
		case 4:
			switch (i)
			{
			case 0:
				rc.left = x + 70;
				rc.right = rc.left + size - padding;
				rc.top = starty + 35;
				rc.bottom = rc.top + size - padding;
				break;
			case 1:
				rc.left = x + 70;
				rc.right = rc.left + size - padding;
				rc.top = starty + 70;
				rc.bottom = rc.top + size - padding;
				break;
			case 2:
				rc.left = x + 35;
				rc.right = rc.left + size - padding;
				rc.top = starty + 70;
				rc.bottom = rc.top + size - padding;
				break;
			default:
				rc.left = x + 35;
				rc.right = rc.left + size - padding;
				rc.top = starty + 105;
				rc.bottom = rc.top + size - padding;
				break;
			}
			break;
		case 87:
			switch (i)
			{
			case 0:
				rc.left = x + 35;
				rc.right = rc.left + size - padding;
				rc.top = starty + 35;
				rc.bottom = rc.top + size - padding;
				break;
			case 1:
				rc.left = x + 35;
				rc.right = rc.left + size - padding;
				rc.top = starty + 70;
				rc.bottom = rc.top + size - padding;
				break;
			case 2:
				rc.left = x + 70;
				rc.right = rc.left + size - padding;
				rc.top = starty + 70;
				rc.bottom = rc.top + size - padding;
				break;
			default:
				rc.left = x + 70;
				rc.right = rc.left + size - padding;
				rc.top = starty + 105;
				rc.bottom = rc.top + size - padding;
				break;
			}
			break;;
		case 191:
			switch (i)
			{
			case 0:
				rc.left = x + 35;
				rc.right = rc.left + size - padding;
				rc.top = starty + 35;
				rc.bottom = rc.top + size - padding;
				break;
			case 1:
				rc.left = x + 35;
				rc.right = rc.left + size - padding;
				rc.top = starty + 70;
				rc.bottom = rc.top + size - padding;
				break;
			case 2:
				rc.left = x + 35;
				rc.right = rc.left + size - padding;
				rc.top = starty + 105;
				rc.bottom = rc.top + size - padding;
				break;
			default:
				rc.left = x + 70;
				rc.right = rc.left + size - padding;
				rc.top = starty + 105;
				rc.bottom = rc.top + size - padding;
				break;
			}
			break;
		case 2:
			switch (i)
			{
			case 0:
				rc.left = x + 70;
				rc.right = rc.left + size - padding;
				rc.top = starty + 35;
				rc.bottom = rc.top + size - padding;
				break;
			case 1:
				rc.left = x + 70;
				rc.right = rc.left + size - padding;
				rc.top = starty + 70;
				rc.bottom = rc.top + size - padding;
				break;
			case 2:
				rc.left = x + 70;
				rc.right = rc.left + size - padding;
				rc.top = starty + 105;
				rc.bottom = rc.top + size - padding;
				break;
			default:
				rc.left = x + 35;
				rc.right = rc.left + size - padding;
				rc.top = starty + 105;
				rc.bottom = rc.top + size - padding;
				break;
			}
			break;
		default:
			break;
		}
		HBRUSH brush = CreateSolidBrush(RGB(red, green, blue));
		FillRect(hdc, &rc, brush);
		DeleteObject(brush);
	}
}
void DrawBoard(HDC hdc) {
	RECT rc;
	int size = 35;
	int padding = 1;
	int startx = offset_x - 5;
	int starty = offset_y - 5;
	int x = 20;
	BYTE red, green, blue;
	Rectangle(hdc, startx, starty, 10 * (size + padding) + startx, (int)(20 * ((double)size + (double)padding * 0.5)) + starty);
	Rectangle(hdc, x, starty, x + 140, starty + 175);
	for (int i = 0; i < rows - 1; i++) {
		for (int j = 0; j < collumns; j++) {
			rc.left = offset_x + padding + j * size;
			rc.right = rc.left + size - padding;
			rc.top = offset_y + padding + i * size;
			rc.bottom = rc.top + size - padding;

			switch (game_board[i][j])
			{
			case 1:
				red = 252;
				green = 186;
				blue = 3;
				break;
			case 2:
				red = 201;
				green = 48;
				blue = 6;
				break;
			case 3:
				red = 57;
				green = 201;
				blue = 4;
				break;
			case 4:
				red = 4;
				green = 90;
				blue = 201;
				break;
			case 5:
				red = 87;
				green = 0;
				blue = 163;
				break;
			case 6:
				red = 191;
				green = 4;
				blue = 176;
				break;
			case 7:
				red = 2;
				green = 201;
				blue = 195;
				break;
			default:
				red = 255;
				green = 255;
				blue = 255;
				break;
			}
			if (red != 255) {
				HBRUSH brush = CreateSolidBrush(RGB(red, green, blue));
				FillRect(hdc, &rc, brush);
				DeleteObject(brush);
				DrawNextBrick(hdc, padding, size, x, starty);
			}
			else if (game) Rectangle(hdc, offset_x + padding + j * size, offset_y + padding + i * size, offset_x + (j + 1) * size, offset_y + (i + 1) * size);
			else {
				HBRUSH brush = CreateSolidBrush(RGB(136, 136, 136));
				FillRect(hdc, &rc, brush);
				DeleteObject(brush);
				DrawNextBrick(hdc, padding, size, x, starty);;
			}
		}
	}
}
void Startgame() {
	int num = sizeof(randBlock)/ sizeof(*randBlock);
	if (num > 1) {
		for (int i = 0; i < num; i++) {
			randBlock[i] = rand() % 7;
		}
	}
	Fallbrick(dy, dx, dr);
}
void deleteMess() {
	for (int i = 0; i < 4; i++) {
		int x_con = (lastPos[i] % collumns) - 1;
		int y_con = (int)(lastPos[i] - x_con - 1) / collumns;
		game_board[y_con][x_con] = 0;
	}
}
void paintBrick(int pole[4]) {
	for (int i = 0; i < 4; i++) {
		int x_con = (pole[i] % collumns) - 1;
		int y_con = (int)(pole[i] - x_con - 1) / collumns;
		game_board[y_con][x_con] = randBlock[pol] + 1;
	}
}
int sumRow(int index) {
	int sum = 0;
	for (int i = 0; i < collumns; i++) sum += game_board[index][i];
	return sum;
}
void deleteRow(int index[4], int lines) {
	for (int i = 0; i < lines; i++) {
		for (int j = 0; j < collumns; j++) {
			game_board[index[i]][j] = 0;
		}
	}
	for (int i = 0; i < lines; i++) switchLines(index[i]);
}
void switchLines(int index) {
	while (sumRow(index - 1) != 0) {
		for (int i = 0; i < collumns; i++) {
			game_board[index][i] = game_board[index - 1][i];
			game_board[index - 1][i] = 0;
		}
		index--;
	}
}
void checkLines() {
	int lines = 0;
	int index[4] = { -1, -1, -1, -1 };
	int nevim = 0;
	int blb = 0;
	for (int i = 0; i < rows - 1; i++) {
		int full = 0;
		for (int j = 0; j < collumns; j++) {
			if (game_board[i][j] == 0) full++;
		}
		if (full == 0) {
			lines++;
			index[nevim] = i;
			nevim++;
		}
	}
	if (index[0] != -1) deleteRow(index, lines);
	switch (lines) {
	case 1:
		blb = 40;
		break;
	case 2:
		blb = 100;
		break;
	case 3:
		blb = 300;
		break;
	case 4:
		blb = 1200;
		break;
	default:
		blb = 0;
	}
	line += lines;
	int p = line % 10;
	level = (line - p) / 10;
	score += blb * (level + 1);
}
void checkPos() {
	int col = x + 5;
	int v1 = randBlock[pol];
	if (v1 == 0) {
		brick1(col, y, rot);
	}
	else if (v1 == 1) {
		brick2(col, y, rot);
	}
	else if (v1 == 2) {
		brick3(col, y, rot);
	}
	else if (v1 == 3) {
		brick4(col, y, rot);
	}
	else if (v1 == 4) {
		brick5(col, y, rot);
	}
	else if (v1 == 5) {
		brick6(col, y, rot);
	}
	else if (v1 == 6) {
		brick7(col, y, rot);
	}
}
bool kubovaPicovina(int dy, int dx, int dr) {
	int v1 = randBlock[pol];
	int y_con = y;
	int col = x + 5;
	int fake = rot;
	if (dx != 0) {;
		if (dx > 0) col--;
		else if (dx < 0) col++;
		y_con++;
	}
	else if (dr != 0) {
		fake--;
		y_con++;
	}
	if (v1 == 0) {
		brick1(col, y_con, fake);
	}
	else if (v1 == 1) {
		brick2(col, y_con, fake);
	}
	else if (v1 == 2) {
		brick3(col, y_con, fake);
	}
	else if (v1 == 3) {
		brick4(col, y_con, fake);
	}
	else if (v1 == 4) {
		brick5(col, y_con, fake);
	}
	else if (v1 == 5) {
		brick6(col, y_con, fake);
	}
	else if (v1 == 6) {
		brick7(col, y_con, fake);
	}
	int correct = 0;
	for (int i = 0; i < 4; i++) {
		int x_con = (newPos[i] % collumns) - 1;
		int y_con = (int)(newPos[i] - x_con - 1) / collumns;
		if (game_board[y_con][x_con] != 0) correct--;
		else correct++;
	}
	if (correct == 4) {
		if (dx != 0) {
			if (dx > 0) x--;
			else if (dx < 0) x++;
		}
		else if (dr != 0) {
			rot--;
		}
		return false;
	}
	else return true;
}
void endGame() {
	for (int i = 0; i < 4; i++) {
		int x_con = (lastPos[i] % collumns) - 1;
		int y_con = (int)(lastPos[i] - x_con - 1) / collumns;
		if (y_con == 0) game = false;
	}
}
void Fallbrick(int dy, int dx, int dr) {
	checkPos();
	if (lastPos[0] != 0 && lastPos[1] != 0 && lastPos[2] != 0 && lastPos[3] != 0) deleteMess();
	int correct = 0;
	for (int i = 0; i < 4; i++) {
		int x_con = (newPos[i] % collumns) - 1;
		int y_con = (int)(newPos[i] - x_con - 1) / collumns;
		if (game_board[y_con][x_con] != 0) correct--;
		else correct++;
	}
	if (correct == 4) {
		if (newPos[0] != 0 && newPos[1] != 0 && newPos[2] != 0 && newPos[3] != 0) paintBrick(newPos);
	}
	else {
		if (lastPos[0] != 0 && lastPos[1] != 0 && lastPos[2] != 0 && lastPos[3] != 0) paintBrick(lastPos);
		if (kubovaPicovina(dy, dx, dr) && dy != 0) {
			endGame();
			checkLines();
			resetBrick();
		}
		else goto there;
	}
	copy(begin(newPos), end(newPos), begin(lastPos));
	there:
	correct = 0;
}

void brick1(int x_con, int y_con, int rota) {
	int k = rota % 4;
	if (k == 0 || k == 2) {
		newPos[0] = y_con * collumns + 1 + x_con;
		if (y_con == 1) {
			newPos[1] = (y_con - 1) * collumns + 1 + x_con;
			newPos[2] = (y_con - 1) * collumns + 1 + x_con;
			newPos[3] = (y_con - 1) * collumns + 1 + x_con;
		}
		else if (y_con == 2) {
			newPos[1] = (y_con - 1) * collumns + 1 + x_con;
			newPos[2] = (y_con - 2) * collumns + 1 + x_con;
			newPos[3] = (y_con - 2) * collumns + 1 + x_con;
		}
		else if (y_con >= 3) {
			newPos[1] = (y_con - 1) * collumns + 1 + x_con;
			newPos[2] = (y_con - 2) * collumns + 1 + x_con;
			newPos[3] = (y_con - 3) * collumns + 1 + x_con;
		}
		else {
			newPos[1] = y_con * collumns + 1 + x_con;
			newPos[2] = y_con * collumns + 1 + x_con;
			newPos[3] = y_con * collumns + 1 + x_con;
		}
	}
	else if (k == 1 || k == 3) {
		newPos[0] = y_con * collumns + 1 + x_con;
		newPos[1] = y_con * collumns + x_con;
		newPos[2] = y_con * collumns - 1 + x_con;
		newPos[3] = y_con * collumns - 2 + x_con;
	}
}
void brick2(int x_con, int y_con, int rota) {
	int k = rota % 4;
	if (k == 0) {
		newPos[0] = y_con * collumns + 1 + x_con;
		newPos[1] = y_con * collumns + x_con;
		newPos[2] = y_con * collumns + 2 + x_con;
		if (y_con > 0) {
			newPos[3] = (y_con - 1) * collumns + 1 + x_con;
		}
		else {
			newPos[3] = y_con * collumns + 1 + x_con;
		}
	}
	else if (k == 1) {
		newPos[0] = y_con * collumns + 1 + x_con;
		if (y_con == 1) {
			newPos[1] = (y_con - 1) * collumns + 1 + x_con;
			newPos[2] = (y_con - 1) * collumns  + x_con;
			newPos[3] = (y_con - 1) * collumns + 1 + x_con;
		}
		else if (y_con > 1) {
			newPos[1] = (y_con - 1) * collumns + 1 + x_con;
			newPos[2] = (y_con - 1) * collumns + x_con;
			newPos[3] = (y_con - 2) * collumns + 1 + x_con;
		}
		else {
			newPos[1] = y_con * collumns + 1 + x_con;
			newPos[2] = y_con * collumns + 1 + x_con;
			newPos[3] = y_con * collumns + 1 + x_con;

		}
	}
	else if (k == 2) {
		newPos[0] = y_con * collumns + 1 + x_con;
		if (y_con > 0) {
			newPos[1] = (y_con - 1) * collumns + 1 + x_con;
			newPos[2] = (y_con - 1) * collumns + 2 + x_con;
			newPos[3] = (y_con - 1) * collumns + x_con;
		}
		else {
			newPos[1] = y_con * collumns + 1 + x_con;
			newPos[2] = y_con * collumns + 1 + x_con;
			newPos[3] = y_con * collumns + 1 + x_con;
		}
	}
	else if (k == 3) {
		newPos[0] = y_con * collumns + 1 + x_con;
		if (y_con == 1) {
			newPos[1] = (y_con - 1) * collumns + 1 + x_con;
			newPos[2] = (y_con - 1) * collumns + 2 + x_con;
			newPos[3] = (y_con - 1) * collumns + 1 + x_con;
		}
		else if (y_con > 1) {
			newPos[1] = (y_con - 1) * collumns + 1 + x_con;
			newPos[2] = (y_con - 1) * collumns + 2 + x_con;
			newPos[3] = (y_con - 2) * collumns + 1 + x_con;
		}
		else {
			newPos[1] = y_con * collumns + 1 + x_con;
			newPos[2] = y_con * collumns + 1 + x_con;
			newPos[3] = y_con * collumns + 1 + x_con;
		}
	}
}
void brick3(int x_con, int y_con, int rota) {
	int k = rota % 4;
	if (k == 0 || k == 1 || k == 2 || k == 3) {
		newPos[0] = y_con * collumns + 1 + x_con;
		newPos[1] = y_con * collumns + x_con;
		if (y_con > 0) {
			newPos[2] = (y_con - 1) * collumns + 1 + x_con;
			newPos[3] = (y_con - 1) * collumns + x_con;
		}
		else {
			newPos[2] = y_con * collumns + 1 + x_con;
			newPos[3] = y_con * collumns + 1 + x_con;
		}
	}
}
void brick4(int x_con, int y_con, int rota) {
	int k = rota % 4;
	if (k == 0 || k == 2) {
		newPos[0] = y_con * collumns + 1 + x_con;
		if (y_con == 1) {
			newPos[1] = (y_con - 1) * collumns + 1 + x_con;
			newPos[2] = (y_con - 1) * collumns + 2 + x_con;
			newPos[3] = (y_con - 1) * collumns + 1 + x_con;
		}
		else if (y_con > 1) {
			newPos[1] = (y_con - 1) * collumns + 1 + x_con;
			newPos[2] = (y_con - 1) * collumns + 2 + x_con;
			newPos[3] = (y_con - 2) * collumns + 2 + x_con;
		}
		else {
			newPos[1] = y_con * collumns + 1 + x_con;
			newPos[2] = y_con * collumns + 1 + x_con;
			newPos[3] = y_con * collumns + 1 + x_con;
		}
	}
	else if (k == 1 || k == 3) {
		newPos[0] = y_con * collumns + 1 + x_con;
		newPos[1] = y_con * collumns + 2 + x_con;
		if (y_con > 0) {
			newPos[2] = (y_con - 1) * collumns + 1 + x_con;
			newPos[3] = (y_con - 1) * collumns + x_con;
		}
		else {
			newPos[2] = y_con * collumns + 1 + x_con;
			newPos[3] = y_con * collumns + 2 + x_con;
		}
	}
}
void brick5(int x_con, int y_con, int rota) {
	int k = rota % 4;
	if (k == 0 || k == 2) {
		newPos[0] = y_con * collumns + 1 + x_con;
		if (y_con == 1) {
			newPos[1] = (y_con - 1) * collumns + 1 + x_con;
			newPos[2] = (y_con - 1) * collumns + x_con;
			newPos[3] = (y_con - 1) * collumns + 1 + x_con;
		}
		else if (y_con > 1) {
			newPos[1] = (y_con - 1) * collumns + 1 + x_con;
			newPos[2] = (y_con - 1) * collumns + x_con;
			newPos[3] = (y_con - 2) * collumns + x_con;
		}
		else {
			newPos[1] = y_con * collumns + 1 + x_con;
			newPos[2] = y_con * collumns + 1 + x_con;
			newPos[3] = y_con * collumns + 1 + x_con;
		}
	}
	else if (k == 1 || k == 3) {
		newPos[0] = y_con * collumns + 1 + x_con;
		newPos[1] = y_con * collumns + x_con;
		if (y_con > 0) {
			newPos[2] = (y_con - 1) * collumns + 1 + x_con;
			newPos[3] = (y_con - 1) * collumns + 2 + x_con;
		}
		else {
			newPos[2] = y_con * collumns + 1 + x_con;
			newPos[3] = y_con * collumns + x_con;
		}
	}
}
void brick6(int x_con, int y_con, int rota) {
	int k = rota % 4;
	if (k == 0) {
		newPos[0] = y_con * collumns + 1 + x_con;
		newPos[1] = y_con * collumns + 2 + x_con;
		if (y_con == 1) {
			newPos[2] = (y_con - 1) * collumns + 1 + x_con;
			newPos[3] = (y_con - 1) * collumns + 1 + x_con;
		}
		else if (y_con > 1) {
			newPos[2] = (y_con - 1) * collumns + 1 + x_con;
			newPos[3] = (y_con - 2) * collumns + 1 + x_con;
		}
		else {
			newPos[2] = y_con * collumns + 1 + x_con;
			newPos[3] = y_con * collumns + 1 + x_con;
		}
	}
	else if (k == 1) {
		newPos[0] = y_con * collumns + 1 + x_con;
		newPos[1] = y_con * collumns + x_con;
		newPos[2] = y_con * collumns - 1 + x_con;
		if (y_con > 0) {
			newPos[3] = (y_con - 1) * collumns + 1 + x_con;
		}
		else {
			newPos[3] = y_con * collumns + 1 + x_con;
		}
	}
	else if (k == 2) {
		newPos[0] = y_con * collumns + 1 + x_con;
		if (y_con == 1) {
			newPos[1] = (y_con - 1) * collumns + 1 + x_con;
			newPos[2] = (y_con - 1) * collumns + 1 + x_con;
			newPos[3] = (y_con - 1) * collumns + 1 + x_con;
		}
		else if (y_con > 1) {
			newPos[1] = (y_con - 1) * collumns + 1 + x_con;
			newPos[2] = (y_con - 2) * collumns + 1 + x_con;
			newPos[3] = (y_con - 2) * collumns + x_con;
		}
		else {
			newPos[1] = y_con * collumns + 1 + x_con;
			newPos[2] = y_con * collumns + 1 + x_con;
			newPos[3] = y_con * collumns + 1 + x_con;
		}
	}
	else if (k == 3) {
		newPos[0] = y_con * collumns + 1 + x_con;
		if (y_con > 0) {
			newPos[1] = (y_con - 1) * collumns + 1 + x_con;
			newPos[2] = (y_con - 1) * collumns + 2 + x_con;
			newPos[3] = (y_con - 1) * collumns + 3 + x_con;
		}
		else {
			newPos[1] = y_con * collumns + 1 + x_con;
			newPos[2] = y_con * collumns + 1 + x_con;
			newPos[3] = y_con * collumns + 1 + x_con;
		}
	}
}
void brick7(int x_con, int y_con, int rota) {
	int k = rota % 4;
	if (k == 0) {
		newPos[0] = y_con * collumns + 1 + x_con;
		newPos[1] = y_con * collumns + x_con;
		if (y_con == 1) {
			newPos[2] = (y_con - 1) * collumns + 1 + x_con;
			newPos[3] = (y_con - 1) * collumns + 1 + x_con;
		}
		else if (y_con > 1) {
			newPos[2] = (y_con - 1) * collumns + 1 + x_con;
			newPos[3] = (y_con - 2) * collumns + 1 + x_con;
		}
		else {
			newPos[2] = y_con * collumns + 1 + x_con;
			newPos[3] = y_con * collumns + 1 + x_con;
		}
	}
	else if (k == 1) {
		newPos[0] = y_con * collumns + 1 + x_con;
		if (y_con > 0) {
			newPos[1] = (y_con - 1) * collumns + 1 + x_con;
			newPos[2] = (y_con - 1) * collumns + x_con;
			newPos[3] = (y_con - 1) * collumns - 1 + x_con;
		}
		else {
			newPos[1] = y_con * collumns + 1 + x_con;
			newPos[2] = y_con * collumns + 1 + x_con;
			newPos[3] = y_con * collumns + 1 + x_con;
		}
	}
	else if (k == 2) {
		newPos[0] = y_con * collumns + 1 + x_con;
		if (y_con == 1) {
			newPos[1] = (y_con - 1) * collumns + 1 + x_con;
			newPos[2] = (y_con - 1) * collumns + 1 + x_con;
			newPos[3] = (y_con - 1) * collumns + 1 + x_con;
		}
		else if (y_con > 1) {
			newPos[1] = (y_con - 1) * collumns + 1 + x_con;
			newPos[2] = (y_con - 2) * collumns + 1 + x_con;
			newPos[3] = (y_con - 2) * collumns + 2 + x_con;
		}
		else {
			newPos[1] = y_con * collumns + 1 + x_con;
			newPos[2] = y_con * collumns + 1 + x_con;
			newPos[3] = y_con * collumns + 1 + x_con;
		}
	}
	else if (k == 3) {
		newPos[0] = y_con * collumns + 1 + x_con;
		newPos[1] = y_con * collumns + 2 + x_con;
		newPos[2] = y_con * collumns + 3 + x_con;
		if (y_con > 0) {
			newPos[3] = (y_con - 1) * collumns + 1 + x_con;
		}
		else {
			newPos[3] = y_con * collumns + 1 + x_con;
		}
	}
}
void resetBrick() {
	x = 0;
	y = 0;
	rot = 0;
	pol++;
	score += 50;
	for (int i = 0; i < 4; i++) {
		lastPos[i] = 0;
		newPos[i] = 0;
	}
}
int borders(int x) {
	int k = rot % 4;
	switch (randBlock[pol])
	{
	case 0:
		switch (k)
		{
		case 0:
			if (x < - 5) return - 5;
			else if (x > 4) return 4;
			else return x;
			break;
		case 1:
			if (x < - 2) return - 2;
			else if (x > 4) return 4;
			else return x;
			break;
		case 2:
			if (x < - 5) return - 5;
			else if (x > 4) return 4;
			else return x;
			break;
		default:
			if (x < - 2) return - 2;
			else if (x > 4) return 4;
			else return x;
			break;
		}
		break;
	case 1:
		switch (k)
		{
		case 0:
			if (x < - 4) return - 4;
			else if (x > 3) return 3;
			else return x;
			break;
		case 1:
			if (x < - 4) return - 4;
			else if (x > 4) return 4;
			else return x;
			break;
		case 2:
			if (x < -4) return -4;
			else if (x > 3) return 3;
			else return x;
			break;
		default:
			if (x < -5) return -5;
			else if (x > 3) return 3;
			else return x;
			break;
		}
		break;
	case 2:
		if (x < -4) return -4;
		else if (x > 4) return 4;
		else return x;
	case 3:
		switch (k)
		{
		case 0:
			if (x < -5) return -5;
			else if (x > 3) return 3;
			else return x;
			break;
		case 1:
			if (x < -4) return -4;
			else if (x > 3) return 3;
			else return x;
			break;
		case 2:
			if (x < -5) return -5;
			else if (x > 3) return 3;
			else return x;
			break;
		default:
			if (x < -4) return -4;
			else if (x > 3) return 3;
			else return x;
			break;
		}
		break;
	case 4:
		switch (k)
		{
		case 0:
			if (x < -4) return -4;
			else if (x > 4) return 4;
			else return x;
			break;
		case 1:
			if (x < -4) return -4;
			else if (x > 3) return 3;
			else return x;
			break;
		case 2:
			if (x < -4) return -4;
			else if (x > 4) return 4;
			else return x;
			break;
		default:
			if (x < -4) return -4;
			else if (x > 3) return 3;
			else return x;
			break;
		}
		break;
	case 5:
		switch (k)
		{
		case 0:
			if (x < -5) return -5;
			else if (x > 3) return 3;
			else return x;
			break;
		case 1:if (x < -3) return -3;
			  else if (x > 4) return 4;
			  else return x;
			break;
		case 2:
			if (x < -4) return -4;
			else if (x > 4) return 4;
			else return x;
			break;
		default:
			if (x < -5) return -5;
			else if (x > 2) return 2;
			else return x;
			break;
		}
		break;
	default:
		switch (k)
		{
		case 0:
			if (x < -4) return -4;
			else if (x > 4) return 4;
			else return x;
			break;
		case 1:
			if (x < -3) return -3;
			else if (x > 4) return 4;
			else return x;
			break;
		case 2:
			if (x < -5) return -5;
			else if (x > 3) return 3;
			else return x;
			break;
		default:
			if (x < -5) return -5;
			else if (x > 2) return 2;
			else return x;
			break;
		}
		break;
	}
}

// Globální proměnné:
HINSTANCE hInst;                                // aktuální instance
WCHAR szTitle[MAX_LOADSTRING];                  // Text záhlaví
WCHAR szWindowClass[MAX_LOADSTRING];			// název třídy hlavního okna

// Předat dál deklarace funkcí zahrnuté v tomto modulu kódu:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: Sem umístěte kód.

	// Inicializovat globální řetězce
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_TETRIS, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Provést inicializaci aplikace:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_TETRIS));

	MSG msg;

	// Hlavní smyčka zpráv:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	
	return (int)msg.wParam;
}
//  FUNKCE: MyRegisterClass()
//  ÚČEL: Zaregistruje třídu okna.
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_TETRIS));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_TETRIS);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	RECT desktop;
	const HWND hDesktop = GetDesktopWindow();
	GetWindowRect(hDesktop, &desktop);
	int screanResulutionx = desktop.right;
	int screanResulutiony = desktop.bottom;
	hInst = hInstance;
	int winWidth = 585;
	int winHeight = 850;
	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		(screanResulutionx - winWidth) / 2, (screanResulutiony - winHeight) / 2, winWidth, winHeight, nullptr, nullptr, hInstance, nullptr);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}
//  FUNKCE: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ÚČEL: Zpracuje zprávy pro hlavní okno.
//
//  WM_COMMAND  - zpracování aplikační nabídky
//  WM_PAINT    - Vykreslení hlavního okna
//  WM_DESTROY  - vystavení zprávy o ukončení a návrat
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hdc = GetDC(hWnd);
	PAINTSTRUCT ps;
	TCHAR greeting[] = _T("Skore: " );
	_In_ UINT time;
	switch (message)
	{
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// Analyzovat vybrané možnosti nabídky:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;
	case WM_PAINT:
	{
		hdc = BeginPaint(hWnd, &ps);
		DrawBoard(hdc);
		if (game) {
			WCHAR X[100];
			wsprintf(X, L"Score: %d", score);
			TextOut(hdc, 10, 10, X, _tcslen(X));

			WCHAR Y[100];
			wsprintf(Y, L"Lines: %d", line);
			TextOut(hdc, 10, 250, Y, _tcslen(Y));

			WCHAR Z[100];
			wsprintf(Z, L"Level: %d", level);
			TextOut(hdc, 10, 290, Z, _tcslen(Z));
		}
		else {
			WCHAR X[100];
			wsprintf(X, L"Score: %d", score);
			TextOut(hdc, 10, 10, X, _tcslen(X));

			WCHAR Y[100];
			wsprintf(Y, L"Lines: %d", line);
			TextOut(hdc, 10, 250, Y, _tcslen(Y));

			WCHAR Z[100];
			wsprintf(Z, L"Level: %d", level);
			TextOut(hdc, 10, 290, Z, _tcslen(Z));

			WCHAR K[100];
			wsprintf(K, L"You lose :D");
			TextOut(hdc, 335, 350, K, _tcslen(K));
		}

		EndPaint(hWnd, &ps);
	}
	break;
	case WM_KEYDOWN:
		dy = 0;
		dx = 0;
		dr = 0;
		switch (wParam) {
		case VK_LEFT: --dx; break;
		case VK_RIGHT: ++dx; break;
		case VK_DOWN: ++dy; break;
		case VK_UP: ++dr; break;
		}
		if (dx | dy | dr) {
			x = borders(x + dx);
			y = y + dy;
			rot = rot + dr;
			InvalidateRect(hWnd, NULL, TRUE);
		}
		if (game) {
			if (dy) score += 20;
			Fallbrick(dy, dx, dr);
		}
		break;
		
	case WM_TIMER:
	{
		dy = 1;
		y = y + dy;
		InvalidateRect(hWnd, NULL, TRUE);
		if (game) Fallbrick(dy, dx, dr);
		break;
	}
	break;
	case WM_CREATE:
		time = 500 - level * 15;
		SetTimer(hWnd, 1000, time, NULL);
		Startgame();
		x = 0;
		y = 0;
		rot = 0;
		score = 0;
		game = true;
		level = 0;
		line = 0;
		pol = 0;
		dx = 0;
		dy = 0;
		dr = 0;
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Obslužná rutina zprávy pro pole "O produktu"
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
