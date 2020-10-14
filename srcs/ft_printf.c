/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 13:22:37 by euyana-b          #+#    #+#             */
/*   Updated: 2020/10/14 16:45:48 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *input, ...)
{
	va_list	arg;
	t_flags *s_list;
	int		aux;

	if (!(s_list = (t_flags*)malloc(sizeof(t_flags))))
		return (0);
	va_start(arg, input);
	ft_initial_struct(s_list);
	aux = ft_breakdown(input, arg, s_list);
	va_end(arg);
	free(s_list);
	return (aux);
}
