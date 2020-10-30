/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_unsignedHx.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 12:33:21 by euyana-b          #+#    #+#             */
/*   Updated: 2020/10/30 13:09:33 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_is_unsignedHx(va_list arg, t_flags *s_list, char pos)
{
	char *aux;
	unsigned int	pointer;

	pointer = (unsigned int)va_arg(arg, unsigned int);
	//s_list->n_print += 1;

	if (pos == 'x')
	{	
		aux = ft_itoa_baseX(pointer, 16);
		if (s_list->minus == 1)
		ft_putstr_int_m(s_list,aux);
		else
		ft_putstr_int_z_n(s_list, aux);
	}
	else
	{
		aux = ft_itoa_base_upper(pointer, 16);
		//write(1,"-",1);
		//ft_putstr_fd(aux,1);
		//write(1,"-",1);
		if (s_list->minus == 1)
		ft_putstr_int_m(s_list,aux);
		else
		ft_putstr_int_z_n(s_list, aux);
	}
	free(aux);
}
