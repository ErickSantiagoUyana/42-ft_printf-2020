/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erick <erick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 22:06:04 by erickuyana        #+#    #+#             */
/*   Updated: 2019/12/03 12:08:03 by erick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if ((s))
	{
		while (*s)
		{
			write(fd, s, sizeof(*s));
			s++;
		}
		write(fd, "\n", 1);
	}
}