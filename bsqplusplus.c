/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsqplusplus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/19 22:56:29 by pollier           #+#    #+#             */
/*   Updated: 2014/08/21 22:47:26 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_header.h"

int			main(int argc, char *argv[])
{
	int i;

	i = 0;
	while (++i < argc)
	{
		ft_open_file(argv, i);
		ft_struct(3);
	}
	return (0);
}

t_params	*ft_struct(int call)
{
	static t_params *params;

	if (!(params))
	{
		params = (t_params *)malloc(sizeof(t_params));
		params->error = 0;
		params->index_panda = 0;
		return (params);
	}
	if (call == 2)
	{
		return (params);
	}
	if (call == 3)
	{
		free(params);
		params = NULL;
	}
	return (params);
}

void		ft_open_file(char **argv, int i)
{
	int			test;

	test = open(argv[i], O_RDONLY);
	ft_get_grid_param(test);
	ft_read_files(argv[i]);
}

void		ft_get_grid_param(int i)
{
	char		*param;
	char		buffer[BUFF_SIZE + 2];
	int			test;

	if (!(test = read(i, buffer, BUFF_SIZE)))
	{
		ft_struct(2)->error = 1;
	}
	buffer[BUFF_SIZE + 1] = '\0';
	if (!(param = ft_read_grid_first_line(buffer)))
	{
		ft_struct(2)->error = 1;
	}
	ft_struct(2)->width = ft_read_grid_second_line(buffer);
	ft_struct(2)->height = ft_atoi(param);
	while (*param >= '0' && *param <= '9')
		param++;
	ft_struct(2)->empty = *param;
	param++;
	ft_struct(2)->obstacle = *param;
	param++;
	ft_struct(2)->full = *param;
}

void		ft_read_files(char *filename)
{
	char		*content;
	int			d;
	int			r;
	int			u;
	int			e;
	char		buff[BUFF_SIZE + 1];

	e = ft_struct(2)->height) + ft_struct(2)->width + 1;
	u = ((ft_struct(2)->width * e);
	content = (char*)malloc(sizeof(char) * (u + ft_struct(2)->width) + 1);
	content[0] = '\0';
	d = open(filename, O_RDONLY);
	while ((r = read(d, buff, BUFF_SIZE)) > 0)
	{
		buff[r + 1] = '\0';
		content = ft_strcat(content, buff);
	}
	content[u + 1] = '\0';
	ft_fuck_first_line(content);
	ft_parse(ft_struct(2)->str);
	ft_chiasse_a_cour();
}
