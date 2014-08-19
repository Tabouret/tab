/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elacombe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/19 16:02:48 by elacombe          #+#    #+#             */
/*   Updated: 2014/08/19 16:42:54 by elacombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_header.h"

t_config	*create_config(char *params)
{
	t_config	*config;
    
	if (!(config = (t_config *)malloc(sizeof(t_config))))
		return (NULL);
	config->height = ft_atoi(params);
	ft_putstr("test4\n");
	while (*params >= '0' && *params <= '9')
		params++;
	config->empty = *params;
	config->obstacle = *(++params);
	config->full = *(++params);
	ft_putstr("test3\n");
	return (config);
}

t_config	*read_config(int i)
{
	char		*params;
	char		buffer[BUFF_SIZE + 1];
	int			test;
	t_config	*config;
    
	if (!(test = read(i, buffer, BUFF_SIZE)))
		return (NULL);
	buffer[BUFF_SIZE + 1] = '\0';
	params = ft_read_line(buffer);
	if (!params)
		return (NULL);
	config = create_config(params);
	ft_putstr("test2\n");
	free(params);
	return (config);
}

char		*ft_parse_input(char *file)
{
	int			test;
	t_config	*config;

	if (!(test = open(file, O_RDONLY)))
		return (NULL);
	config = read_config(test);
	ft_putstr("test1\n");
	if ((close(test)) == -1 || !config)
		return (NULL);
	return ("");
}
