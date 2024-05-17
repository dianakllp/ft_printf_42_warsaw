/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_i.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolopen <dkolopen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:25:06 by dkolopen          #+#    #+#             */
/*   Updated: 2024/05/17 13:35:58 by dkolopen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsigned_int(unsigned int nb)
{
	int		counter;
	char	c;

	counter = 0;
	if (nb > 9)
		print_unsigned_int(nb / 10);
	c = (nb % 10) + '0';
	counter += write(1, &c, 1);
	return (counter);
}
