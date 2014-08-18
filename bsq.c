/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elacombe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/18 15:47:38 by elacombe          #+#    #+#             */
/*   Updated: 2014/08/18 22:09:43 by elacombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_header.h"
#include <stdio.h>

char	*ft_catstr(char *dest, char *str)
{
	int		old_size;
	int 	new_size;
	char	buffer[BUFF_SIZE + 1];

	if (!(

}
char	*ft_buffer(char **argv)
{
	char	*buffer;
	int		file;
	int		size;

	buffer = (char *)malloc(BUFF_SIZE + 1);
	if (!(file = open(argv[1], O_RDONLY, S_IREAD)))
		file = 0;
	size = read(file, buffer, BUFF_SIZE);
	buffer[size + 1] = '\0';
	return(buffer);
}

char	*ft_bufferterm()
{
	return (0);
}

int		ft_get_tab_size(char *str)
{
	int	i;

	i = 5;
	while (str[i] != '\n')
		i++;
	return (i - 5);
}

int		main(int argc, char **argv)
{
	char	*str;
	int		x;
	/*int		v;
	int		o;
	int		f;*/
	int		y;
	char	**tab;

	if (!(str = (char *)malloc(4096)))
		return(0);
	if (argc == 2)
		str = ft_buffer(argv);
	else if (argc == 1)
		str = ft_bufferterm();
	y = str[0];
	/*v = str[1];
	o = str[2];
	f = str[3];*/
	x = ft_get_tab_size(str);
	if (!(tab = (char **)malloc(sizeof(char) * (x + 1) * (y + 1))))
		return (0);
	tab = ft_make_tab(str, x, y);
	return (0);
}
