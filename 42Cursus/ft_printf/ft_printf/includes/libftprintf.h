/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:44:46 by mafzal            #+#    #+#             */
/*   Updated: 2025/02/18 21:37:53 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_specifiers(va_list ap, char c);
int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_putnbr(long int n);
int	ft_puthex(unsigned long int n, char c);
int	ft_putptr(void *ptr);

#endif