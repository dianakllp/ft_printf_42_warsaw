/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dianakolopenyuk <dianakolopenyuk@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:07:07 by dkolopen          #+#    #+#             */
/*   Updated: 2024/06/05 13:51:15 by dianakolope      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>	

int		ft_printf(const char *str, ...);
int		parse_str(const char *format_str, va_list args);
int		put_hex(unsigned int nb, const char x);
int		put_pointer(unsigned long long ptr);
int		print_char(int c);
int		print_string(char *str);
int		put_nb(int n);
int		put_unsigned_int(unsigned int nb);
void	print_hex(unsigned int nb, const char x);

#endif
