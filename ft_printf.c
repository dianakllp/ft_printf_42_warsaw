/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolopen <dkolopen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:21:51 by dkolopen          #+#    #+#             */
/*   Updated: 2024/05/17 13:35:11 by dkolopen         ###   ########.fr       */
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

/*int	main()
{
	int		*ptr;
	int		i;
	
	i = 27;
	ptr = &i;
	printf("Result: %d %c %s %% %X %x %p %i %u\n", 7, 
	//'c', "string", 15, 12345, ptr, 44,956);
	ft_printf("Result: %d %c %s %% %X %x %p %i %u\n", 7,
	'c', "string", 15, 12345, ptr, 44,956);
	
	return 0;
}*/
