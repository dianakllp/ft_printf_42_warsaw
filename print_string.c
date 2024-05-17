/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolopen <dkolopen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:24:59 by dkolopen          #+#    #+#             */
/*   Updated: 2024/05/17 13:41:16 by dkolopen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(char *str)
{
	int	counter;

	counter = 0;
	while (*str != '\0')
	{
		print_char(*str);
		str++;
		counter++;
	}
	return (counter);
}
