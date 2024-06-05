/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dianakolopenyuk <dianakolopenyuk@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:24:59 by dkolopen          #+#    #+#             */
/*   Updated: 2024/06/04 14:52:27 by dianakolope      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	print_string(char *str)
{
	int	len;

	len = 0;
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}
