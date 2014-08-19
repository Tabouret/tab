/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/18 17:52:00 by elacombe          #+#    #+#             */
/*   Updated: 2014/08/19 21:27:47 by elacombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_header.h"

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

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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

char	*ft_strconcat(char *dest, char *str)
{
	int		new_size;
	char	*result;
	int		i;
	int		j;

	int d_size = ft_strlen(dest);
	int s_size = ft_strlen(str);

	new_size = d_size + s_size;
	if((result = (char*)malloc(sizeof(char) * new_size)) == NULL)
		return (NULL);
	i = 0;
	if (dest != NULL)
	{
		while (i < d_size)
		{
			result[i] = dest[i];
			i++;
		}
		free(dest);
		dest = NULL;
	}
	j = 0;
	while (str[j] != '\0')
	{
		result[i] = str[j];
		i++;
		j++;
	}
	result[i] = '\0';
	return (result);
}

int		ft_strnlen(char *str, int offset)
{
	int size;

	size = ft_strlen(str);
	if (offset >= size)
		return (0);
	return (size - offset);
}

char	*ft_strdup(char *source)
{
	char	*result;
	int		size;
	int		i;

	size = ft_strlen(source);
	if ((result = (char*)malloc(sizeof(char) * size)) == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		result[i] = source[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strndup(char *source, int offset)
{
	char	*result;
	int		size;
	int		i;
	size = ft_strnlen(source, offset);
	if (size == 0)
		return (NULL);
	if ((result = (char*)malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		result[i] = source[i + offset];
		i++;
	}
	result[i] = '\0';
	return (result);
}

/*char	*ft_strdup_to(char *str, char delimiter)
{
	int		i;
	int		size;
	char	*result;

	size = 0;
	i = 0;
	while (str[i] != delimiter)
	{
		size++;
	}
	if (!size)
		return (NULL);
	if ((result = (char*)malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	while (i <= size)
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}*/
