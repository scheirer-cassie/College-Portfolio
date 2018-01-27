/**
 * fifteen.c
 *
 * CS50 AP
 * Fifteen
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 *
 * Extra features including printing an actual grid to make it look more
 * tile-like, and using ANSI color sequences for some additional customizing
 */

#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// ansi escape sequence to print grid color
// replace the number beteen [ and m with 31 for red, 32 for green, 33 for brown,
// 34 for blue, 35 for purple, 36 for cyan, 37 for gray
#define COLOR "\033[32m"

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// saved locations of the blank tile
int blank_row;
int blank_col;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);
void swap(int *a, int *b);
void print_grid_row(int d);
void print_tile(int tile);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
               DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = get_int();

        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(50000);
    }

    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN!\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).
 */
void init(void)
{
    // initialize count to 0
    int count = 0;

    // iterate through the rows and columns
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            // assign a number to each array space from d*d to 1
            board[i][j] = ((d * d) - 1) - count;
            count++;
        }
    }
    // switch the places of 2 and 1 if there is an even number of tiles
    if ((d * d) % 2 == 0)
    {
        board[d - 1][d - 2] = 2;
        board[d - 1][d - 3] = 1;
    }
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    // iterate through the rows and columns
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            // if value of tile is zero, print underscore instead
            if (board[i][j] == 0)
            {
                printf("_   ");
            }
            // if value of tile is greater than or equal to ten, print tile number and two spaces
            else if (board[i][j] >= 10)
            {
                printf("%d  ", board[i][j]);
            }
            // for any other tile value, print tile number and three spaces
            else
            {
                printf("%d   ", board[i][j]);
            }
        }
        // print new lines
        printf("\n\n");
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false.
 */
bool move(int tile)
{
    // iterate through the rows and columns
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            // if one tile is zero
            if (board[i][j] == 0)
            {
                // if input = the tile one up
                if (tile == board[i + 1][j])
                {
                    // switch the tile and the zero
                    board[i][j] = tile;
                    board[i + 1][j] = 0;
                    return true;
                }
                // if input = the tile one down
                else if (tile == board[i - 1][j])
                {
                    // switch the tile and the zero
                    board[i][j] = tile;
                    board[i - 1][j] = 0;
                    return true;
                }
                // if input = the tile one right
                else if (tile == board[i][j + 1])
                {
                    // switch the tile and the zero
                    board [i][j] = tile;
                    board[i][j + 1] = 0;
                    return true;
                }
                // if input = the tile one left
                else if (tile == board[i][j - 1])
                {
                    // switch the tile and the zero
                    board[i][j] = tile;
                    board[i][j - 1] = 0;
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
    }
    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration),
 * else false.
 */
bool won(void)
{
    // initialize count to 1
    int count = 1;

    // iterate through the rows and columns
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            // if not yet arrived at the last tile, continue looping
            if (i == (d - 1) && j == (d - 1))
            {
                continue;
            }
            // if the tile = the count, fail
            if (board[i][j] != count++)
            {
                return false;
            }
        }
    }
    return true;
}
