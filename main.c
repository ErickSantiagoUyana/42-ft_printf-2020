/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 14:09:13 by euyana-b          #+#    #+#             */
/*   Updated: 2020/10/02 17:36:07 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> 
#include "ft_printf.h"

int	ft_printf(const char *input, ...);

int main (){

    char i = 'x';
    int l = 99;
    long m = 123;

    ft_printf("\nAdios perchas %m %c %c %c como te fue", i ,l, m);
    
    printf("\nAdios perchas %70m %c %c %ld como te fue", i ,l,m);
    return (0);
}