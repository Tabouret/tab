/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elacombe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/19 15:16:22 by elacombe          #+#    #+#             */
/*   Updated: 2014/08/19 15:25:51 by elacombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_header.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void    ft_putnbr(int x)
{
	int i;
	int j;

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

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}
