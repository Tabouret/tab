/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsqv2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elacombe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/18 23:44:33 by elacombe          #+#    #+#             */
/*   Updated: 2014/08/19 00:15:56 by elacombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_header.h"

int		is_directory(char *filename)
{
	int res;

	res = open(filename, O_RDWR);
	if (res == -1)
		return (1);
	return (0);
}

char	*ft_read_file(char *filename)
{
	int		d;
	int		ret;
	char	buff[256 + 1];
	char	*content;

	content = NULL;
	if (is_directory(filename))
		return (NULL);
	d = open(filename, O_RDONLY);
	if (d == -1)
		return (NULL);
	ret = 1;
	while (ret)
	{
		ret = read(d, buff, 256);
		if (ret <= 0)
			break ;
		buff[ret] = '\0';
		content = ft_strconcat(content, buff);
	}
	return (content);
}

int		main(int argc, char **argv)
{
	return (0);
}
