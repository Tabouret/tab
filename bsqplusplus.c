/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsqplusplus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/19 22:56:29 by pollier           #+#    #+#             */
/*   Updated: 2014/08/20 03:17:20 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_header.h"

int				main(int argc, char *argv[])
{
	int i;

	i =0;
	while (++i <= argc)
	{
		ft_highway_to_segfaults(argv, i);
	}
	return 0;
}

t_params		unicorn(int call)
{
	/*implement singleton here*/
}

void			ft_highway_to_segfaults(char **argv, int i)
{
	ft_open_file(argv, i);
}

char			*ft_open_file(char **argv, int i)
{
	int			test;
	char		*olol;
	t_params	*params;


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
	int		u;
	char 	buff[BUFF_SIZE + 1];

	u = params->width * params->height + params->width;
	if ((content = (char*)malloc(sizeof(char) *	u)) == NULL)
		return (NULL);
	content[0] = '\0';
	if(!(d = open(filename, O_RDONLY)))
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
	ft_putstr(content);
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

char *ft_strcat(char *dest, char *src, int *index)
{
	int dest_size;
	int i;

	dest_size = *index;
	i = 0;
	while (src [i] != '\0')
	{
		dest[dest_size] = src[i];
		i++;
		dest_size++;
	}
	dest[dest_size] = '\0';
	*index = dest_size;
	return (dest);
}

int		ft_atoi(char *s1)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (s1[i] && s1[i] <= '9' && s1[i] >= '0')
	{
		nb = (nb * 10) + (s1[i] - '0');
		i++;
	}
	return (nb);
}
