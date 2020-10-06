/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 14:09:13 by euyana-b          #+#    #+#             */
/*   Updated: 2020/10/05 22:13:11 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> 
#include "ft_printf.h"

int	ft_printf(const char *input, ...);

int main (){

    char i = 'x';
    int l = 123;
    long m = 123;

    ft_printf("\n -0.*  0- Adios como %c %c te fue", i ,l, m);
    //ft_printf("\nCharacters: %c %c \n", 'a', 65);
    printf("\nAdios perchas %c %i14.9 como te fue", i ,l);
    return (0);
}