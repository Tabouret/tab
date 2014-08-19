/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/18 15:46:38 by elacombe          #+#    #+#             */
/*   Updated: 2014/08/19 23:06:44 by pollier          ###   ########.fr       */
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

char	*ft_read_line(char *str);
char	*ft_read_lines(char *str, int n);
void	ft_putstr(char *str);
char	*ft_parse_input(char *file);
int		is_input_valid(char *str);
char	*ft_read_file(char *filename);
int		ft_atoi(char *s1);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int x);
char	**ft_make_tab(char *str, int x, int y);
int		ft_check_empty (char **tab, int tab_check[], char empty);
int		ft_biggest_offset_x (int x, int y);
int		ft_biggest_offset_y (int x, int y);
int		ft_biggest_square (int x, int y);
int		ft_gps(char **tab, int value[], char empty, char solved_char);
void	ft_print_tab (char **tab);
char	*ft_strcat(char *dest, char *src, int *index);
char	*ft_strconcat(char *dest, char *str);
int		ft_strlen(char *str);
int		ft_strnlen(char *str, int offset);
char	*ft_strdup(char *source);
char	*ft_strndup(char *source, int offset);

typedef struct	s_stats
{
	int			height;
	int			width;
	char		obstacle;
	char		empty;
	char		full;
	char		**tab;
}				t_stats;

#endif
