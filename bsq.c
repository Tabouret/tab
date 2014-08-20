/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/18 15:47:38 by elacombe          #+#    #+#             */
/*   Updated: 2014/08/20 00:25:37 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./includes/ft_header.h"
#include <stdio.h>

char		*ft_buffer(char **argv)
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

t_params		*create_params(char *param)
{
	t_params	*params;

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
	return (params);
}

t_params		*ft_read_files(char *filename)
{
	t_params	*params;
	char 	*content;
	int		d;
	int		index;
	int		r;
	char 	buff[BUFF_SIZE + 1];
	printf("read config\n");

	params = create_params(filename);
	if (!params)
		return (NULL);
	printf("read width\n");
	params->width = get_width(filename);
	printf("try to allocate full memory");
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
		if (r <= 0)
			break ;
		buff[r] = '\0';
		printf("read\n");
		content = ft_strcat(content, buff, &index);
	}
	printf( "parsed: \n\n%s\n", content);

	free(content);
	free(params->tab);
	free(params);
	return (params);
}

int get_width(char *filename)
{
	int d;
	int r;
	int i;
	int width;
	char *string;
	char *content;
	char buffer[BUFF_SIZE + 1];

	d = open(filename, O_RDONLY);
	if (d == -1)
		return 0;
	r = 1;
	content = NULL;
	while (r)
	{
		r = read(d, buffer, BUFF_SIZE);
		if (r <= 0)
			break ;
		content = ft_strconcat(content, buffer);
		string = ft_read_lines(content, 2);
		if (string)
			break ;
	}
	width = 0;
	i = 0;
	while (i < 2)
	{
		if(*string == '\n')
		{
			i++;
			if (i < 2)
				width = 0;
			else
				break;
		}
		string++;
		width++;
	}
	close(d);
	return (width - 1);
}

t_params		*get_params(int i)
{
	char	*param;
	char	buffer[BUFF_SIZE + 1];
	int		test;
	t_params	*params;

	if (!(test = read(i, buffer, BUFF_SIZE)))
		return (NULL);
	buffer[BUFF_SIZE + 1] = '\0';
	if (!(param = ft_read_line(buffer)))
		return (NULL);
	params = create_params(param);
	ft_putstr(param);
	free(param);
	return (params);
}

t_params		*ft_get_param(char **argv, int i)
{
	int			test;
	t_params		*params;

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
	return (params);
}

int			main(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i <= argc)
	{
		ft_get_param(argv, i);
		i++;
	}
	return (0);
}
