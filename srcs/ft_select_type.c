/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 13:52:46 by euyana-b          #+#    #+#             */
/*   Updated: 2020/10/14 16:45:03 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_select_type(const char *input, va_list arg, t_flags *s_list)
{
	//write(1, &input[s_list->pos], 1);
	if (input[s_list->pos] == 'c')
		ft_ischar((unsigned char)va_arg(arg, int), s_list);
	if (input[s_list->pos] == 's')
		ft_is_string(arg, s_list);
	if (input[s_list->pos] == '%')
		ft_ischar('%', s_list);
	if (input[s_list->pos] == '\0')
		s_list->pos--;
	s_list->pos++;
}
