#include "rush01.h"

int	count_visible(int *line)
{
	int	max;
	int	count;
	int	i;

	i = 0;
	max = 0;
	count = 0;
	while (i < 4)
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

int	no_duplicate(int grid[4][4], int row, int col, int val)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[row][i] == val || grid[i][col] == val)
			return (0);
		i++;
	}
	return (1);
}

int	check_line(int grid[4][4], int index, int *constraint, int is_col)
{
	int	i;
	int	line[4];

	for (i = 0; i < 4; i++)
		line[i] = is_col ? grid[i][index] : grid[index][i];

	if (count_visible(line) != (is_col ? constraint[index] : constraint[8 + index]))
		return 0;

	ft_rev_int_tab(line, 4);
	if (count_visible(line) != (is_col ? constraint[4 + index] : constraint[12 + index]))
		return 0;

	return 1;
}

void	print_grid(int grid[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_putchar(grid[i][j] + '0');
			if (j < 3)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int	rush01(int grid[4][4], int row, int col, int *constraint)
{
	int	val;

	if (row == 4)
	{
		print_grid(grid);
		return (1);
	}
	if (col == 4)
		return (check_line(grid, row, constraint, 0) && rush01(grid, row + 1, 0, constraint));
	val = 1;
	while (val <= 4)
	{
		if (no_duplicate(grid, row, col, val))
		{
			grid[row][col] = val;

			if (row == 3 && !check_line(grid, col, constraint, 1))
				grid[row][col] = 0;
			else if (rush01(grid, row, col + 1, constraint))
				return (1);

			grid[row][col] = 0;
		}
		val++;
	}
	return (0);
}
