/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolopen <dkolopen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:57:24 by dkolopen          #+#    #+#             */
/*   Updated: 2024/05/17 15:31:12 by dkolopen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_specifier(char specifier, va_list args)
{
	int	counter;

	counter = 0;
	if (specifier == 'c')
		counter = print_char(va_arg(args, int));
	else if (specifier == 's')
		counter = print_string(va_arg(args, char *));
	else if (specifier == 'p')
		counter = put_pointer(va_arg(args, unsigned long));
	else if (specifier == 'd' || specifier == 'i')
		counter = put_nb(va_arg(args, int));
	else if (specifier == 'u')
		counter = print_unsigned_int(va_arg(args, int));
	else if (specifier == 'x' || specifier == 'X')
		counter = put_hex(va_arg(args, int), specifier);
	else if (specifier == '%')
		counter = print_char('%');
	return (counter);
}

int	parse_str(const char *format_str, va_list args)
{
	int		i;
	char	*start;
	int		counter;

	start = (char *)format_str;
	counter = 0;
	i = 0;
	while (start[i] != '\0')
	{
		if (start[i] == '%')
		{
			start++;
			counter += handle_specifier(start[i], args);
		}
		else
			print_char(start[i]);
		i++;
	}
	return (counter);
}
