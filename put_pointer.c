/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pointer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dianakolopenyuk <dianakolopenyuk@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:11:42 by dkolopen          #+#    #+#             */
/*   Updated: 2024/06/05 14:20:23 by dianakolope      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(unsigned long long ptr)
{
	int				len;

	len = 0;
	if (ptr >= 16) //If ptr is less than 16, it's small enough to be represented by a single hex digit.
	{
		len += print_pointer(ptr / 16); // So, we need to divide it by 16 to see how many "16s" fit into ptr(any number).
		len += print_pointer(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
		{
			print_char((ptr + '0'));
		}
		else
		{
			print_char((ptr - 10 + 'a'));
		}
		len++;
	}
	return (len);
}

int	put_pointer(unsigned long long ptr)
{
	int	count;

	count = 0;
	if (ptr == 0)
	{
 		count += write (1, "(nil)", 5);
        return (count);
	}
	count = write(1, "0x", 2);
	
	count += print_pointer(ptr);
	return (count);
}
