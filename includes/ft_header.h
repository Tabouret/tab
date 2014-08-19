/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/18 15:46:38 by elacombe          #+#    #+#             */
/*   Updated: 2014/08/20 01:37:49 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FT_HEADER_H
# define	FT_HEADER_H
# include	<unistd.h>
# include	<stdlib.h>
# include	<sys/types.h>
# include	<sys/stat.h>
# include	<fcntl.h>
# define	BUFF_SIZE	4096

void			ft_highway_to_segfaults(char **argv, int i);
char			*ft_open_file(char **argv, int i);
t_params		*ft_get_grid_param(int i);
t_params		*ft_read_files(char *filename);
char			*ft_read_grid_first_line(char *str);
int				ft_read_grid_second_line(char *str);

typedef struct	s_params
{
	int			height;
	int			width;
	char		obstacle;
	char		empty;
	char		full;
	char		**tab;
}				t_params;

#endif
