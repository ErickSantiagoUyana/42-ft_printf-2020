/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_auxiliaries.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 23:30:25 by euyana-b          #+#    #+#             */
/*   Updated: 2020/11/06 23:24:49 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_writespaces(int n)
{
	int aux;

	aux = 0;
	while (n > 0)
	{
		write(1, " ", 1);
		n--;
		aux++;
	}
	return (aux);
}

int		ft_writezeros(int n)
{
	int aux;

	aux = 0;
	while (n > 0)
	{
		write(1, "0", 1);
		n--;
		aux++;
	}
	return (aux);
}

void	ft_initial_struct(t_flags *s_list)
{
	s_list->pos = 0;
	s_list->n_print = 0;
	s_list->minus = 0;
	s_list->zero = 0;
	s_list->hash = 0;
	s_list->w_flag = 0;
	s_list->width = 0;
	s_list->p_flag = 0;
	s_list->p_width = -1;
	s_list->is_neg = 0;
}

void	ft_reset_struct(t_flags *s_list)
{
	s_list->minus = 0;
	s_list->zero = 0;
	s_list->hash = 0;
	s_list->w_flag = 0;
	s_list->width = 0;
	s_list->p_flag = 0;
	s_list->p_width = -1;
	s_list->is_neg = 0;
}
