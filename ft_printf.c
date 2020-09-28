/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erick <erick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 13:22:37 by euyana-b          #+#    #+#             */
/*   Updated: 2020/09/28 21:50:19 by erick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> 
#include <stdarg.h>
#include <stdio.h>

# include <stdlib.h>
#define ALLSYMBOLS "cspdiouxXfy%#-+ .*0123456789hLljz"


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
/*int ft_save(const char *input, t_flags *s_list,int pos)
{


	while (input[pos] !=  '\0')
	{
		if(input[pos] != '%' && input[pos])
		{ 
			s_list->nprint += write(1, &input[pos],1);
		}
		else if(input[pos] == '%')
		{
				if(!ft_strchr(ALLSYMBOLS,input[pos+1]))
				{

				}
				
				while(ft_strchr(ALLSYMBOLS,input[pos+1]))
				{
					pos+=1;
					

				}
				
		}
		pos++;
	}

	return(s_list->nprint);
}*/

int	ft_printf(const char *input, ...)
{
	//const char	*save;
	va_list	arg_list;
	t_flags *s_list;

	int			pos;
	pos = 0;
	//save = ft_strdup(input);
	if (!(s_list = (t_flags*)malloc(sizeof(t_flags))))
		return (0);

	
	va_start(arg_list, input);	
	
	ft_save(input,s_list,pos);
	
	va_end(arg_list);
	free(s_list);
	return (1);
}