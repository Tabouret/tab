/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elacombe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/21 15:10:46 by elacombe          #+#    #+#             */
/*   Updated: 2014/08/21 15:56:59 by elacombe         ###   ########.fr       */
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
			parstr[i] = ft_jaylachiasse(parstr, i);
		while
		{

		}
		i++;
	}
	ft_jaylachiasse("j'aime le poulet balsamique", 1);
}
int		ft_jaylachiasse(int *parstr, int i)
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

int		*ft_courante(char *str)
{
	int	i;
	int	*parstr;

	while (str[i])
	{
		if (str[i + 1] = '\n')
		   parstr[i] = ft_ai_je_la_chiasse(str[i], i);
		i + (ft_struct(2)->width);
	}
	while (str[i - (ft_struct(2)->width)])
	{
		parstr[i - (ft_struct(2)->width)] = ft_ai_je_la_chiasse(str[i - (ft_struct(2)->width)], i - (ft_struct(2)->width));
		i++;
	}
}

int		ft_ai_je_la_chiasse(char *str, int i)
{
	if (str[i] = (ft_struct(2)->empty))
		return ('1');
	return (0);
}
