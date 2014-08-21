/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trucs2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/21 22:48:10 by pollier           #+#    #+#             */
/*   Updated: 2014/08/21 23:15:32 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

void		ft_fill_grid_soluce(void)
{
	int	i;
	int j;
	int max;
	int pos;

	j = 0;
	i = 0;
	max = ft_struct(2)->max;
	pos = ft_struct(2)->pos;
	while (i < max || j < max)
	{
		j = 0;
		while (j < max)
		{
			(ft_struct(2)->str[pos + j]) = (ft_struct(2)->full);
			j++;
		}
		pos = pos + (ft_struct(2)->width);
		i++;
	}
}

void		ft_setup_grid_to_parse(void)
{
	int	i;
	int	u;

	i = 0;
	u = ft_struct(2)->width;
	while (ft_struct(2)->str[i])
	{
		if (ft_struct(2)->str[i + 1] == '\n')
			ft_fill_grid_base(i);
		i++;
	}
	i = i - u;
	while ((ft_struct(2)->str[i]))
	{
		ft_fill_grid_base(i);
		i++;
	}
}

void		ft_fill_grid_base(int i)
{
	if (ft_struct(2)->str[i] == (ft_struct(2)->empty))
	{
		ft_struct(2)->strint[i] = 1;
	}
	else if (ft_struct(2)->str[i] == (ft_struct(2)->obstacle))
	{
		ft_struct(2)->strint[i] = 0;
	}
}

char		*ft_read_grid_first_line(char *str)
{
	char	*reading;
	int		i;

	i = 0;
	while (str[i] != '\n')
	{
		if (str[i] == '\0')
			return (NULL);
		i++;
	}
	if (!(reading = (char *)malloc(i + 1)))
		return (NULL);
	i = 0;
	while (str[i] != '\n')
	{
		reading[i] = str[i];
		i++;
	}
	reading[i] = '\0';
	return (reading);
}
