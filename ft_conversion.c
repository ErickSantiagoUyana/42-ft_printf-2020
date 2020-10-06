/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 16:19:35 by euyana-b          #+#    #+#             */
/*   Updated: 2020/10/05 22:05:11 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

 void f_flags(const char *input,t_flags *s_list)
 {
        while (ft_strchr("-+ #0", input[s_list->pos]))
	{
         if(input[s_list->pos] == '-')
                s_list->minus = 1;
         if(input[s_list->pos] == 0)
                s_list->zero = 1;
                
           s_list->pos++;
        }
 }

void ft_analyser_fwpl(const char *input, va_list arg_list, t_flags *s_list)
{
        //f_flags(input,s_list);

}



void	ft_conver(char c, va_list arg_list, t_flags *s_list)
{
        if (c == 'c')
        ft_ischar(c,arg_list,s_list);
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