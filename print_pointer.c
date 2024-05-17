/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolopen <dkolopen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:11:42 by dkolopen          #+#    #+#             */
/*   Updated: 2024/05/17 13:40:52 by dkolopen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(unsigned long ptr)
{
	unsigned long	nb;
	int				len;

	nb = ptr;
	len = 0;
	if (nb >= 16)
	{
		len += print_pointer(nb / 16);
		len += print_pointer(nb % 16);
	}
	else
	{
		if (nb <= 9)
		{
			print_char((nb + '0'));
		}
		else
		{
			print_char((nb - 10 + 'a'));
		}
		len++;
	}
	return (len);
}

int	put_pointer(unsigned long ptr)
{
	int	count;

	count = 0;
	if (ptr == 0)
	{
		print_string("(nil)");
		return (5);
	}
	print_string("0x");
	count += 2;
	count += print_pointer(ptr);
	return (count);
}
