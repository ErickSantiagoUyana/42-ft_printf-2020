/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ischar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 16:56:17 by euyana-b          #+#    #+#             */
/*   Updated: 2020/10/06 19:43:50 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	writeblanks(int n)
{
	while (n > 0)
	{
		write(1, " ", 1);
		n--;
	}
}

void	writezeros(int n)
{
	while (n > 0)
	{
		write(1, "0", 1);
		n--;
	}
}


void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}


void	ft_ischar(t_flags *f, va_list ap)
{
	int				num;
	unsigned char	c;

	num = 0;
	c = (unsigned char)va_arg(ap, int);
	if (f->width && f->minus == 0)
	{
		num = f->width - 1;
		if (f->zero != 0)
			writezeros(num);
		else if (f->zero == 0)
			writeblanks(num);
		write(1, &c, 1);
		//f->nprinted = f->nprinted + num;
	}
	else if (f->width && f->minus == 1)
	{
		num = f->width - 1;
		write(1, &c, 1);
		writeblanks(num);
		//f->nprinted = f->nprinted + num;
	}
	else
		write(1, &c, 1);
	//f->nprinted++;
}
