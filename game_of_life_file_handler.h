#ifndef GOLFH_H
#define GOLFH_H

#include "game_of_life.h"

int r, c, value, i = -1, j = -1;
char comma, read, a;

/* Description: Load a configuration to the field array from a file.
* Input: The field array, its size and a file pointer to the
* file with the initial configuration.
* Output: Returns 0 on success, the field array is updated with
* the configuration from the file.
* Returns a non-zero value on failure.
* The file pointed to by fp is closed.
*/

int load_config_from_file(const int rows, const int cols,
                          cell field[rows][cols], FILE *fp);

/* Description: Saves the current configuration of the field array to
* a specified file.
* Input: The field array, its size and a file pointer to the
* file where the final configuration should be saved.
* Output: Returns 0 on success, the current configuration in the
* field array is written to the file.
* Returns a non-zero value on failure.
* The file pointed to by fp is closed.
*/

int save_config_to_file(const int rows, const int cols,
                        const cell field[rows][cols], FILE *fp);

#endif