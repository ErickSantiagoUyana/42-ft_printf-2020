/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b ∫ <euyana-b@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 23:51:39 by euyana-b          #+#    #+#             */
/*   Updated: 2020/10/10 19:03:12 by euyana-b ∫       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_string_right(t_flags *s_list, char *s)
{
	int len;

	len = ft_strlen(s);
	if (s_list->width < len)
		ft_putstr_fd(s,len);
	else
	{
		if (s_list->zero == 1)
			ft_writezeros(s_list->width - len);
		else
			ft_writeblanks(s_list->width - len);
		ft_putstr_fd(s,1);
	}
	s_list->n_print =s_list->n_print + s_list->width;
}

void	ft_string_legth(t_flags *s_list, char *s)
{
	int len;

	len = ft_strlen(s);
	if (s_list->width < len)
		ft_putstr_fd(s,len);
	else
	{
		ft_putstr_fd(s,1);
		ft_writeblanks(s_list->width - len);
	}
	s_list->n_print =s_list->n_print + s_list->width;
}

void	ft_is_string(va_list arg, t_flags *s_list)
{
	char	*s;
	s = (char *)va_arg(arg, char *);
	if (s_list->width)
	{
		if (s_list->minus == 1)
		{
			ft_string_legth(s_list, s);
		}
		else if (s_list->zero == 1)
			{
				ft_string_right(s_list, s);
			}
			else
			{
				ft_string_right(s_list, s);
			}
	}
	else
	{
		ft_string_legth(s_list, s);
	}
}
