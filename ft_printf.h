/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 11:48:46 by euyana-b          #+#    #+#             */
/*   Updated: 2020/10/02 16:57:30 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include <stdarg.h>
#include "libft/libft.h"

typedef	struct		s_flags
{
	char *format;
	int nprint;
	int i;
	int len;
	int minus;
	int plus;
	int space;
	int zero;
	int hash;
}					t_flags;

void	conver(char c, va_list ap, t_flags *f);
int ischar(char c, va_list ap, t_flags *f);


#endif
