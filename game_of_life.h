#ifndef GOL_H
#define GOL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Constants, representation of states */
#define ALIVE 'X'
#define DEAD '.'

/* Constants that controls the fieldsize */
#define ROWSIZE 20 // Controls the row size
#define COLSIZE 20 // Controls the column size

/* Declaration of data structure */
typedef struct cell
{
    char current;
    char next;
} cell;

cell world[ROWSIZE][COLSIZE];

/* Declaration of functions */

/* Description: Initialize all the cells to dead, then asks the user
 *              about which structure to load, and finally load the
 *              structure.
 * Input:       The field array and its size.
 * Output:      The field array is updated.
 */

void init_field(const int rows, const int cols,
                cell field[rows][cols]);

/* Description: Draws the field of the game.
 * Input:       The field array and its size.
 * Output:      The field.
 */

void draw_field(const int rows, const int cols,
                cell field[rows][cols]);

/* Description: Counts ammount of neighbours
 *              and calculates what the next 
 *              generation will look like.
 * Input:       The field array and its size.
 * Output:      The next generation.
 */

void next_gen(const int rows, const int cols,
              cell field[rows][cols]);

/* Description: Updates the field.
 * Input:       The field array and its size.
 * Output:      Updated field.
 */

void update_field(const int rows, const int cols,
                  cell field[rows][cols]);

#endif