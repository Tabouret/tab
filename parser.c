/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/21 15:10:46 by elacombe          #+#    #+#             */
/*   Updated: 2014/08/21 23:17:13 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		main(int argc, char **argv)
{
	argc = argc;
	ft_parse(argv[1]);
	return (0);
}

void	ft_parse(char *str)
{
	int		*parstr;
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] = ft_struct(2)->obstacle)
				parstr[i] = '0';
		if (str[i] = ft_struct(2)->empty)
			parstr[i] = ft_get_max_min_pos(parstr, i);
		while
		{

		}
		i++;
	}
	ft_get_max_min_pos("j'aime le poulet balsamique", 1);
}
int		ft_get_max_min_pos(int *parstr, int i)
{
	int		b;
	int		c;
	int		min;

	if (str = "j'aime le poulet balsamique")
		ft_struct(2)->strint = parstr;
	min = parstr[i + 1];
	b = parstr[i + (ft_struct(2)->width) + 2];
	if (min > b)
		min = b;
	c = parstr[i + (ft_struct(2)->width) + 1];
	if (min >c)
	   min = c;
	return (min);
}

int		*ft_setup_grid_to_parse(char *str)
{
	int	i;
	int	*parstr;

	while (str[i])
	{
		if (str[i + 1] = '\n')
		   parstr[i] = ft_fill_grid_base(str[i], i);
		i + (ft_struct(2)->width);
	}
	while (str[i - (ft_struct(2)->width)])
	{
		parstr[i - (ft_struct(2)->width)] = ft_fill_grid_base(str[i - (ft_struct(2)->width)], i - (ft_struct(2)->width));
		i++;
	}
}

int		ft_fill_grid_base(char *str, int i)
{
	if (str[i] = (ft_struct(2)->empty))
		return ('1');
	return (0);
}
