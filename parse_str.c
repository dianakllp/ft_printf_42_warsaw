/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolopen <dkolopen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:57:24 by dkolopen          #+#    #+#             */
/*   Updated: 2024/04/09 11:36:35 by dkolopen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"
#include "ft_printf.h"

int print_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}
int print_string(char *str)
{
	int counter;
	
	counter = 0;
	while (*str != '\0')
	{
		ft_putchar_fd(*str, 1);
		str++;
		counter++;
	}
	return (counter);
}
int print_pointer(const void *ptr)
{
	const char *charPtr;
	int i;
	int counter;
	
	charPtr = (const char *) ptr;
	i = 0; 
	while(charPtr[i] != '\0')
	{
		printf("%c", charPtr[i]);
		counter++;
	} 
	return(counter); 
}

int print_int(int numb)
{
	char *str;
	str = ft_itoa(numb);
	int counter;

	counter = 0;
	while (*str != '\0')
	{
		ft_putchar_fd(*str, 1);
		str++;
		counter++;
	}
	return(counter);
}

int print_unsigned_int(unsigned int nb) 
{
	int counter;
	char buffer[30];

	counter = 0;
	while (nb != 0) 
	{
		int digit;
		int counter;
		
		digit = nb % 10;
		buffer[counter] = digit + '0';
		write(1, &buffer[counter], 1);
		nb /= 10;
		counter++;
	}
	return (counter);
}

int print_hex(int nb, int toupper)
{
	char buffer[30];
	int counter;
	int digit;

	counter = 0;
	while (nb != 0)
	{
		digit = nb % 16;
		if (digit < 10)
		{
			buffer[counter] = digit + '0'; // It is just digit from one to 10, so Convert the digit to ASCII and store it
		}
		else 
		{
			buffer[counter] = digit - 10 + 'A';
		}
		nb /= 16;
		counter++;
	}
	buffer[counter] = '\0';
	counter = ft_strlen(buffer);
	while (counter != 0)
	{
		ft_putchar_fd(buffer[counter - 1] + toupper * 40, 1);
		counter--; 
	}
	return(ft_strlen(buffer));
}

int	handle_specifier(char specifier, va_list args)
{
	int counter;

	counter = 0;
	//if(format_str[i + 1] == ) //check for modifiers (like width, precision, flags, etc.).
	//{ Store this information for later use }
	if (specifier == 'c')
	{
		counter = print_char(va_arg(args, int));
	}
	else if (specifier == 's')
	{
		counter = print_string(va_arg(args, char *));
	}
	else if (specifier == 'p')
	{
		counter = print_pointer(va_arg(args, char *));
	}
	else if (specifier == 'd')
	{
		counter = print_int (va_arg(args, int)); 
	}
	else if (specifier == 'i')
	{
		counter = print_int(va_arg(args, int)); 
	}
	else if(specifier == 'u')
	{
		counter = print_unsigned_int(va_arg(args, int));
	}
	else if (specifier == 'x' || specifier == 'X')
	{
		counter = print_hex(va_arg(args, int), specifier == 'X');
	}
	else if (specifier == '%')
	{
		counter = print_char(va_arg(args, int));
	}
	else 
	{
		counter = print_char(specifier);
	}
	return(counter);
}

int	parse_str(const char *format_str, va_list args)
{
	char	*start = (char *)format_str;
	char	*print_text;
	int 	counter;

	counter = 0; 
	while (*start != '\0')
	{
		if (*start == '%')
		{
			start++;
			counter += handle_specifier(*start, args);
			return (counter);
		}
	}
	return(counter);
}
