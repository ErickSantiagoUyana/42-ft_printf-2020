/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 14:09:13 by euyana-b          #+#    #+#             */
/*   Updated: 2020/10/06 20:02:25 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> 
#include "ft_printf.h"

int	ft_printf(const char *input, ...);

int main (){

    char i = 'X';
    char l = 'R';
    int m = 50;

    ft_printf("Adios perchas %*c como te fue", i,l);
    //ft_printf("\nCharacters: %c %c \n", 'a', 65);
    printf("\nAdios perchas %*c como te fue", i,l);
    return (0);
}
