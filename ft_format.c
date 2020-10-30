/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 16:19:35 by euyana-b          #+#    #+#             */
/*   Updated: 2020/10/30 19:07:05 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flags(const char *input, t_flags *s_list)
{
	while (ft_strchr("-0", input[s_list->pos]))
	{
		if (input[s_list->pos] == '-')
			s_list->minus = 1;
		if (input[s_list->pos] == '0')
			s_list->zero = 1;
		s_list->pos++;
	}
	if (s_list->minus == 1)
		s_list->zero = 0;
}

void	ft_widthstart(const char *input, va_list arg, t_flags *s_list)
{
	if (input[s_list->pos] == '*')
	{
		s_list->width = va_arg(arg, int);
		s_list->w_flag = 1;
		if (s_list->width < 0)
		{
			s_list->minus = 1;
			s_list->width = -(s_list->width);
		}
		while (input[s_list->pos] == '*')
			s_list->pos++;
	}
}

void	ft_width(const char *input, va_list arg, t_flags *s_list)
{
	ft_widthstart(input, arg, s_list);
	if (input[s_list->pos] >= '0' && input[s_list->pos] <= '9')
	{
		s_list->width = ft_atoi(&input[s_list->pos]);
		s_list->w_flag = 1;
		while (input[s_list->pos] >= '0' && input[s_list->pos] <= '9')
		{
			s_list->pos++;
			if (input[s_list->pos] == '*')
			{
				if (s_list->width < 0)
				{
					s_list->minus = 1;
					s_list->width = -(s_list->width);
				}
				while (input[s_list->pos] == '*')
					s_list->pos++;
			}
		}
	}
}

void	ft_precision(const char *input, va_list arg, t_flags *s_list)
{
	int aux;

	if (input[s_list->pos] == '.')
	{
		s_list->pos++;
		s_list->p_flag = 1;
		if (input[s_list->pos] >= '0' && input[s_list->pos] <= '9')
		{
			s_list->p_width = ft_atoi(&input[s_list->pos]);
			while (input[s_list->pos] >= '0' && input[s_list->pos] <= '9')
				s_list->pos++;
		}
		else if (input[s_list->pos] == '*')
		{
			aux = va_arg(arg, int);
			s_list->p_width = aux;
			if (aux < 0)
			{
				s_list->p_flag = 0;
			}
			while (input[s_list->pos] == '*')
				s_list->pos++;
		}
	}
}

void	ft_format(const char *input, va_list arg, t_flags *s_list)
{
	ft_flags(input, s_list);
	ft_width(input, arg, s_list);
	ft_precision(input, arg, s_list);
}
