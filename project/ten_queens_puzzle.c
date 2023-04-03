#include <unistd.h>
#include <stdio.h>
#include <string.h>

void	printing(int array[10][10]);
void	populate(int array[10][10]);

int	isgood_line(int grid[10][10], int row, int col)
{
	int	i;
	int	j;

	i = -1;
	while (++i < row)
	{
		if (grid[i][col] == 1)
			return (0);
	}
	i = row + 1;
	j = col + 1;
	while (--i >= 0 && --j >= 0)
	{
		if (grid[i][j] == 1)
			return (0);
	}
	i = row + 1;
	j = col - 1;
	while (--i >= 0 && ++j < 10)
	{
		if (grid[i][j] == 1)
			return (0);
	}
	return (1);
}
int	isgood_linecol(int grid[10][10], int row, int col)
{
	int	i;
	int	j;

	j = -1;
	while (++j < col)
	{
		if (grid[row][j] == 1)
			return (0);
	}
	i = row + 1;
	j = col + 1;
	while (--i >= 0 && --j >= 0)
	{
		if (grid[i][j] == 1)
			return (0);
	}
	i = row - 1;
	j = col + 1;
	while (++i < 10 && --j >= 0)
	{
		if (grid[i][j] == 1)
			return (0);
	}
	return (1);
}

int	queenplace(int grid[10][10], int row, int *count)
{
	int	col;

	col = -1;
	if (row == 10)
	{
		printing(grid);
		*count += 1;
		return (1);
	}
	while (++col < 10)
	{
		if (isgood_line(grid, row, col) == 1)
		{
			grid[row][col] = 1;
			queenplace(grid, row + 1, count);
			grid[row][col] = 0;
		}
	}
	return (0);
}

void	populate(int array[10][10])
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < 10)
	{
		while (++j < 10)
		{
			array[i][j] = 0;
		}
		j = -1;
	}
}

void	printing(int array[10][10])
{
	int		row;
	int		col;
	char	res;

	row = -1;
	col = -1;
	while (++row < 10)
	{
		while (++col < 10)
		{
			if (array[row][col] == 1)
			{
				res = col + 48;
				write(1, &res, 1);
			}
		}
		col = -1;
	}
	write(1, "\n", 1);
}

int	ft_ten_queens_puzzle(void)
{
	int	array[10][10];
	int	row;
	int	count;

	count = 0;
	row = 0;
	populate(array);
	queenplace(array, row, &count);
	return (count);
}
int ft_check(char *str)
{
    int i;
    int check;

    i = 0;
    check = 0;
    while (str[i])
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            check++;
        }
        else
            return (1);
		i++;
    }
    if (check == 10)
        return (0);
    else
        return (1);
}

int	trysolve(char *str)
{
	int	array[10][10];
	int	i;
	int	j;

	populate(array);
	i = 0;
	j = 0;
	while (j < 10)
	{
		while (i < 10)
		{
			if (i == (str[j] - '0'))
			{
				if (isgood_linecol(array, i, j) == 1)
				{
					array[i][j] = 1;
				}
				else
				{
					return (0);
				}
			}
			i++;
		}
		j++;
		i = 0;
	}
	return (1);
}

int	main(int argc, char **argv)
{
    if (argc == 1)
    {
        printf("Hello all, do you know about the ten queens puzzle ?\n");
        printf("if not, write 'no' as a command line arguments.\n");
        printf("Else write your solution in a command line argument, in a 10 numbers fashion, which begin at 0 to 9, where each of them is the position of a queen in the row.\n");
        printf("If you want all the solution, write 'soluce' as a command line argument.\n");
        printf("Have Fun !\n" );
        return (0);
    }
    if (argc > 2)
    {
        printf("Only one argument at a time !\n");
        return (0);
    }
    if (strcmp(argv[1],"no") == 0)
    {
        printf("The goal of this game is to place 10 queens on a 10x10 board without them threatening each other !\n");
        printf("For non chess player, a queen moves any number of squares vertically, horizontally or diagonally ! \n");
        printf("Have it a try ! Try your solution like that '851295474' in a command line argument\n");
        printf("The numbers is the position of a queen in the row, like for this example : The queen is at row 8 in the first column !\n");
        return (0);
    }
    else if (strcmp(argv[1],"soluce") == 0)
    {
        printf("Count of solutions : %d\n",ft_ten_queens_puzzle());
        return(0);
    }
    else if (ft_check(argv[1]) == 0)
    {
		if (trysolve(argv[1]) == 1)
		{
			printf("SUCCESS !\n");
			return (1);
		}
		else
		{
			printf("TOO BAD ! WRONG\n");
			return (0);
		}
    }
	else
	{
		printf("Please input no, soluce, or a valid solution.\n");
		return (0);
	}
}