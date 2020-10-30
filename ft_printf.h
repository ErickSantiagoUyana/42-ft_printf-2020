/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 11:48:46 by euyana-b          #+#    #+#             */
/*   Updated: 2020/10/30 17:45:38 by euyana-b         ###   ########.fr       */
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
	int			w_flag;
	int			width;
	int			p_flag;
	int			p_width;
	int			is_negative;
}				t_flags;

size_t			ft_strlen(const char *str);
char			*ft_strchr(const char *s, int c);
int				ft_putstr_fd(char *s, int fd);
int				ft_atoi(const char *str);
char			*ft_itoa_baseX(uintmax_t value, uintmax_t base);
char			*ft_itoa_base_upper(intmax_t value, intmax_t base);
char			*ft_itoa(int n);


int				ft_printf(const char *input, ...);
int				ft_breakdown(const char *input,  va_list arg, t_flags *s_list);
void			ft_format(const char *input, va_list arg, t_flags *s_list);
void			ft_precision(const char *input, va_list arg, t_flags *s_list);
void			ft_width(const char *input, va_list arg, t_flags *s_list);
void			ft_widthstart(const char *input, va_list arg, t_flags *s_list);
void			ft_flags(const char *input, t_flags *s_list);
void			ft_select_type(const char *input, va_list arg, t_flags *s_list);

void			ft_is_char(unsigned char	c, t_flags *s_list);

void			ft_is_string(va_list arg, t_flags *s_list);
void			ft_putstr_z_n(t_flags *s_list, char *s);
void			ft_putstr_minus(t_flags *s_list, char *s);
int				ft_p_flag(t_flags *s_list, char *s);
void			ft_caracter_sum(t_flags *s_list, int aux, int len);

void			ft_is_int(va_list arg, t_flags *s_list);
void			ft_putstr_int_z_n(t_flags *s_list, char *s);
int				ft_putstr_p(t_flags *s_list, char *s);
void			ft_putstr_int_m(t_flags *s_list, char *s);
int				ft_putstr_sum(t_flags *s_list, char *s);

void			ft_is_pointer(va_list arg, t_flags *s_list);
char			*ft_itoa_baseX(uintmax_t value, uintmax_t base);

void			ft_is_unsigned(va_list arg, t_flags *s_list);
void			ft_is_unsignedHx(va_list arg, t_flags *s_list, char pos);

int				ft_writespaces(int n);
int				ft_writezeros(int n);
void			ft_initial_struct(t_flags *s_list);
void			ft_reset_struct(t_flags *s_list);

#endif
