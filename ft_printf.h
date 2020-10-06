/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 11:48:46 by euyana-b          #+#    #+#             */
/*   Updated: 2020/10/06 19:45:26 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include <stdarg.h>
#include <unistd.h>
#include "libft/libft.h"
#define ALLSYMBOLS "cspdiuxX%-.*0123456789"

typedef	struct		s_flags
{
	int pos;
	int n_print;
	int minus;
	int zero;
	int hash;
	int width;
	int precision;
	int precisiontf;
}					t_flags;

int		ft_breakdown(const char *input, t_flags *s_list, va_list arg_list);
void	ft_ischar(t_flags *f, va_list ap);
void	ft_analyser_fwpl(const char *input, va_list arg_list, t_flags *s_list);
void	ft_conversion(const char *input, va_list arg_list, t_flags *s_list);

#endif
