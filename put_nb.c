/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dianakolopenyuk <dianakolopenyuk@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:24:51 by dkolopen          #+#    #+#             */
/*   Updated: 2024/06/05 13:48:48 by dianakolope      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_int(int nb, int len)
{
	if (nb == -2147483648)
	{
		len += print_string("-2147483648");
		return (len);
	}
	else if (nb < 0)
	{
		len += print_char('-');
		len = print_int(-nb, len);
	}
	else if (nb >= 10)
	{
		len = print_int(nb / 10, len);
		len += print_char(nb % 10 + '0');
	}
	else
	{
		len += print_char(nb + '0');
	}
	return (len);
}

int	put_nb(int n)
{
	return (print_int(n, 0));
}
