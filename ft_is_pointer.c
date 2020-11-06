/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 13:24:48 by euyana-b          #+#    #+#             */
/*   Updated: 2020/11/06 22:26:03 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_pointer_aux_precision(t_flags *s_list, char *s)
{
	int aux;
	int len;

	aux = 0;
	len = ft_strlen(s);
	if (len == 1 && ft_atoi(s) == 0)
		len = 0;
	aux += ft_writezeros(s_list->p_width - len);
	if (len != 0)
		aux += ft_putstr_fd(s, 1);
	return (aux);
}

int		ft_pointer_aux_z_n(t_flags *s_list, char *s, int len, int aux)
{
	if (len == 1 && ft_atoi(s) == 0)
		len = 0;
	if (len > s_list->p_width)
		aux += ft_writespaces(s_list->width - len - 2);
	else
		aux += ft_writespaces(s_list->width - s_list->p_width - 2);
	aux += write(1, "0x", 2);
	aux += ft_pointer_aux_precision(s_list, s);
	return (aux);
}

void	ft_putstr_pointer_z_n(t_flags *s_list, char *s)
{
	int aux;
	int len;

	aux = 0;
	len = ft_strlen(s);
	if (s_list->p_flag)
	{
		if (s_list->p_width > s_list->width)
		{
			aux += write(1, "0x", 2);
			aux += ft_pointer_aux_precision(s_list, s);
		}
		else
			aux += ft_pointer_aux_z_n(s_list, s, len, aux);
	}
	else
	{
		if (s_list->zero == 0)
			aux += ft_writespaces(s_list->width - len - 2);
		aux += write(1, "0x", 2);
		if (s_list->zero)
			aux += ft_writezeros(s_list->width - len);
		aux += ft_putstr_fd(s, 1);
	}
	s_list->n_print += aux;
}

void	ft_putstr_pointer_m(t_flags *s_list, char *s)
{
	int aux;

	aux = 0;
	aux += write(1, "0x", 2);
	if (s_list->p_flag)
	{
		aux += ft_pointer_aux_precision(s_list, s);
		aux += ft_writespaces(s_list->width - aux);
	}
	else
	{
		aux += ft_putstr_fd(s, 1);
		aux += ft_writespaces(s_list->width - aux);
	}
	s_list->n_print += aux;
}

void	ft_is_pointer(va_list arg, t_flags *s_list)
{
	char				*aux;
	unsigned long long	pointer;

	pointer = (unsigned long long)va_arg(arg, void *);
	aux = ft_itoa_basex(pointer, 16);
	if (s_list->minus == 1)
		ft_putstr_pointer_m(s_list, aux);
	else
		ft_putstr_pointer_z_n(s_list, aux);
	free(aux);
}
