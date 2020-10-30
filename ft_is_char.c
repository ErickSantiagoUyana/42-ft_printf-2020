/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 16:56:17 by euyana-b          #+#    #+#             */
/*   Updated: 2020/10/30 17:15:08 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_is_char(unsigned char c, t_flags *s_list)
{
	int aux;

	aux = 0;
	if (s_list->w_flag == 1)
	{
		if (s_list->minus == 1)
		{
			write(1, &c, 1);
			aux = ft_writespaces(s_list->width - 1) + 1;
		}
		else
		{
			if (s_list->zero == 1)
			{
				aux = ft_writezeros(s_list->width - 1) + 1;
				write(1, &c, 1);
			}
			else
			{	aux = ft_writespaces(s_list->width - 1) + 1;
				write(1, &c, 1);
			}
		}
	}
	else
	{
		write(1, &c, 1);
		s_list->n_print++;
	}
	s_list->n_print += aux;
}
