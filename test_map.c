#include "cube.h"
#include "libft.h"

int test_up(char **m, int hi, int wi)
{
    int	i;
	int	j;

    j = 0;
	while(j <= wi - 1)
	{
		i = 0;
		while (m[i][j] != '1')
		{
			if (m[i][j] != ' ')
				return (-1);
			if (!((j - 1 < 0 || (m[i][j - 1] == ' ' || m[i][j - 1] == '1')) &&
			(j + 1 > wi || (m[i][j + 1] == ' ' || m[i][j + 1] == '1'))))
				return (-1);
			i++;
		}
		if (!((j - 1 < 0 || (m[i][j - 1] == ' ' || m[i][j - 1] == '1')) &&
			(j + 1 > wi || (m[i][j + 1] == ' ' || m[i][j + 1] == '1'))))
				return (-1);
		j++;
	}
    return (0);
}

int test_right(char **m, int hi, int wi)
{
    int	i;
	int	j;

    i = 0;
	while(i <= hi - 1)
	{
		j = wi - 1;
		while (m[i][j] != '1')
		{
			if (m[i][j] != ' ')
				return (-1);
			if (!((i - 1 < 0 || (m[i - 1][j] == ' ' || m[i - 1][j] == '1')) &&
			(i + 1 > hi - 1 || (m[i + 1][j] == ' ' || m[i + 1][j] == '1'))))
				return (-1);
			j--;
		}
		if (!((i - 1 < 0 || (m[i - 1][j] == ' ' || m[i - 1][j] == '1')) &&
			(i + 1 > hi - 1 || (m[i + 1][j] == ' ' || m[i + 1][j] == '1'))))
				return (-1);
		i++;
	}
    return (0);
}

int test_down(char **m, int hi, int wi)
{
    int	i;
	int	j;

	j = 0;
	while(j <= wi - 1)
	{
	    i = hi - 1;
		while (m[i][j] != '1')
		{
			if (m[i][j] != ' ')
				return (-1);
			if (!((j - 1 < 0 || (m[i][j - 1] == ' ' || m[i][j - 1] == '1')) &&
			(j + 1 > wi || (m[i][j + 1] == ' ' || m[i][j + 1] == '1'))))
				return (-1);
			i--;
		}
		if (!((j - 1 < 0 || (m[i][j - 1] == ' ' || m[i][j - 1] == '1')) &&
			(j + 1 > wi || (m[i][j + 1] == ' ' || m[i][j + 1] == '1'))))
				return (-1);
		j++;
	}
    return (0);
}

int test_left(char **m, int hi, int wi)
{
    int	i;
	int	j;

    i = 0;
	while(i <= hi - 1)
	{
		j = 0;
		while (m[i][j] != '1')
		{
			if (m[i][j] != ' ')
				return (-1);
			if (!((i - 1 < 0 || (m[i - 1][j] == ' ' || m[i - 1][j] == '1')) &&
			(i + 1 > hi - 1 || (m[i + 1][j] == ' ' || m[i + 1][j] == '1'))))
				return (-1);
			j++;
		}
		if (!((i - 1 < 0 || (m[i - 1][j] == ' ' || m[i - 1][j] == '1')) &&
			(i + 1 > hi - 1 || (m[i + 1][j] == ' ' || m[i + 1][j] == '1'))))
				return (-1);
		i++;
	}
    return (0);
}

int test_map(t_params *params)
{
    int out;

    out = test_up(params->map, params->hight, params->width);
    if (out == -1)
        return (-1);
    out = test_right(params->map, params->hight, params->width);
    if (out == -1)
        return (-1);
    out = test_down(params->map, params->hight, params->width);
    if (out == -1)
        return (-1);
    out = test_left(params->map, params->hight, params->width);
    return (out);
}