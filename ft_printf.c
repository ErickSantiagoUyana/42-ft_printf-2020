/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 13:22:37 by euyana-b          #+#    #+#             */
/*   Updated: 2020/09/18 13:24:58 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_printf(const char *input, ...)
{
	const char	*save;
	va_list		args;
	int			char_count;

	save = ft_strdup(input);
	char_count = 0;
	va_start(args, input);
	char_count += ft_treat_save(save, args);
	va_end(args);
	free((char *)save);
	return (char_count);
}