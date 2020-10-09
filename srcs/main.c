/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 14:09:13 by euyana-b          #+#    #+#             */
/*   Updated: 2020/10/09 22:08:20 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> 
#include "ft_printf.h"

int	ft_printf(const char *input, ...);

int main (){

    char i = 'X';
    char l = 'R';
	char *j = "PENYLUU";
    //int m = 50;

	int a;
	int b;

    a = ft_printf("hello perchas %-20c %020mc how are you", i,l);
    printf("\n");
    b = printf("hello perchas %-20c %c how are you", i,l);
	printf("\n");
	printf("A = %i  B = %i", a, b);
	printf("\n");
	ft_printf("%-10s %-10s",j,j);
	printf("\n");
	printf("%-10s %-10s",j, j );

    return (0);
}
