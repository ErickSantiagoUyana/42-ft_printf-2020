/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base10.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b ∫ <euyana-b@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 21:42:52 by euyana-b ∫        #+#    #+#             */
/*   Updated: 2020/10/14 21:43:00 by euyana-b ∫       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */



#include "ft_printf.h"

int ft_count_numbers(int number)
{
	int cont;
	cont = 1;

	while (number >= 10)
	{
		number = number /10;
		cont = cont * 10;
	}
	return(cont);
}

int ft_len_int(int number)
{
	int cont;
	cont = 1;

	while (number >= 10)
	{
		number = number /10;
		cont++;
	}
	return(cont);
}

char*ft_itoa_base10(int number)
{
	char *str;
	char number_c;
	int cont;
	int i;

	i = 0;
	cont = ft_count_numbers(number);
	str = (char*)malloc(sizeof(char) * ft_len_int(number) + 1);
	while(cont > 1)
	{
		number_c = (number / cont) + '0';
		str[i++] = number_c;
		number_c = number +'0';
		number = number % cont;
		cont = cont / 10;
	}
		number_c = number+'0';
		str[i] = number_c;
		str[i + 1] = '\n';
	return(str);
}
