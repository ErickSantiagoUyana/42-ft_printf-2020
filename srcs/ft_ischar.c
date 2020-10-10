/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ischar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 16:56:17 by euyana-b          #+#    #+#             */
/*   Updated: 2020/10/11 00:33:19 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_ischar(va_list arg, t_flags *s_list)
{
	unsigned char	c;
	//write(1,"k", 1);

	printf("-%i- ",s_list->width);
	c = (unsigned char)va_arg(arg, int);
	if (s_list->width > 0)
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
		{
			ft_writeblanks(s_list->width - 1);
			write(1, &c, 1);
		}
		s_list->n_print = s_list->n_print + s_list->width;
	}
	else
	{
		write(1, &c, 1);
		s_list->n_print++;
	}
	//printf("- %i -", s_list->n_print);
}
