/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elacombe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/18 17:52:00 by elacombe          #+#    #+#             */
/*   Updated: 2014/08/18 19:01:58 by elacombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_header.h"

int ft_atoi(char *s1)
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

void	ft_putchar (char c)
{
	write (1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int x)
{
	int i;
	int	j;

	i = x;
	j = 1;
	if (x < 0)
	{
		ft_putchar('-');
		i = -x;
	}
	while (j <= i)
		j *= 10;
	j = j / 10;
	while (j)
	{
		ft_putchar((i / j) % 10 + '0');
		j /= 10;
	}
}

char	**ft_make_tab(char *str, int x, int y)
{
	int		i;
	char	**src;

	i = 0;
	if (!(src = (char **)malloc(sizeof(char *) * (x + 1))))
		return (0);
	while (i < x + 1)
	{
		src[i] = malloc(sizeof(char) * (y + 1));
		i++;
	}
	i = 5;
	x = 0;
	y = 0;
	ft_putstr(str);

	while (str[i])
	{	

		ft_putstr(str);
		while (str[i] != '\n')
		{ 
			src[x][y] = str[i];
			i++;
			y++;
		}
		x++;
		i++;
		y = 0;
	}
	return (src);
}
