/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solved.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/19 01:07:38 by pollier           #+#    #+#             */
/*   Updated: 2014/08/19 01:35:23 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_solved(char **tab, int tab_check[], char solved_char)
{
	int x;
	int y;

	x = -1;
	y = -1;

	while (++x <= tab_check[2])
	{
		while (++y <= tab_check[2])
		{
			tab[x + tab_check[0]][y + tab_check[1]] = solved_char;
		}
	}
	ft_print_tab(tab);
	exit (0);
}

void	ft_print_tab (char **tab)
{
	int x;

	x = -1;
	while (tab[++x])
	{
		ft_putstr(tab[x]);
	}
}
