/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ischar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 16:56:17 by euyana-b          #+#    #+#             */
/*   Updated: 2020/10/09 19:54:49 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ischar(va_list arg, t_flags *s_list)
{
	unsigned char	c;

	c = (unsigned char)va_arg(arg, int);
	if (s_list->width)
	{
		if (s_list->minus == 1)
		{
			write(1, &c, 1);
			ft_writeblanks(s_list->width - 1);
		}
		else	if (s_list->zero == 1)
		{
			ft_writezeros(s_list->width - 1);
			write(1, &c, 1);
		}
		else
			ft_writeblanks(s_list->width - 1);
	}
	else
		write(1, &c, 1);
	s_list->n_print = s_list->n_print + s_list->width;
}
