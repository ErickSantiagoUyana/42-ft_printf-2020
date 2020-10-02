/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 16:19:35 by euyana-b          #+#    #+#             */
/*   Updated: 2020/10/02 17:26:59 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	conver(char c, va_list arg_list, t_flags *s_list)
{
	
    write(1,"-",1);
    if (c == 'c')
        ischar(c,arg_list,s_list);
	else if (c == 's')
        write(1,&c,1);
	else if (c == 'p')
        write(1,&c,1);
	else if (c == 'd' || c == 'i')
        write(1,&c,1);
	else if (c == 'o')
        write(1,&c,1);
	else if (c == 'u')
        write(1,&c,1);
	else if (c == 'x' || c == 'X')
        write(1,&c,1);
	else if (c == 'f')
        write(1,&c,1);
	else if (c == '%')
        write(1,&c,1);
	else if (c == 'y')
        write(1,&c,1);
	else if (c == 'b')
        write(1,&c,1);
}