/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_breakdown.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 23:59:48 by euyana-b          #+#    #+#             */
/*   Updated: 2020/10/14 16:45:03 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_breakdown(const char *input, va_list arg, t_flags *s_list)
{
	while (input[s_list->pos] != '\0')
	{
		if (input[s_list->pos] == '%')
		{
			s_list->pos++;
			if (ft_strchr(ALLSYMBOLS, input[s_list->pos]))
			{	//write(1, &input[s_list->pos], 1);
				if (ft_strchr("cspdiuxX%", input[s_list->pos]))
				{	ft_select_type(input, arg, s_list);
					//write(1, &input[s_list->pos], 1);
				}
				else
				{
					//write(1, &input[s_list->pos], 1);
					ft_format(input, arg, s_list);
					ft_select_type(input, arg, s_list);
					ft_reset_struct(s_list);
					//write(1, &input[s_list->pos], 1);
				}
			}
		}
		if (input[s_list->pos] != '\0' && input[s_list->pos] != '%')
		{
			s_list->n_print += write(1, &input[s_list->pos], 1);
			s_list->pos++;
		}
	}
	return (s_list->n_print);
}
