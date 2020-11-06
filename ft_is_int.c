/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 19:46:55 by euyana-b          #+#    #+#             */
/*   Updated: 2020/11/06 13:12:04 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_int_aux_precision(t_flags *s_list, char *s)
{
	int aux;
	int len;

	aux = 0;
	len = ft_strlen(s);
	if (len == 1 && ft_atoi(s) == 0)
		len = 0;
	if (s_list->is_neg == 1)
		aux += write(1, "-", 1);
	aux += ft_writezeros(s_list->p_width - len);
	if (len != 0)
		aux += ft_putstr_fd(s, 1);
	return (aux);
}

int		ft_int_aux_z_n(t_flags *s_list, char *s, int len, int aux)
{
	if (len > s_list->p_width)
		aux += ft_writespaces(s_list->width - len - s_list->is_neg);
	else
		aux += ft_writespaces(s_list->width - s_list->p_width - s_list->is_neg);
	aux += ft_int_aux_precision(s_list, s);
	return (aux);
}

void	ft_putstr_int_z_n(t_flags *s_list, char *s)
{
	int aux;
	int len;

	aux = 0;
	len = ft_strlen(s);
	if (s_list->p_flag)
	{
		if (len == 1 && ft_atoi(s) == 0)
			len = 0;
		if (s_list->p_width > s_list->width)
			aux += ft_int_aux_precision(s_list, s);
		else
			aux += ft_int_aux_z_n(s_list, s, len, aux);
	}
	else
	{
		if (s_list->zero == 0)
			aux += ft_writespaces(s_list->width - len - s_list->is_neg);
		if (s_list->is_neg == 1)
			aux += write(1, "-", 1);
		if (s_list->zero)
			aux += ft_writezeros(s_list->width - len - s_list->is_neg);
		aux += ft_putstr_fd(s, 1);
	}
	s_list->n_print += aux;
}

void	ft_putstr_int_m(t_flags *s_list, char *s)
{
	int aux;

	aux = 0;
	if (s_list->p_flag)
	{
		aux += ft_int_aux_precision(s_list, s);
		aux += ft_writespaces(s_list->width - aux);
	}
	else
	{
		if (s_list->is_neg == 1)
			aux += write(1, "-", 1);
		aux += ft_putstr_fd(s, 1);
		aux += ft_writespaces(s_list->width - aux);
	}
	s_list->n_print += aux;
}

void	ft_is_int(va_list arg, t_flags *s_list)
{
	char	*aux;
	int		number;

	number = va_arg(arg, int);
	if (number < 0)
	{
		aux = ft_itoa(number * -1);
		s_list->is_neg = 1;
	}
	else
		aux = ft_itoa(number);
	if (s_list->minus == 1)
		ft_putstr_int_m(s_list, aux);
	else
		ft_putstr_int_z_n(s_list, aux);
	free(aux);
}
