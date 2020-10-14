/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_auxiliaries.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b ∫ <euyana-b@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 23:32:43 by euyana-b          #+#    #+#             */
/*   Updated: 2020/10/14 21:38:47 by euyana-b ∫       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
char		*ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char		*ft_strdup(const char *s1)
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

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (*str++ != '\0')
		i++;
	return (i);
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

void	ft_putstr_fd(char *s, int fd)
{
	if ((s))
		write(fd, s, ft_strlen(s));
}
