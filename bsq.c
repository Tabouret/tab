/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elacombe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/18 15:47:38 by elacombe          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2014/08/19 18:38:02 by elacombe         ###   ########.fr       */
=======
/*   Updated: 2014/08/19 17:55:57 by elacombe         ###   ########.fr       */
>>>>>>> FETCH_HEAD
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_header.h"

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

t_stats	*ft_read_files(char *filename)
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


t_stats	*create_stats(char *param)
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
t_stats	*create_stats(char *param)
{
	t_stats	*stats;

<<<<<<< HEAD
t_stats	*get_stats(int i)
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
	buffer = ft_read_lines(stats);
	free(param);
	return (stats);
}

char	*ft_get_params(char **argv, int i)
{
	int			test;
	t_stats		*stats;	

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
	test = open(argv[i], O_RDONLY);
	if (test == -1)
		return (NULL);
	stats = get_stats(test);
	if (!(close(test)) || !stats)
		return (NULL);
<<<<<<< HEAD
	ft_read_files(stats);
=======
>>>>>>> FETCH_HEAD
	return ("");
}
char	*ft_what_input(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc > 1)
	{
		while (argv[i])
		{
			ft_get_params(argv, i);
			i++;
		}
	}
	else if (argc == 1)
		ft_get_params(argv, i);
	return ("");
}
int		main(int argc, char **argv)
{
	ft_what_input(argc, argv);
	return (0);
}
