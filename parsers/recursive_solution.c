/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_solution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabahi <drabahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/10 18:11:01 by drabahi           #+#    #+#             */
/*   Updated: 2014/08/10 18:11:02 by drabahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void			recursive_solution(char map[9][9], int pos, int *nb_sol);
void			display_map(char map[9][9]);

static int		line_conflict(char map[9][9], int line, int n)
{
	int	i;

	i = -1;
	while (++i < 9)
	{
		if (map[line][i] == n + '1')
			return (1);
	}
	return (0);
}

static int		col_conflict(char map[9][9], int col, int n)
{
	int	i;

	i = -1;
	while (++i < 9)
	{
		if (map[i][col] == n + '1')
			return (1);
	}
	return (0);
}

static int		bloc_conflict(char map[9][9], int line, int col, int n)
{
	int	i;
	int	j;

	i = (line / 3) * 3 - 1;
	while (++i < ((line / 3) + 1) * 3)
	{
		j = (col / 3) * 3 - 1;
		while (++j < ((col / 3) + 1) * 3)
		{
			if (map[i][j] == n + '1')
				return (1);
		}
	}
	return (0);
}

void			case_solution(char map[9][9], int pos, int *nb_sol)
{
	int	i;

	i = -1;
	while (++i < 9)
	{
		if (!(bloc_conflict(map, pos / 9, pos % 9, i)
			|| line_conflict(map, pos / 9, i) || col_conflict(map, pos % 9, i)))
		{
			map[pos / 9][pos % 9] = i + '1';
			recursive_solution(map, pos + 1, nb_sol);
		}
	}
	map[pos / 9][pos % 9] = '.';
}

void			recursive_solution(char map[9][9], int pos, int *nb_sol)
{
	if (pos > 80)
	{
		if (*nb_sol == -1)
			display_map(map);
		(*nb_sol)++;
	}
	else if (map[pos / 9][pos % 9] != '.')
		recursive_solution(map, pos + 1, nb_sol);
	else
		case_solution(map, pos, nb_sol);
}
