#ifndef SOURCE_H
#define SOURCE_H

#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

void Chessplace(char pole[][9]);
void move_all(char pole[][9], int* team);
int move_check(int team, int x1, int x2, int y1, int y2, char pole[][9]);
int friendly(int side, int x2, int y2, char pole[][9]);

#endif
