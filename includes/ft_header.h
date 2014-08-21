/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/18 15:46:38 by elacombe          #+#    #+#             */
/*   Updated: 2014/08/21 22:58:46 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef			FT_HEADER_H
# define		FT_HEADER_H
# include		<unistd.h>
# include		<stdlib.h>
# include		<stdio.h>
# include		<sys/types.h>
# include		<sys/stat.h>
# include		<fcntl.h>
# define		BUFF_SIZE	4096

typedef struct	s_params
{
	int			height;
	int			width;
	int			error;
	int			index_panda;
	char		obstacle;
	char		empty;
	char		full;
	char		*str;
	int			*strint;
	int			max;
	int			pos;
}				t_params;

void			ft_open_file(char **argv, int i);
void			ft_get_grid_param(int i);
void			ft_read_files(char *filename);
char			*ft_read_grid_first_line(char *str);
int				ft_read_grid_second_line(char *str);
char			*ft_strcat(char *dest, char *src);
int				ft_atoi(char *s1);
t_params		*ft_struct(int call);
int				ft_strnlen(char *str, int offset);
int				ft_strlen(char *str);
void			ft_fuck_first_line(char *str);
void			ft_parse(char *str);
int				ft_jaylachiasse(int i);
void			ft_courante(void);
void			ft_ai_je_la_chiasse(int i);
void			ft_chiasse_a_cour();
void			ft_sauce_septique(void);

#endif
