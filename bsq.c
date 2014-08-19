/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/18 15:47:38 by elacombe          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2014/08/19 21:27:41 by elacombe         ###   ########.fr       */
=======
/*   Updated: 2014/08/19 21:17:05 by pollier          ###   ########.fr       */
>>>>>>> FETCH_HEAD
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

t_stats		*create_stats(char *param)
{
	t_stats	*stats;

	if (!(stats = (t_stats *)malloc(sizeof(t_stats))))
		return (NULL);
	stats->height = ft_atoi(param);
	while (*param >= '0' && *param <= '9')
		param++;
	stats->empty = *param;
	param++;
	stats->obstacle = *param;
	param++;
	stats->full = *param;
	return (stats);
}

t_stats		*ft_read_files(char *filename)
{
	t_stats	*stats;
	char 	*content;
	int		d;
	int		index;
	int		r;
	char 	buff[BUFF_SIZE + 1];
	printf("read config\n");

	stats = create_stats(filename);
	if (!stats)
		return (NULL);
	printf("read width\n");
	stats->width = get_width(filename);
	printf("try to allocate full memory");
	if ((content = (char*)malloc(sizeof(char) *	(stats->width * stats->height + stats->width))) == NULL)
		return (NULL);
	content[0] = '\0';
	d = open(filename, O_RDONLY);
	if (d == 1)
		return (NULL);
	r = 1;
	index = 0;
	while (r)
	{
		r = read(d, buff, 4096);
		if (r <= 0)
			break ;
		buff[r] = '\0';
		printf("read\n");
		content = ft_strcat(content, buff, &index);
	}
	printf( "parsed: \n\n%s\n", content);

	free(content);
	free(stats->tab);
	free(stats);
	return (stats);
}

int get_width(char *filename)
{
	int d;
	int r;
	int i;
	int width;
	char *string;
	char *content;
	char buffer[4096 + 1];

	d = open(filename, O_RDONLY);
	if (d == -1)
		return 0;
	r = 1;
	content = NULL;
	while (r)
	{
		r = read(d, buffer, 4096);
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

t_stats		*get_stats(int i)
{
	char	*param;
	char	buffer[BUFF_SIZE + 1];
	int		test;
	t_stats	*stats;

	if (!(test = read(i, buffer, BUFF_SIZE)))
		return (NULL);
	buffer[BUFF_SIZE + 1] = '\0';
	if (!(param = ft_read_line(buffer)))
		return (NULL);
	stats = create_stats(param);
	ft_putstr(param);
	free(param);
	return (stats);
}

t_stats		*ft_get_param(char **argv, int i)
{
	int			test;
	t_stats		*stats;

<<<<<<< HEAD
=======
=======
	if (!(stats = (t_stats *)malloc(sizeof(t_stats))))
		return (NULL);
	stats->height = ft_atoi(param);
	while (*param >= '0' && *param <= '9')
		param++;
	stats->empty = *param;
	param++;
	stats->obstacle = *param;
	param++;
	stats->full = *param;
	return (stats);
}

t_stats	*get_stats(int i)
{
	char	*param;
	char	buffer[BUFF_SIZE + 1];
	int		test;
	t_stats	*stats;

	if (!(test = read(i, buffer, BUFF_SIZE)))
		return (NULL);
	if (!(param = ft_read_line(buffer)))
		return (NULL);
	stats = create_stats(param);
	free(param);
	return (stats);
}

char	*ft_get_params(char **argv, int i)
{
	int			test;
	t_stats		*stats;

>>>>>>> FETCH_HEAD
>>>>>>> FETCH_HEAD
	test = open(argv[i], O_RDONLY);
	if (test == -1)
		return (NULL);
	stats = get_stats(test);
	if (!(close(test)) || !stats)
		return (NULL);
	/*ft_read_files(stats);*/
	return (stats);
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
