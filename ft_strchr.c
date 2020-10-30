/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:57:57 by euyana-b          #+#    #+#             */
/*   Updated: 2020/10/30 12:07:39 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
