/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbedouan <nbedouan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:55:34 by nbedouan          #+#    #+#             */
/*   Updated: 2024/12/14 03:34:08 by nbedouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

# define HEXA "0123456789abcdef"
# define UPHEXA "0123456789ABCDEF"

int		ft_printf(const char *format, ...);
int		ft_putchar(int c);
int		ft_putstr(const char *str);
void	ft_putnbr_base(ssize_t nb, char *base, int *count);
void	ft_putnbr_lb(unsigned long nb, char *base, int *count);
void	print_address(size_t ptr, int *count);
size_t	ft_strlen(const char *str);

#endif

g