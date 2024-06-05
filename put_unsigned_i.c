/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_i.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dianakolopenyuk <dianakolopenyuk@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:25:06 by dkolopen          #+#    #+#             */
/*   Updated: 2024/06/05 13:55:44 by dianakolope      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_unsigned_int(unsigned int nb)
{
	int		len;

	len = 0;
	if (nb <= 9)
		len += print_char(nb % 10 + '0');
	else
	{
		len = put_unsigned_int(nb / 10);
		len += print_char(nb % 10 + '0');
	}
	return (len);
}
