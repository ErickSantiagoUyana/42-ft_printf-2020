/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ischar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 16:56:17 by euyana-b          #+#    #+#             */
/*   Updated: 2020/10/05 21:57:11 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int ft_ischar(char c, va_list arg_list, t_flags *s_list)
{  
    ft_putchar_fd(va_arg(arg_list,int),1);
    //falta sumar el valor que se pinto
    return (1);
}