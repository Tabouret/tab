/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_empty.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/18 23:39:20 by pollier           #+#    #+#             */
/*   Updated: 2014/08/19 00:03:09 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_gps(char **tab, int size_x, int size_y, int sqr_size, char empty)
{
	int x;
	int y;
	int check;

	x = -1;
	y = -1;
	yes_we_check = 0;
	while (y <= (size_y - sqr_size))
	{
		while(x <= (size_x - sqr_size))
		{
			check = ft_check_empty(tab, x, y, sqr_size, empty);
			if (check == 1)
			{

			}
		}
	}
}

int		ft_check_empty (char **tab, int off_x, int off_y, int size, char empty)
{
	int x;
	int y;

	x = -1;
	y = -1;

	while (++x <= size)
	{
		while (++y <= size)
		{
			if (tab[x + off_x][y + off_y] != empty)
			{
				return (0);
			}
		}
	}
	return (1);
}
