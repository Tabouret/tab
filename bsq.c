/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elacombe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/18 15:47:38 by elacombe          #+#    #+#             */
/*   Updated: 2014/08/19 17:55:57 by elacombe         ###   ########.fr       */
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

	test = open(argv[i], O_RDONLY);
	if (test == -1)
		return (NULL);
	stats = get_stats(test);
	if (!(close(test)) || !stats)
		return (NULL);
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
