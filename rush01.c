#include "rush01.h"
#include <stdlib.h>

int	count_visible(int *line)
{
	int	max;
	int	count;
	int	i;

	i = 0;
	max = 0;
	count = 0;
	while (i < g_size)
	{
		if (line[i] > max)
		{
			max = line[i];
			count++;
		}
		i++;
	}
	return (count);
}

int	no_duplicate(int **grid, int row, int col, int val)
{
	int	i;

	i = 0;
	while (i < g_size)
	{
		if (grid[row][i] == val || grid[i][col] == val)
			return (0);
		i++;
	}
	return (1);
}

int	check_line(int **grid, int index, int *constraint, int is_col)
{
	int	i;
	int	*line;

	line = malloc(sizeof(int) * g_size);
	if (!line)
		return (0);
	i = 0;
	while (i < g_size)
	{
		if (is_col)
			line[i] = grid[i][index];
		else
			line[i] = grid[index][i];
		i++;
	}
	if (count_visible(line) != (is_col ? constraint[index] : constraint[g_size * 2 + index]))
		return (free(line), 0);
	ft_rev_int_tab(line, g_size);
	if (count_visible(line) != (is_col ? constraint[g_size + index] : constraint[g_size * 3 + index]))
		return (free(line), 0);
	return (free(line), 1);
}

void print_grid(int **grid)
{
	int	i;
	int	j;

	i = 0;
	while (i < g_size)
	{
		j = 0;
		while (j < g_size)
		{
			ft_putchar(grid[i][j] + '0');
			if (j < g_size - 1)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int	rush01(int **grid, int row, int col, int *constraint)
{
	int	val;

	if (row == g_size)
		return (print_grid(grid), 1);
	if (col == g_size)
		return (check_line(grid, row, constraint, 0) && rush01(grid, row + 1, 0, constraint));
	val = 1;
	while (val <= g_size)
	{
		if (no_duplicate(grid, row, col, val))
		{
			grid[row][col] = val;
			if (row == g_size - 1 && !check_line(grid, col, constraint, 1))
				grid[row][col] = 0;
			else if (rush01(grid, row, col + 1, constraint))
				return (1);
			grid[row][col] = 0;
		}
		val++;
	}
	return (0);
}