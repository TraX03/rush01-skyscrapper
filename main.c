#include <stdlib.h>
#include "rush01.h"

int g_size;

int *parse_input(char *str, int total)
{
    int *arr;
    int i = 0;

    arr = malloc(total * sizeof(int));
    if (!arr)
        return (NULL);
    while (*str && i < total)
    {
        if (*str >= '1' && *str <= ('0' + g_size))
        {
            if (*(str + 1) >= '0' && *(str + 1) <= '9')
                return (free(arr), NULL);
            arr[i++] = *str - '0';
        }
        else if (*str != ' ')
            return (free(arr), NULL);
        str++;
    }
    if (i != total)
        return (free(arr), NULL);
    return (arr);
}

int **malloc_grid(void)
{
    int **grid;
    int i;

    grid = malloc(g_size * sizeof(int *));
    if (!grid)
        return (NULL);
	i = 0;
    while (i < g_size)
    {
        grid[i] = malloc(g_size * sizeof(int));
        if (!grid[i])
        {
            while (--i >= 0)
                free(grid[i]);
            free(grid);
            return (NULL);
        }
		i++;
    }
    return (grid);
}

void free_grid(int **grid)
{
    int i;

    if (!grid)
        return;
	i = 0;
    while (i < g_size)
	{
        free(grid[i]);
		i++;
	}
    free(grid);
}

int main(int argc, char **argv)
{
    int **grid;
    int *constraint;

    if (argc == 3)
    {
        if (*argv[1] < '2' || *argv[1] > '9')
            return (ft_putstr("Error: Invalid grid size (must be 2–9)\n"), 1);
        g_size = *argv[1] - '0';
        constraint = parse_input(argv[2], g_size * 4);
        if (!constraint)
            return (ft_putstr("Error: Invalid input format\n"), 1);
        grid = malloc_grid();
        if (!grid)
        {
            ft_putstr("Error: Memory allocation failed\n");
            return (free(constraint), 1);
        }
        if (!rush01(grid, 0, 0, constraint))
            ft_putstr("Error: No solution found\n");
        free(constraint);
        free_grid(grid);
        return (0);
    }
    ft_putstr("Usage: ./rush01 [grid size 2–9] [constraints]\n");
    return (1);
}