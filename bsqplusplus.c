/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsqplusplus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/19 22:56:29 by pollier           #+#    #+#             */
/*   Updated: 2014/08/21 22:22:14 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_header.h"

int			main(int argc, char *argv[])
{
	int i;

	i = 0;
	while (++i < argc)
	{
		ft_open_file(argv, i);
		ft_struct(3);
	}
	return (0);
}

t_params	*ft_struct(int call)
{
	static t_params *params;

	if (!(params))
	{
		params = (t_params *)malloc(sizeof(t_params));
		params->error = 0;
		params->index_panda = 0;
		ft_putstr("Init struct\n");
		return (params);
	}
	if (call == 2)
	{
		ft_putstr("OMG\n");
		return (params);
	}
	if (call == 3)
	{
		ft_putstr("Free struct\n");
		free(params);
		params = NULL;
	}
	return (params);
}

void		ft_open_file(char **argv, int i)
{
	int			test;

	test = open(argv[i], O_RDONLY);
	ft_get_grid_param(test);
	ft_read_files(argv[i]);
}

void		ft_get_grid_param(int i)
{
	char		*param;
	char		buffer[BUFF_SIZE + 2];
	int			test;

	if (!(test = read(i, buffer, BUFF_SIZE)))
	{
		ft_struct(2)->error = 1;
	}
	buffer[BUFF_SIZE + 1] = '\0';
	if (!(param = ft_read_grid_first_line(buffer)))
	{
		ft_struct(2)->error = 1;
	}
	ft_struct(2)->width = ft_read_grid_second_line(buffer);
	ft_struct(2)->height = ft_atoi(param);
	while (*param >= '0' && *param <= '9')
		param++;
	ft_struct(2)->empty = *param;
	param++;
	ft_struct(2)->obstacle = *param;
	param++;
	ft_struct(2)->full = *param;
}

void		ft_read_files(char *filename)
{
	char		*content;
	int			d;
	int			r;
	int			u;
	char		buff[BUFF_SIZE + 1];

	u = ((ft_struct(2)->width * ft_struct(2)->height) + ft_struct(2)->width + 1);
	content = (char*)malloc(sizeof(char) * (u + ft_struct(2)->width) + 1);
	content[0] = '\0';
	d = open(filename, O_RDONLY);
	while ((r = read(d, buff, BUFF_SIZE)) > 0)
	{
		buff[r + 1] = '\0';
		content = ft_strcat(content, buff);
	}
	ft_putstr("Narwhales Prime\n");
	content[u + 1] = '\0';
	ft_fuck_first_line(content);
	ft_putstr("Narwhales 1\n");
	ft_parse(ft_struct(2)->str);
	ft_putstr("Narwhales 2\n");
	ft_chiasse_a_cour();
	ft_putstr("Narwhales 3\n");
}

void		ft_fuck_first_line(char *str)
{
	char	*reading;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\n')
		i++;
	i++;
	reading = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	while (str[i] != '\0')
	{
		reading[j] = str[i];
		i++;
		j++;
	}
	reading[j] = '\n';
	reading[j] = '\0';
	ft_struct(2)->str = reading;
}

int		ft_check_empty (char **tab, int tab_check[], char empty)
{
	int x;
	int y;

	x = -1;
	y = -1;
	while (++x <= tab_check[2])
	{
		while (++y <= tab_check[2])
		{
			if (tab[x + tab_check[0]][y + tab_check[1]] != empty)
			{
				return (0);
			}
		}
	}
	return (1);
}

void		ft_parse(char *str)
{
	int		i;
	int		ubloop[0];

	i = 0;
	ft_struct(2)->strint = malloc(sizeof(int) * ft_strlen(ft_struct(2)->str));
	ft_putstr("diplodocus Prime\n");
	ft_courante();
	ft_putstr("diplodocus 1\n");
	while (str[i])
	{
		if (str[i] == '\n')
			i++;
		if (str[i] == ft_struct(2)->obstacle)
			ft_struct(2)->strint[i] = 0;
		if (str[i] == ft_struct(2)->empty)
			ft_struct(2)->strint[i] = ft_jaylachiasse(i);
		i++;
		ft_putstr("diplodocus 2\n");
	}
	ft_putstr("Pegasus Prime\n");
	ubloop[0] = -10;
	ft_jaylachiasse(-1);
	ft_sauce_septique();
}

void		ft_sauce_septique(void)
{
	int i;

	i = (ft_struct(2)->height) * (ft_struct(2)->width) - (ft_struct(2)->width) - 2;
	while (ft_struct(2)->str[i])
	{
		if (ft_struct(2)->strint[i - 1] == '\n')
			i--;
		if (ft_struct(2)->str[i] == ft_struct(2)->obstacle)
			ft_struct(2)->strint[i] = 0;
		if (ft_struct(2)->str[i] == ft_struct(2)->empty)
			ft_struct(2)->strint[i] = ft_jaylachiasse(i);
		i--;
		ft_putstr("diplosodomus 2\n");
	}
}

int			ft_jaylachiasse(int i)
{
	int		b;
	int		c;
	int		min;

	ft_struct(2)->max = 0;
	ft_putnbr(ft_struct(2)->max);
	ft_putstr("<-- je suis max avant le premier hippopotame\n");
	min = ft_struct(2)->strint[i + 1];
	ft_putnbr(ft_struct(2)->strint[i]);
	ft_putnbr(ft_struct(2)->max);
	ft_putstr("<-- je suis max apres le premier hippopotame\n");
	if (ft_struct(2)->strint[i] > ft_struct(2)->max)
	{
		ft_struct(2)->max = ft_struct(2)->strint[i];
		ft_struct(2)->pos = i;
		ft_putstr("Hippopotamidae troisieme if chiant\n");
	}
	b = ft_struct(2)->strint[i + (ft_struct(2)->width) + 2];
	if (min > b)
		min = b;
	c = ft_struct(2)->strint[i + (ft_struct(2)->width) + 1];
	if (min > c)
		min = c;
	ft_putnbr(min);
	ft_putstr("<--- je suis min\n");
	return (min);
}

void		ft_chiasse_a_cour(void)
{
	int	i;
	int j;
	int max;
	int pos;

	j = 0;
	i = 0;
	max = ft_struct(2)->max;
	pos = ft_struct(2)->pos;
	ft_putnbr(max);
	ft_putstr("<--- je suis max\n");
	ft_putnbr(pos);
	ft_putstr("<--- je suis pos\n");
	ft_putstr(ft_struct(2)->str);
	ft_putstr("olol poney \n");
	while (i < max || j < max)
	{
		j = 0;
		while (j < max)
		{
			(ft_struct(2)->str[pos + j]) = (ft_struct(2)->full);
			j++;
		}
		pos = pos + (ft_struct(2)->width);
		i++;
	}
	ft_putstr(ft_struct(2)->str);
}

void		ft_putnbr(int x)
{
	int i;
	int j;

	i = x;
	j = 1;
	if (x < 0)
	{
		ft_putchar('-');
		i = -x;
	}
	while (j <= i)
		j *= 10;
	j = j / 10;
	while (j)
	{
		ft_putchar((i / j) % 10 + '0');
		j /= 10;
	}
}

void		ft_courante(void)
{
	int	i;
	int	u;

	i = 0;
	u = ft_struct(2)->width;
	ft_putnbr(u);
	ft_putstr("<-- je suis u le phallu\n");
	while (ft_struct(2)->str[i])
	{
		if (ft_struct(2)->str[i + 1] == '\n')
			ft_ai_je_la_chiasse(i);
		i++;
		ft_putstr("Captain phallu 2\n");
	}
	i = i - u;
	ft_putnbr(i);
	ft_putstr("<-- je suis i le phalli\n");
	while ((ft_struct(2)->str[i]))
	{
		ft_ai_je_la_chiasse(i);
		ft_putstr("Captain phallu 3\n");
		i++;
	}
}

void		ft_ai_je_la_chiasse(int i)
{
	ft_putstr("ma bite est un space marine\n");
	ft_putnbr(i);
	ft_putstr("\n");
	if (ft_struct(2)->str[i] == (ft_struct(2)->empty))
	{
		ft_putstr("ma bite est une tornade\n");
		ft_struct(2)->strint[i] = 1;
		ft_putstr("ma bite est une tornade\n");
	}
	else if (ft_struct(2)->str[i] == (ft_struct(2)->obstacle))
	{
		ft_struct(2)->strint[i] = 0;
		ft_putstr("ma bite est un marabou\n");
	}
	else
		ft_putstr("ma bite est un volcan\n");
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
	j = 1;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	while (str[j + i] != '\n' && str[j + i] != '\0')
		j++;
	return (j - 1);
}

char		*ft_strcat(char *dest, char *src)
{
	int dest_size;
	int i;

	dest_size = ft_struct(2)->index_panda;
	i = 0;
	while (src [i] != '\0')
	{
		dest[dest_size - 1] = src[i - 1];
		i++;
		dest_size++;
	}
	dest[dest_size] = '\0';
	ft_struct(2)->index_panda = dest_size;
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

int			ft_strnlen(char *str, int offset)
{
	int size;

	size = ft_strlen(str);
	if (offset >= size)
		return (0);
	return (size - offset);
}

int			ft_strlen(char *str)
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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
