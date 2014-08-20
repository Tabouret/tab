/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsqplusplus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/19 22:56:29 by pollier           #+#    #+#             */
/*   Updated: 2014/08/20 19:18:13 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_header.h"

int				main(int argc, char *argv[])
{
	int i;

	i = 0;
	while (++i <= argc)
	{
		ft_putstr("Pegasus 0\n");
		ft_open_file(argv, i);
	}
	return 0;
}

t_params	*ft_struct(int call)
{
	static t_params *params;


	if (call == 1)
	{
		params = (t_params *)malloc(sizeof(t_params));
		ft_putstr("Unicorn 1\n");
		return (params);
	}
	if (call == 2)
	{
		ft_putstr("Unicorn 2\n");
		return (params);
	}
	if (call == 3)
	{
		ft_putstr("Unicorn 3\n");
		free(params);
		params = NULL;
	}
	return (params);
}
/*
void			ft_highway_to_segfaults(char **argv, int i)
{
	ft_open_file(argv, i);
}
*/
char			*ft_open_file(char **argv, int i)
{
	int			test;
	t_params	*params;

	ft_putstr("Manfred 1\n");
	test = open(argv[i], O_RDONLY);
	if (test == -1)
		return (NULL);
	params = ft_get_grid_param(test);
	ft_putstr("Manfred 2\n");
	if (close(test))
		return (NULL);
	ft_read_files(argv[i]);
	ft_putstr("Manfred 3\n");
	return (params->str);
}

t_params		*ft_get_grid_param(int i)
{
	char		*param;
	char		buffer[BUFF_SIZE + 1];
	int			test;
	t_params	*params;

	params = ft_struct(1);
	if (!(test = read(i, buffer, BUFF_SIZE)))
		return (NULL);
	buffer[BUFF_SIZE + 1] = '\0';
	if (!(param = ft_read_grid_first_line(buffer)))
		return (NULL);
	if (!(params = (t_params *)malloc(sizeof(t_params))))
		return (NULL);
	params->width = ft_read_grid_second_line(buffer);
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

void		ft_read_files(char *filename)
{
	char		*content;
	int			d;
	int			index;
	int			r;
	int			u;
	char		*buff;
	t_params	*olol;

	ft_putstr("Poilu\n");
	olol = ft_struct(2);
	u = (olol->width * olol->height + olol->width);
	content = (char*)malloc(sizeof(u + 1));
	content[0] = '\0';
	d = open(filename, O_RDONLY);
	r = 1;
	index = 0;
	while (r)
	{
		buff = (char *)malloc(sizeof(BUFF_SIZE + 1));
		r = read(d, buff, BUFF_SIZE);
		buff[r] = '\0';
		ft_putstr("read\n");
		content = ft_strcat(content, buff, &index);
		ft_putstr("read 2\n");
		free(buff);
	}
	ft_putstr(content);
	free(content);
	free(olol->str);
	free(olol);
}

char		*ft_read_grid_first_line(char *str)
{
	char	*reading;
	int		i;

	i = 0;
	while (str[i] != '\n')
	{
		if (str[i] == '\0')
			return (NULL);
		i++;
	}
	if (!(reading = (char *)malloc(i + 1)))
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

	i = 0;
	j = 0;
	while (str[i] != '\n')
		i++;
	while (str[j + i] != '\n')
		j++;
	return (j);
}

char		*ft_strcat(char *dest, char *src, int *index)
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

int			ft_atoi(char *s1)
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

int		ft_strnlen(char *str, int offset)
{
	int size;

	size = ft_strlen(str);
	if (offset >= size)
		return (0);
	return (size - offset);
}

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void		ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

