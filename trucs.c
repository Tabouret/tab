/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trucs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/21 22:46:57 by pollier           #+#    #+#             */
/*   Updated: 2014/08/21 23:15:33 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

void		ft_rm_first_line(char *str)
{
	char	*reading;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\n')
		i++;
	i++;
	reading = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	while (str[i] != '\0')
	{
		reading[j] = str[i];
		i++;
		j++;
	}
	reading[j] = '\n';
	reading[j] = '\0';
	ft_struct(2)->str = reading;
}

int			ft_check_empty (char **tab, int tab_check[], char empty)
{
	int x;
	int y;

	x = -1;
	y = -1;
	while (++x <= tab_check[2])
	{
		while (++y <= tab_check[2])
		{
			if (tab[x + tab_check[0]][y + tab_check[1]] != empty)
			{
				return (0);
			}
		}
	}
	return (1);
}

void		ft_parse(char *str)
{
	int		i;

	i = 0;
	ft_struct(2)->strint = malloc(sizeof(int) * ft_strlen(ft_struct(2)->str));
	ft_setup_grid_to_parse();
	while (str[i])
	{
		if (str[i] == '\n')
			i++;
		if (str[i] == ft_struct(2)->obstacle)
			ft_struct(2)->strint[i] = 0;
		if (str[i] == ft_struct(2)->empty)
			ft_struct(2)->strint[i] = ft_get_max_min_pos(i);
		i++;
	}
	ft_get_max_min_pos(-1);
	ft_fill_rest_of_grid();
}

void		ft_fill_rest_of_grid(void)
{
	int i;
	int j;

	j = ft_struct(2)->height * ft_struct(2)->width;
	i = j - (ft_struct(2)->width) - 2;
	while (ft_struct(2)->str[i])
	{
		if (ft_struct(2)->strint[i - 1] == '\n')
			i--;
		if (ft_struct(2)->str[i] == ft_struct(2)->obstacle)
			ft_struct(2)->strint[i] = 0;
		if (ft_struct(2)->str[i] == ft_struct(2)->empty)
			ft_struct(2)->strint[i] = ft_get_max_min_pos(i);
		i--;
	}
}

int			ft_get_max_min_pos(int i)
{
	int		b;
	int		c;
	int		min;

	ft_struct(2)->max = 0;
	min = ft_struct(2)->strint[i + 1];
	if (ft_struct(2)->strint[i] > ft_struct(2)->max)
	{
		ft_struct(2)->max = ft_struct(2)->strint[i];
		ft_struct(2)->pos = i;
	}
	b = ft_struct(2)->strint[i + (ft_struct(2)->width) + 2];
	if (min > b)
		min = b;
	c = ft_struct(2)->strint[i + (ft_struct(2)->width) + 1];
	if (min > c)
		min = c;
	return (min);
}
