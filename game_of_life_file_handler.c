#include "game_of_life_file_handler.h"

int load_config_from_file(const int rows, const int cols,
                          cell field[rows][cols], FILE *fp)
{
    value = fscanf(fp, "%2d%c%2d", &r, &comma, &c);

    if (value == 0)
    {
        fprintf(stderr, "Incorrect configuration file format");

        fclose(fp);

        return EXIT_FAILURE;
    }

    if (r > ROWSIZE || c > COLSIZE)
    {
        fprintf(stderr, "The configuration is too big for the field");
        fprintf(stderr, "\nThe field needs to be at least ");
        fprintf(stderr, "%d rows and %d columns", r, c);

        fclose(fp);

        return EXIT_FAILURE;
    }

    while (feof(fp) == 0)
    {
        read = fgetc(fp);

        i++;

        if (read == '*')
        {
            field[j][i].current = ALIVE;
        }

        else if (read == '\n')
        {
            j++;
            i = -1;
        }
    }

    fclose(fp);

    return EXIT_SUCCESS;
}

int save_config_to_file(const int rows, const int cols,
                        const cell field[rows][cols], FILE *fp)
{
    fprintf(fp, "%d,%d\n", r, c);

    for (r = 0; r < rows; r++)
    {
        for (c = 0; c < cols; c++)
        {
            a = field[r][c].current;

            if (a == '.')
            {
                a = '0';
            }

            else if (a == 'X')
            {
                a = '*';
            }

            fputc(a, fp);

            if (c == cols - 1)
            {
                fputc('\n', fp);
            }
        }
    }

    fclose(fp);

    return EXIT_SUCCESS;
}