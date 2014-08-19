/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_lines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elacombe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/19 16:16:16 by elacombe          #+#    #+#             */
/*   Updated: 2014/08/19 21:27:44 by elacombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_header.h"

char	*ft_read_line(char *str)
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

char *ft_read_lines(char *str, int n)
{
	char *result;
	int i;
	int count;
	int size;

	i = 0;
	count = 0;
	while (count < n)
	{
		if(str[i] == '\0')
		{
			return (NULL);
		}
		if(str[i] == '\n')
		{
			count++;
		}
		i++;
	}
	if ((result = (char*)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	size = i;
	i = 0;
	while (i < size)
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
