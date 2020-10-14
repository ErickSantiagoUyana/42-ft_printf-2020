/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 16:56:17 by euyana-b          #+#    #+#             */
/*   Updated: 2020/10/14 16:45:03 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ischar(unsigned char c, t_flags *s_list)
{
	if (s_list->width > 0)
	{
		if (s_list->minus == 1)
		{
			write(1, &c, 1);
			ft_writespaces(s_list->width - 1);
		}
		else	if (s_list->zero == 1)
		{
			ft_writezeros(s_list->width - 1);
			write(1, &c, 1);
		}
		else
		{
			ft_writespaces(s_list->width - 1);
			write(1, &c, 1);
		}
		s_list->n_print = s_list->n_print + s_list->width;
	}
	else
	{
		write(1, &c, 1);
		s_list->n_print++;
	}
}
