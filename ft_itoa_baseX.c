/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_baseX.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 13:43:26 by euyana-b          #+#    #+#             */
/*   Updated: 2020/10/30 17:50:26 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_baseX(uintmax_t value, uintmax_t base)
{
	char				*s;
	unsigned long long	n;
	int					i;

	i = 1;
	n = value;
	while ((n /= base) >= 1)
		i++;
	s = (char*)malloc(sizeof(char) * (i + 1));
	s[i] = '\0';
	n = value;
	while (i-- > 0)
	{
		s[i] = (n % base < 10) ? n % base + '0' : n % base + 'a' - 10;
		n /= base;
	}
	return (s);
}

char	*ft_itoa_base_upper(intmax_t value, intmax_t base)
{
	char				*s;
	long long			n;
	int					sign;
	int					i;

	n = (value < 0) ? -value : value;
	sign = (value < 0 && base == 10) ? -1 : 0;
	i = (sign == -1) ? 2 : 1;
	while ((n /= base) >= 1)
		i++;
	s = (char*)malloc(sizeof(char) * (i + 1));
	s[i] = '\0';
	n = (value < 0) ? -value : value;
	while (i-- + sign)
	{
		s[i] = (n % base < 10) ? n % base + '0' : n % base + 'A' - 10;
		n /= base;
	}
	(i == 0) ? s[i] = '-' : 0;
	return (s);
}

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

static	int	num_char(int n)
{
	int aux;

	aux = 0;
	if (!n)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		aux++;
	}
	return (aux);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = num_char(n);
	if (n < 0)
		i++;
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (0);
	if (n == -2147483648)
		return (ft_strcpy(str, "2147483648"));
	str[i] = '\0';
	if (!n)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		str[i - 1] = '0' + (n % 10);
		n = n / 10;
		i--;
	}
	return (str);
}
