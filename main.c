/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elacombe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/19 14:58:54 by elacombe          #+#    #+#             */
/*   Updated: 2014/08/19 16:47:48 by elacombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_header.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	char *file_content;
	int index;

	if (argc == 3)
		index = 2;
	else if (argc != 2)
		return (0);
	else
		index = 1;
	file_content = ft_parse_input(argv[index]);
	ft_putstr("testou4\n");
	if (!file_content)
	ft_putstr("testou5\n");
		return (0);
	ft_putstr(file_content);
	ft_putstr("testou6\n");
	return (0);
}
