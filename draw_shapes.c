#include <stdio.h>
#include "draw.h"

/* Prints a size x size square whose left col is at startCol */
void print_square(int leftCol, int size)
{
  int i, j;
  int endCol = leftCol + size;
  for (int row = 0; row < size; row++){
    int col;
    for (col = 0; col < leftCol; col++) putchar(' ');
    for (       ; col < endCol;  col++) putchar('*');
    putchar('\n');
  }
}

// Prints a triangle of specified height whose left edge is at col leftCol.
void print_triangle(int leftCol, int size)
{
  for (int row = 0; row <= size; row++) {
    int minCol = leftCol + size - row, maxCol = leftCol + size + row;
    int col;
    for (col = 0; col < minCol; col++) putchar(' ');
    for (       ; col <= maxCol; col++) putchar('*');
    putchar('\n');
  }
}

/* Prints an arrow based on the bitmap provided. */
void print_arrow()
{
  for (char row = 0; row < 5; row++){ 
    unsigned short rowBits = arrow_bitmap[0][row];
    for (char col = 0; col < 7; col++){
      unsigned short colMask = 1 << (6-col); /* mask to select bit associated with bit */
      putchar( (rowBits & colMask) ? '*' : ' ');
    }
    putchar('\n');
  }
}
  
