/*
 * Programmering i C
 * Fall 20
 * Mastery test 9

 * File:         mp9.c
 * Description:  A simple implementation of Conway's Game of Life.
 * Author:       Elliot Pedersen
 * CS username:  dv20epn
 * Date:         2020-10-26
 * Input:        Choice of initial configuration and then instruction
                 to step or exit.
 * Output:       Prints the game field in each step.
 * Limitations:  No validation of input.
 */

#include "game_of_life.h"
#include "game_of_life_file_handler.h"

/* Description: Checks the parameters to the program. Checks if the
* call to the program has the right number of
* parameters. Open the input and output files.
* Input: The parameters to the program and two pointers to file
* pointers.
* Output: Returns 0 when the files are correctly opened.
* Returns a non-zero value on failure.
*/

int check_prog_params(int argc, const char *argv[],
                      FILE **in_file_p,
                      FILE **out_file_p);

/* Description: Start and run games, interact with the user.
 * Input:       About what initial structure and whether to step or
 *              exit.
 * Output:      Prints information to the user, and the game field in
 *              each step.
 */

int main(int argc, const char *argv[])
{
    char user_input;

    FILE *in_file_p;
    FILE *out_file_p;

    if (check_prog_params(argc, argv, &in_file_p, &out_file_p) == 0)
    {
        if (load_config_from_file(ROWSIZE, COLSIZE,
                                  world, in_file_p) == 0)
        {
            init_field(ROWSIZE, COLSIZE, world);

            do
            {
                draw_field(ROWSIZE, COLSIZE, world);

                user_input = getchar();

                if (user_input != '\n')
                {
                    save_config_to_file(ROWSIZE, COLSIZE,
                                        world, out_file_p);
                }

                next_gen(ROWSIZE, COLSIZE, world);

                update_field(ROWSIZE, COLSIZE, world);

            } while (user_input == '\n');
        }
    }

    return 0;
}

int check_prog_params(int argc, const char *argv[],
                      FILE **in_file_p,
                      FILE **out_file_p)
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <input configuration file> ", argv[0]);
        fprintf(stderr, "<output configuration file>");

        return EXIT_FAILURE;
    }

    *in_file_p = fopen(argv[1], "r");

    if (*in_file_p == NULL)
    {
        fprintf(stderr, "Could not open the file: %s", argv[1]);

        fclose(*in_file_p);

        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], argv[2]) == 0)
    {
        fprintf(stderr, "Incorrect configuration file format");

        fclose(*in_file_p);

        return EXIT_FAILURE;
    }

    int len = strlen(argv[2]);
    if ((len >= 4) && strcmp(&(argv[2][len - 4]), ".gol") != 0)
    {
        fprintf(stderr, "Could not open the file: %s", argv[2]);

        fclose(*in_file_p);

        return EXIT_FAILURE;
    }

    *out_file_p = fopen(argv[2], "w");

    return EXIT_SUCCESS;
}