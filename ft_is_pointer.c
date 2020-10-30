/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 13:24:48 by euyana-b          #+#    #+#             */
/*   Updated: 2020/10/30 16:48:39 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
void	ft_putstr_pointer_m(t_flags *s_list, char *s)
{
int len;
	int aux; 

	len = ft_strlen(s);
	aux = 0;
	if (s_list->p_flag == 1 && s_list->p_width == 0)
		len = 0;
	write(1,"0x",2);
	if (s_list->p_flag == 1)
	{	
		if (s_list->p_width > 0)
		{	
			aux += ft_writezeros(s_list->p_width - len);
			aux += ft_putstr_fd(s,1);
		}
	}
	else
		aux += ft_putstr_fd(s,1);
	if (s_list->w_flag == 1 && s_list->p_flag < s_list->width)
	{
		if (s_list->p_flag < s_list->width && s_list->p_flag == 1)
			aux += ft_writespaces(s_list->width - (len + 2 + 0));
		else
			aux += ft_writespaces(s_list->width - (len + 2 + s_list->p_width));
	}
	s_list->n_print += aux + 2;
}

void	ft_putstr_pointer_z_n(t_flags *s_list, char *s)
{
	int len;
	int aux; 

	len = ft_strlen(s);
	aux = 0;
	if (s_list->p_flag == 1 && s_list->p_width == 0)
		len = 0;
	if (s_list->w_flag == 1 && s_list->p_flag < s_list->width)
	{
		if (s_list->p_flag < s_list->width && s_list->p_flag == 1)
			aux += ft_writespaces(s_list->width - (len + 2 + 0));
		else
			aux += ft_writespaces(s_list->width - (len + 2 + s_list->p_width));
	}
	write(1,"0x",2);
	if (s_list->p_flag == 1)
	{	
		if (s_list->p_width > 0)
		{	
			aux += ft_writezeros(s_list->p_width - len);
			aux += ft_putstr_fd(s,1);
		}
	}
	else
		aux += ft_putstr_fd(s,1);
	s_list->n_print += aux + 2;
}

void	ft_is_pointer(va_list arg, t_flags *s_list)
{
	char				*aux;
	unsigned long long	pointer;

	pointer = (unsigned long long)va_arg(arg, void *);
	aux = ft_itoa_baseX(pointer, 16);
	if (s_list->minus == 1)
		ft_putstr_pointer_m(s_list, aux);
	else
		ft_putstr_pointer_z_n(s_list, aux);
}
