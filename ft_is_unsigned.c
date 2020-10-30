/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 15:09:59 by euyana-b          #+#    #+#             */
/*   Updated: 2020/10/30 12:58:03 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_is_unsigned(va_list arg, t_flags *s_list)
{
	char *aux;
	unsigned int	unsig;

	unsig = (unsigned int)va_arg(arg, int);
	aux = ft_itoa_baseX(unsig,10);

	if (s_list->minus == 1)
		ft_putstr_int_m(s_list,aux);
	else
		ft_putstr_int_z_n(s_list, aux);
	free(aux);
}
