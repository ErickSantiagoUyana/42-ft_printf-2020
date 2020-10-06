/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 13:22:37 by euyana-b          #+#    #+#             */
/*   Updated: 2020/10/05 23:09:53 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> 
#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"
# include <stdlib.h>
#include "libft/libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
char	*ft_strdup(const char *s1)
{
	char	*d;
	int		i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	d = malloc(sizeof(char) * (i + 1));
	if (!(d))
		return (0);
	ft_strcpy(d, s1);
	return (d);
}
char	*ft_strchr(const char *s, int c)
{
	char *straux;

	straux = (char *)s;
	while (*straux != c)
	{
		if (*straux == '\0')
			return (0);
		straux++;
	}
	return (straux);
}

void ft_initial_struct(t_flags *s_list)
{
	s_list->pos = 0;
	s_list->n_print = 0;
	s_list->minus = 0;
	s_list->zero = 0;
	s_list->hash = 0;
	s_list->width = 0;
	s_list->precision = 0;
}


int ft_breakdown(const char *input, t_flags *s_list,va_list arg_list)
{

	while (input[s_list->pos] !=  '\0')
	{
		if(input[s_list->pos] == '%' && input[s_list->pos])
		{ 
			if(ft_strchr(ALLSYMBOLS,input[s_list->pos+1]))
			{
				if(ft_strchr("cspdiuxX%",input[s_list->pos+1]))
				{
				ft_conver((char)input[s_list->pos+1],arg_list,s_list);
				s_list->pos+=2;
				}
				else
				{	
				ft_analyser_fwpl(input,arg_list,s_list);
				}
			}
		}
		s_list->n_print += write(1, &input[s_list->pos],1);

		s_list->pos++;
	}

	return(s_list->pos);
}

int	ft_printf(const char *input, ...)
{
	const char	*save;
	va_list	arg_list;
	t_flags *s_list;
	save = ft_strdup(input);
	if (!(s_list = (t_flags*)malloc(sizeof(t_flags))))
		return (0);
	
	va_start(arg_list, input);
	ft_initial_struct(s_list);
	ft_breakdown(input,s_list,arg_list);
	
	va_end(arg_list);
	free(s_list);
	return (1);
}