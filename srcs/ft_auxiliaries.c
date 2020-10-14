/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_auxiliaries.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 23:30:25 by euyana-b          #+#    #+#             */
/*   Updated: 2020/10/12 17:36:00 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_writespaces(int n)
{
	while (n > 0)
	{
		write(1, " ", 1);
		n--;
	}
}

void	ft_writezeros(int n)
{
	while (n > 0)
	{
		write(1, "0", 1);
		n--;
	}
}

void	ft_initial_struct(t_flags *s_list)
{
	s_list->pos = 0;
	s_list->n_print = 0;
	s_list->minus = 0;
	s_list->zero = 0;
	s_list->hash = 0;
	s_list->width = 0;
	s_list->p_flag = 0;
	s_list->p_width = 0;
}

void	ft_reset_struct(t_flags *s_list)
{
	s_list->minus = 0;
	s_list->zero = 0;
	s_list->hash = 0;
	s_list->width = 0;
	s_list->p_flag = 0;
	s_list->p_width = 0;
}
