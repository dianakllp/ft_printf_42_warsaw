/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dianakolopenyuk <dianakolopenyuk@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:57:24 by dkolopen          #+#    #+#             */
/*   Updated: 2024/06/05 13:57:26 by dianakolope      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_str(const char *format_str, va_list args)
{
	int		i;
	char	*start;
	int		counter;
	char 	specifier;

	start = (char *)format_str;
	counter = 0;
	i = 0;
	while (start[i] != '\0')
	{
		if (start[i] == '%')
		{
			i++;
			specifier = start[i];
	
			if (specifier == 'c')
				counter += print_char(va_arg(args, int));
			else if (specifier == 's')
				counter += print_string(va_arg(args, char *));
			else if (specifier == 'p')
				counter += put_pointer(va_arg(args, unsigned long long));
			else if (specifier == 'd' || specifier == 'i')
				counter += put_nb(va_arg(args, int));
			else if (specifier == 'u')
				counter += put_unsigned_int(va_arg(args, int));
			else if (specifier == 'x' || specifier == 'X')
				counter += put_hex(va_arg(args, int), specifier);
			else if (specifier == '%')
				counter += print_char('%');
			// counter += handle_specifier(start[i], args);
		}
		else
			counter += print_char(start[i]);
		i++;
	}
	return (counter);
}
