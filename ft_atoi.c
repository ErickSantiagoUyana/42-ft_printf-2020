/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 20:55:42 by erickuyana        #+#    #+#             */
/*   Updated: 2020/10/30 12:09:02 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *str)
{
	long int	result;
	int			i;
	int			count;
	int			sign;

	result = 0;
	i = 0;
	count = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\f' ||
			str[i] == '\r' || str[i] == '\n' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (ft_isdigit(str[i + count]))
	{
		result = result * 10 + str[i + count] - '0';
		count++;
	}
	if (count > 18 && sign > 0)
		return (-1);
	if (count > 18 && sign < 0)
		return (0);
	return (sign * result);
}
