/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b ∫ <euyana-b@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 14:09:13 by euyana-b          #+#    #+#             */
/*   Updated: 2020/10/10 22:30:29 by euyana-b ∫       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	ft_printf(const char *input, ...);

int main (){

    char i = 'X';
    char l = 'R';
	char *j = "Bien y tu?";
    //int m = 50;

	int a;
	int b;

    a = ft_printf("hello %0.5c", i, l);
    //printf("\n");
    b = printf("hello %0.5c", i , l);
	printf("\n");
	printf("A = %i  B = %i", a, b);
	printf("\n");
	//ft_printf("%09s",j);
	//printf("\n");
	//printf("%09s",j);

    return (0);
}
