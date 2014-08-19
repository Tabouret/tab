/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsqplusplus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/19 22:56:29 by pollier           #+#    #+#             */
/*   Updated: 2014/08/19 23:23:06 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
	t_stats		*stats;

	test = open(argv[i], O_RDONLY);
	if (test == -1)
		return (NULL);
	stats = get_stats(test);
	if (!(close(test)) || !stats)
		return (NULL);
	return (t_stats->stats);
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
	char 	*content;
	int		d;
	int		index;
	int		r;
	char 	buff[BUFF_SIZE + 1];
	printf("read config\n");

	if (!(buff = read()))
	{
		/* code */
	}
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
		r = read(d, buff, BUFF_SIZE);
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
