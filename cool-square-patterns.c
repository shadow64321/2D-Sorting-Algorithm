#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

// Global Variables
char GRID[10][10];
const int GRID_SIZE = sizeof(GRID)/sizeof(GRID[0]);

// Function Declaration
void resetGrid();
int gridFull();
void drawGrid();
void initialiser(); // Uses rand to generate random number and throw them throughout the array

int main() {
  do {
    resetGrid();
    initialiser();
    drawGrid();

  } while(gridFull() != 0);

  return 0;
}

// Function Implementation
void resetGrid() {
  for (int row = 0; row < GRID_SIZE; row++) {
    for (int column = 0; column < GRID_SIZE; column++) {
      GRID[row][column] = ' ';
    }
  }
}

int gridFull() {
  int freeSpaces = sizeof(GRID);
  for (int row = 0; row < GRID_SIZE; row++) {
    for (int column = 0; column < GRID_SIZE; column++) {
      if (GRID[row][column] != ' ') {
        freeSpaces--;
      }
    }
  } 
  return freeSpaces;
}

void drawGrid() {
  for (int row = 0; row < GRID_SIZE; row++) {
    for (int column = 0; column < GRID_SIZE; column++) {
      printf("%d", GRID[row][column]);
    }
    printf("\n");
  } 
}

void initialiser() {
  srand(time(0));
  for (int i = 0; i < 20; i++) {
    int x = rand() % GRID_SIZE;
    int y = rand() % GRID_SIZE;

    for (int row = x; row < GRID_SIZE; row++) {
      for (int column = x; column < GRID_SIZE; column++) {
        GRID[row][column] = y;
      }
    } 
  }
}
