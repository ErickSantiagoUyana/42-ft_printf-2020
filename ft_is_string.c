/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 23:51:39 by euyana-b          #+#    #+#             */
/*   Updated: 2020/11/06 16:54:59 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_caracter_sum(t_flags *s_list, int aux, int len)
{
	if (s_list->p_flag)
	{
		if (s_list->width < aux)
			s_list->n_print += aux;
		else
			s_list->n_print += s_list->width;
	}
	else
	{
		if (s_list->width >= len)
			s_list->n_print += s_list->width;
		else
			s_list->n_print += len;
	}
}

int		ft_p_flag(t_flags *s_list, char *s)
{
	int aux;

	aux = 0;
	while (aux < s_list->p_width && s[aux] != '\0')
		aux++;
	return (aux);
}

void	ft_putstr_minus(t_flags *s_list, char *s)
{
	int aux;
	int len;

	aux = 0;
	len = ft_strlen(s);
	if (s_list->p_flag)
	{
		aux = ft_p_flag(s_list, s);
		write(1, s, aux);
		ft_writespaces(s_list->width - aux);
	}
	else
	{
		ft_putstr_fd(s, 1);
		ft_writespaces(s_list->width - len);
	}
	ft_caracter_sum(s_list, aux, len);
}

void	ft_putstr_z_n(t_flags *s_list, char *s)
{
	int aux;
	int len;

	aux = 0;
	len = ft_strlen(s);
	if (s_list->p_flag)
	{
		aux = ft_p_flag(s_list, s);
		if (s_list->zero)
			ft_writezeros(s_list->width - aux);
		else
			ft_writespaces(s_list->width - aux);
		write(1, s, aux);
	}
	else
	{
		if (s_list->zero)
			ft_writezeros(s_list->width - len);
		else
			ft_writespaces(s_list->width - len);
		ft_putstr_fd(s, 1);
	}
	ft_caracter_sum(s_list, aux, len);
}

void	ft_is_string(va_list arg, t_flags *s_list)
{
	char	*s;

	if ((s = (char *)va_arg(arg, char *)) == NULL)
	{
		if (s_list->minus)
			ft_putstr_minus(s_list, "(null)");
		else
			ft_putstr_z_n(s_list, "(null)");
	}
	else
	{
		if (s_list->minus)
			ft_putstr_minus(s_list, s);
		else
		{
			ft_putstr_z_n(s_list, s);
		}
	}
}
