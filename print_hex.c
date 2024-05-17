/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolopen <dkolopen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:11:18 by dkolopen          #+#    #+#             */
/*   Updated: 2024/05/17 13:32:46 by dkolopen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hex(unsigned int nb, const char x)
{
	if (nb >= 16)
	{
		print_hex(nb / 16, x);
		print_hex(nb % 16, x);
	}
	else
	{
		if (nb <= 9)
			print_char((nb + '0'));
		else
		{
			if (x == 'X')
				print_char((nb - 10 + 'A'));
			if (x == 'x')
				print_char((nb - 10 + 'a'));
		}
	}
}

int	put_hex(unsigned int nb, const char x)
{
	int	len;

	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	print_hex(nb, x);
	len = 0;
	while (nb != 0)
	{
		len++;
		nb = nb / 16;
	}
	return (len);
}
