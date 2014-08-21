/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trucs3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/21 22:49:01 by pollier           #+#    #+#             */
/*   Updated: 2014/08/21 22:50:09 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_header.h"

int			ft_read_grid_second_line(char *str)
{

	int		i;
	int		j;

	i = 0;
	j = 1;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	while (str[j + i] != '\n' && str[j + i] != '\0')
		j++;
	return (j - 1);
}

char		*ft_strcat(char *dest, char *src)
{
	int dest_size;
	int i;

	dest_size = ft_struct(2)->index_panda;
	i = 0;
	while (src [i] != '\0')
	{
		dest[dest_size - 1] = src[i - 1];
		i++;
		dest_size++;
	}
	dest[dest_size] = '\0';
	ft_struct(2)->index_panda = dest_size;
	return (dest);
}

int			ft_atoi(char *s1)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (s1[i] && s1[i] <= '9' && s1[i] >= '0')
	{
		nb = (nb * 10) + (s1[i] - '0');
		i++;
	}
	return (nb);
}

int			ft_strnlen(char *str, int offset)
{
	int size;

	size = ft_strlen(str);
	if (offset >= size)
		return (0);
	return (size - offset);
}

int			ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void		ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void		ft_putchar(char c)
{
	write(1, &c, 1);
}
