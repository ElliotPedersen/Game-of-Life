#include "game_of_life.h"

void init_field(const int rows, const int cols,
                cell field[rows][cols])
{
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            field[r][c].current = DEAD;
        }
    }
}

void draw_field(const int rows, const int cols,
                cell field[rows][cols])
{
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            printf("%c ", field[r][c].current);
        }

        printf("\n");
    }

    printf("Select one of the following options: \n\t(enter) Step\n");
    printf("\t(any)\tSave and exit\n");
}

void next_gen(const int rows, const int cols,
              cell field[rows][cols])
{
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {

            int neighbour_amnt = 0;

            for (int i = r - 1; i <= r + 1; i++)
            {
                for (int j = c - 1; j <= c + 1; j++)
                {
                    if ((i != r || j != c) &&
                        (i > -1 && i < rows && j > -1 && j < cols))
                    {
                        if (field[i][j].current == ALIVE)
                        {
                            neighbour_amnt++;
                        }
                    }

                    field[r][c].next = DEAD;
                }
            }

            if (field[r][c].current == ALIVE &&
                (neighbour_amnt == 2 || neighbour_amnt == 3))
            {
                field[r][c].next = ALIVE;
            }

            else if (field[r][c].current == DEAD &&
                     (neighbour_amnt == 3))
            {
                field[r][c].next = ALIVE;
            }
        }
    }
}

void update_field(const int rows, const int cols,
                  cell field[rows][cols])
{
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            field[r][c].current = field[r][c].next;
        }
    }
}