/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dianakolopenyuk <dianakolopenyuk@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:21:51 by dkolopen          #+#    #+#             */
/*   Updated: 2024/06/05 14:17:41 by dianakolope      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		result;

	va_start (args, str);
	result = parse_str(str, args);
	va_end (args);
	return (result);
}

// int	main()
// {
// 	// int		*ptr;
// 	// int		i;
	
// 	// i = 27;
// 	// ptr = &i;
// 	// printf("Result: %d %c %s %% %X %x %p %i %u\n", 7, 'c', "string", 15, 12345, ptr, 44,956);
// 	// ft_printf("Result: %d %c %s %% %X %x %p %i %u\n", 7, 'c', "string", 15, 12345, ptr, 44,956);
// 	printf("Result printf: %p", 0);
// 	printf("\n");
// 	ft_printf("Result ft_printf: %p", 0);
// 	return 0;
// }
