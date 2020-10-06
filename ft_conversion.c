/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 16:19:35 by euyana-b          #+#    #+#             */
/*   Updated: 2020/10/06 20:05:49 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>


void	ft_flags(const char *input, t_flags *s_list)
{
	while (ft_strchr("-0", input[s_list->pos]))
	{
		if (input[s_list->pos] == '-')
			s_list->minus = 1;
		if (input[s_list->pos] == 0)
			s_list->zero = 1;
		s_list->pos++;
	}
	if (s_list->minus == 1)
		s_list->zero = 0;
}

void	ft_widthstart(const char *input, t_flags *s_list, va_list arg_list)
{
	if(input[s_list->pos] == '*')
	{
		s_list->width = va_arg(arg_list,int);
		if (s_list->width < 0)
		{
			s_list->minus = 1;
			s_list->width = -(s_list->width);
		}
		while (input[s_list->pos] == '*')
			s_list->pos++;
	}
}

void	ft_width(const char *input, t_flags *s_list, va_list arg_list)
{
	ft_widthstart(input, s_list, arg_list);
	if (input[s_list->pos] >= '0' && input[s_list->pos] <= '9')
	{
		s_list->width = atoi(&input[s_list->pos]);
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

void	ft_precision(const char *input, t_flags *s_list, va_list arg_list)
{
	int i;
	int p;

	p = 0;
	i = s_list->pos;
	if (input[i] == '.')
	{
		i++;
		s_list->precisiontf = 1;
		if (input[i] >= '0' && input[i] <= '9')
		{
			s_list->precision = atoi(&input[i]);
			while (input[i] >= '0' && input[i] <= '9')
				i++;
		}
		else if (input[s_list->pos] == '*')
		{
			p = va_arg(arg_list, int);
			if (p >= 0)
				s_list->precision = p;
			else if (p < 0)
				s_list->precisiontf = 0;
			while (input[s_list->pos] == '*')
				i++;
		}
	}
	s_list->pos = i;

}

void	ft_analyser_fwpl(const char *input, va_list arg_list, t_flags *s_list)
{
	ft_flags(input, s_list);
	ft_width(input, s_list, arg_list);
	ft_precision(input, s_list, arg_list);
}

void	ft_conversion(const char *input, va_list arg_list, t_flags *s_list)
{
	if (input[s_list->pos] == 'c')
		ft_ischar(s_list, arg_list);
}
