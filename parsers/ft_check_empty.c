/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_empty.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/18 23:39:20 by pollier           #+#    #+#             */
/*   Updated: 2014/08/19 00:31:47 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		*ft_gps(char **tab, int value[], char empty)
{
	int x;
	int y;
	int tab_check[2];

	x = -1;
	y = -1;
	while (++y <= (value[1] - value[2]))
	{
		while(++x <= (value[0] - value[2]))
		{
			tab_check [0] = x;
			tab_check [1] = y;
			tab_check [2] = value[2];
			if (ft_check_empty(tab, tab_check, empty);)
			{
				/*put win statement here*/
			}
		}
	}
}

int		ft_check_empty (char **tab, int tab_check[], char empty)
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
