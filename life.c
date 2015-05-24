#include "life.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int** newGrid(int size)
{	
	//int* values = calloc(size*size, sizeof(int)); 
	int** rows = malloc(size*sizeof(int*)); //inicializa un apartado de memoria para apuntadores a int

	int i;
	int j;
	srand(time(NULL));
	for (i = 0; i < size; i++) {
		int* values = calloc(size*size, sizeof(int));
		for (j = 0; j < size; j++) {
			int r = rand() % 2;
			values[j] = r;
		}
		rows[i] = values;
	}
	return rows;
}

void updateGrid(int** grid, int size)
{
	int i;
	int j;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			if (grid[i][j] == 0)
				grid[i][j] = 1;
				//checkDead(grid, size, i, j);
			else
				grid[i][j] = 0;
				//checkLive(grid, size, i, j);
		}
	}
}

void checkDead(int** grid, int size, int i, int j)
{
	int x; 
	int y; 
	int count;
	count = 0;
	//Checo casilla superior izq
	x = i-1;
	y = j-1;
	if (inRange(size, x) && inRange(size, y))
		if (grid[x][y] == 1)
			count++;

	//Checo casilla superior
	x = i-1;
	if (inRange(size, x))
		if (grid[x][j] == 1)
			count++;

	//Checo casilla superior der
	x = i-1;
	y = j+1;
	if (inRange(size, x) && inRange(size, y))
		if (grid[x][y] == 1)
			count++;

	//Checo casilla der. 
	y = j+1;
	if (inRange(size, y))
		if (grid[i][y] == 1)
			count++;

	//Checo casilla inferior der. 
	x = i+1;
	y = j+1;
	if (inRange(size, x) && inRange(size, y))
		if (grid[x][y] == 1)
			count++;

	//Checo casilla inferior
	x = i+1;
	if (inRange(size, x))
		if (grid[x][j] == 1)
			count++;

	//Checo casilla inferior izq. 
	x = i+1;
	y = j-1;
	if (inRange(size, x) && inRange(size, y))
		if (grid[x][y] == 1)
			count++;

	//Checo casilla izq
	y = j-1;
	if (inRange(size, y))
		if (grid[i][y] == 1)
			count++;

	//Checo cuantos vecinos vivios tenia
	if (count == 3) {
		grid[i][j] = 1; //VIVE!!!
	}
}

/*Revisa una casilla viva*/
void checkLive(int** grid, int size, int i, int j) 
{
	int x; 
	int y; 
	int count;
	count = 0;
	//Checo casilla superior izq
	x = i-1;
	y = j-1;
	if (inRange(size, x) && inRange(size, y))
		if (grid[x][y] == 1)
			count++;

	//Checo casilla superior
	x = i-1;
	if (inRange(size, x))
		if (grid[x][j] == 1)
			count++;

	//Checo casilla superior der
	x = i-1;
	y = j+1;
	if (inRange(size, x) && inRange(size, y))
		if (grid[x][y] == 1)
			count++;

	//Checo casilla der. 
	y = j+1;
	if (inRange(size, y))
		if (grid[i][y] == 1)
			count++;

	//Checo casilla inferior der. 
	x = i+1;
	y = j+1;
	if (inRange(size, x) && inRange(size, y))
		if (grid[x][y] == 1)
			count++;

	//Checo casilla inferior
	x = i+1;
	if (inRange(size, x))
		if (grid[x][j] == 1)
			count++;

	//Checo casilla inferior izq. 
	x = i+1;
	y = j-1;
	if (inRange(size, x) && inRange(size, y))
		if (grid[x][y] == 1)
			count++;

	//Checo casilla izq
	y = j-1;
	if (inRange(size, y))
		if (grid[i][y] == 1)
			count++;

	//Checo cuantos vecinos vivios tenia
	if (count > 3) {
		grid[i][j] = 0; //Muere!!!!
	} else if (count == 0) {
		grid[i][j] = 0; //Soledad!!
	}
}
wchar_t* getGrid(int** grid, int size) {
	int i;
	int j;
	wchar_t* res = calloc(size*size+size+1, sizeof(wchar_t));
	int count;
	count = 0;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			if (grid[i][j] == 0) {
				res[count] = (wchar_t)L" □";
				count++;
			}
			else {
				res[count] = (wchar_t)L" ■";
				count++;
			}
		}
		res[count] = (wchar_t)"\n";
		count++;
	}
	res[size*size+size+1] = '\0';
	return res;
}

/*Imprime un arragelo 2d según sea 1 o 0 sus indices*/
void printGrid(int** grid, int size) {
	int i;
	int j;
	printf("\r");
	int count = 0; 
	wchar_t mundo[size*size+size+1];
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			if (grid[i][j] == 0) {
				mundo[count] = (wchar_t)" □";
				count++;
			}
			else {
				mundo[count] = (wchar_t)" ■";
				count++;
			}
		}
		mundo[count] = (wchar_t)"\n";
		count++;
	}
	//mundo[size*size+size+1] = (wchar_t)"\0";
	printf("%S", mundo[0]);
}

int inRange(int size, int n) {
	return n >= 0 && n < size;
}

int main(int argc, char const *argv[])
{	
	int size = 6;
	int** arr = newGrid(size);
	printGrid(arr, size);
	//wchar_t* w = getGrid(arr, size);
	/*while(1) {
		printGrid(arr, size);
		updateGrid(arr, size);
	}*/
	int i;
	for (i = 0; i < size; i++)
	{
    	int* currentIntPtr = arr[i];
    	free(currentIntPtr);
	}
	return 0;
}
