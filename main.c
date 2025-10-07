#include <stdlib.h>
#include "rush01.h"

int	*parse_input(char *str, int num)
{
	int	*arr;
	int	i;

	i = 0;
	arr = malloc(num * sizeof(int));
	if (!arr)
		return (NULL);
	while (*str && i < num) 
	{
		if (*str >= '1' && *str <= '4')
		{
			if(*(str + 1) >= '0' && *(str + 1) <= '9')
				return (free(arr), NULL);
			arr[i++] = *str - '0';
		} else if (*str != ' ')
			return (free(arr), NULL);
		str++;
	}
	if (i != num)
		return (free(arr), NULL);
	return (arr);
}

// row = height
// col = width
int	main(int argc, char **argv)
{
	int	grid[4][4] = {0};
	int	*constraint;

	if (argc == 2)
	{
		constraint = parse_input(argv[1], 16);
		if (constraint)
		{
			if (rush01(grid, 0, 0, constraint))
				return (free(constraint), 0);
			free(constraint);
		}
	}
	ft_putstr("Error\n");
	return (0);
}
