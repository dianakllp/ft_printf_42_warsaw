/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolopen <dkolopen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:07:07 by dkolopen          #+#    #+#             */
/*   Updated: 2024/05/21 13:45:41 by dkolopen         ###   ########.fr       */
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
int		print_pointer(unsigned long ptr);
int		put_pointer(unsigned long ptr);
int		print_char(char c);
int		print_string(char *str);
int		put_nb(int n);
int		print_unsigned_int(unsigned int nb);
void	print_hex(unsigned int nb, const char x);

#endif
