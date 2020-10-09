/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 13:52:46 by euyana-b          #+#    #+#             */
/*   Updated: 2020/10/09 20:36:52 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_select_type(const char *input, va_list arg, t_flags *s_list)
{
	if (input[s_list->pos] == 'c')
		ft_ischar(arg, s_list);
	if (input[s_list->pos] == 's')
		ft_is_string(arg, s_list);
}
