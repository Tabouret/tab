/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsqplusplus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/19 22:56:29 by pollier           #+#    #+#             */
/*   Updated: 2014/08/20 00:58:54 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_header.h"

int			main(int argc, char const *argv[])
{
	int i;
	char *tab;

	i =0;
	while (++i <= argc)
	{
		tab = ft_highway_to_segfaults(argv, i);
	}
	return 0;
}

void		ft_highway_to_segfaults(char **argv, int i)
{
	ft_open_file
}

char		*ft_open_file(char **argv, int i)
{
	int			test;
	t_params		*params;

	test = open(argv[i], O_RDONLY);
	if (test == -1)
		return (NULL);
	params = ft_get_grid_param(test);
	if (!(close(test)) || !params)
		return (NULL);
	ft_read_files(argv[i]);
	return (t_params->params);
}

t_params		*ft_get_grid_param(int i)
{
	char	*param;
	char	buffer[BUFF_SIZE + 1];
	int		test;
	t_params	*params;

	if (!(test = read(i, buffer, BUFF_SIZE)))
		return (NULL);
	buffer[BUFF_SIZE + 1] = '\0';
	if (!(param = ft_read_grid_first_line(buffer)))
		return (NULL);
	params->width = ft_read_grid_second_line(buffer);
	if (!(params = (t_params *)malloc(sizeof(t_params))))
		return (NULL);
	params->height = ft_atoi(param);
	while (*param >= '0' && *param <= '9')
		param++;
	params->empty = *param;
	param++;
	params->obstacle = *param;
	param++;
	params->full = *param;
	free(param);
	return (params);
}

t_params		*ft_read_files(char *filename)
{
	char 	*content;
	int		d;
	int		index;
	int		r;
	char 	buff[BUFF_SIZE + 1];

	if ((content = (char*)malloc(sizeof(char) *	(params->width * params->height + params->width))) == NULL)
		return (NULL);
	content[0] = '\0';
	d = open(filename, O_RDONLY);
	if (d == 1)
		return (NULL);
	r = 1;
	index = 0;
	while (r)
	{
		r = read(d, buff, BUFF_SIZE);
		buff[r] = '\0';
		printf("read\n");
		content = ft_strcat(content, buff, &index);
	}
	free(content);
	free(params->tab);
	free(params);
	return (params);
}

char		*ft_read_grid_first_line(char *str)
{
	char	*reading;
	int		i;

	while (str[i] != '\n')
	{
		if (str[i] == '\0')
			return (NULL);
		i++;
	}
	if (!(reading = (char *)malloc(i)))
		return (NULL);
	i = 0;
	while (str[i] != '\n')
	{
		reading[i] = str[i];
		i++;
	}
	reading[i] = '\0';
	return (reading);
}

int			ft_read_grid_second_line(char *str)
{

	int		i;
	int		j;

	while (str[i] != '\n')
		i++;
	while (str[j + i] != '\n')
		j++;
	return (j);
}


