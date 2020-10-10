/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b ∫ <euyana-b@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 11:48:46 by euyana-b          #+#    #+#             */
/*   Updated: 2020/10/10 18:55:00 by euyana-b ∫       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# define ALLSYMBOLS "cspdiuxX%-.*0123456789"

typedef	struct	s_flags
{
	int			pos;
	int			n_print;
	int			minus;
	int			zero;
	int			hash;
	int			width;
	int			precision;
	int			precisiontf;
}				t_flags;

int				ft_printf(const char *input, ...);
int				ft_breakdown(const char *input,  va_list arg, t_flags *s_list);
void			ft_format(const char *input, va_list arg, t_flags *s_list);
void			ft_precision(const char *input, va_list arg, t_flags *s_list);
void			ft_width(const char *input, va_list arg, t_flags *s_list);
void			ft_widthstart(const char *input, va_list arg, t_flags *s_list);
void			ft_flags(const char *input, t_flags *s_list);
void			ft_select_type(const char *input, va_list arg, t_flags *s_list);
void			ft_ischar(va_list arg, t_flags *s_list);
void			ft_is_string(va_list arg, t_flags *s_list);
void			ft_string_legth(t_flags *s_list, char *s);
void			ft_string_right(t_flags *s_list, char *s);
void			ft_writeblanks(int n);
void			ft_writezeros(int n);
void			ft_initial_struct(t_flags *s_list);
void			ft_reset_struct(t_flags *s_list);

char		*ft_strcpy(char *dst, const char *src);
char		*ft_strdup(const char *s1);
int	ft_isdigit(int c);
int	ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
void	ft_putstr_fd(char *s, int fd);


#endif
