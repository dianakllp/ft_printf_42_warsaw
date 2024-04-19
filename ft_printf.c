/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolopen <dkolopen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:21:51 by dkolopen          #+#    #+#             */
/*   Updated: 2024/04/09 11:37:15 by dkolopen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// printf() returns the number of characters printed after successful execution.
// If an error occurs, a negative value is returned.
#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

int ft_printf(const char *str, ...) //printf(string format, items-to-format)
{
	va_list args;
	int result;
	
    va_start(args,str);
	result = parse_str(str, args); //inside should be the formating string 
	va_end(args);
	return(result);
}

int main()
{
	printf("Result: %d %c %s\n\n", 7, 'c', "string");
	ft_printf("Result: %d %c %s\n\n", 7, 'c', "string");
	return 0;
}
