/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 19:46:55 by euyana-b          #+#    #+#             */
/*   Updated: 2020/10/30 18:17:07 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putstr_sum(t_flags *s_list, char *s)
{
	int aux;
	int sum;

	aux = ft_strlen(s);
	sum = 0;
	if (s_list->is_negative == 1)
		sum++;
	if (aux < s_list->p_width)
		sum += s_list->p_width;
	else
		sum += aux;
	return (sum);
}

void	ft_putstr_int_z_n(t_flags *s_list, char *s)
{
	int len;
	int neg;

	len = ft_putstr_sum(s_list, s);
	neg = 0;
	if (s_list->p_width == 0 && s_list->p_flag == 1)
		len = 0;
	if (s_list->width > len)
	{
		if (s_list->zero == 1 && s_list->p_flag == 0)
		{
			if (s_list->is_negative == 1)
			{
				write(1, "-", 1);
				neg = 1;
			}
			ft_writezeros(s_list->width - len);
		}
		else
			ft_writespaces(s_list->width - len);
		s_list->n_print += s_list->width - len;
	}
	if (s_list->is_negative == 1 && neg == 0)
		write(1, "-", 1);
	ft_putstr_p(s_list, s);
}

int		ft_putstr_p(t_flags *s_list, char *s)
{
	int aux;
	int sum;

	aux = ft_strlen(s);
	sum = 0;
	if (s_list->is_negative == 1)
		sum++;
	if (aux < s_list->p_width)
	{
		ft_writezeros(s_list->p_width - aux);
		write(1, s, aux);
		sum += s_list->p_width;
	}
	else
	{
		if (s_list->p_flag == 1 && s_list->p_width == 0)
		{
			if (s_list->width == 1)
				write(1, " ", aux);
			aux = 0;
		}
		else
			write(1, s, aux);
		sum += aux;
	}
	s_list->n_print += sum;
	return (sum);
}

void	ft_putstr_int_m(t_flags *s_list, char *s)
{
	int aux;

	aux = 0;
	if (s_list->is_negative == 1)
		write(1, "-", 1);
	aux = ft_putstr_p(s_list, s);
	ft_writespaces(s_list->width - aux);
	if (s_list->width - aux > 0)
		s_list->n_print += s_list->width - aux;
}

void	ft_is_int(va_list arg, t_flags *s_list)
{
	char	*aux;
	int		number;

	number = va_arg(arg, int);
	if (number < 0)
	{
		aux = ft_itoa(number * -1);
		s_list->is_negative = 1;
	}
	else
		aux = ft_itoa(number);
	if (s_list->minus == 1)
		ft_putstr_int_m(s_list, aux);
	else
		ft_putstr_int_z_n(s_list, aux);
	
	free(aux);
}
