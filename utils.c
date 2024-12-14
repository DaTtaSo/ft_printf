/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbedouan <nbedouan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 00:52:17 by nbedouan          #+#    #+#             */
/*   Updated: 2024/12/14 03:31:06 by nbedouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i])
		ft_putchar(str[i++]);
	return (i);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putnbr_base(ssize_t nb, char *base, int *count)
{
	int	b_len;

	if (!base || !count)
		return ;
	b_len = ft_strlen(base);
	if (nb < 0)
	{
		nb *= -1;
		*count += ft_putchar('-');
	}
	if (nb >= b_len)
	{
		ft_putnbr_base(nb / b_len, base, count);
		ft_putnbr_base(nb % b_len, base, count);
	}
	else
		*count += ft_putchar(base[nb]);
}

void	ft_putnbr_lb(unsigned long nb, char *base, int *count)
{
	unsigned long long	b_len;

	if (!base || !count)
		return ;
	b_len = ft_strlen(base);
	if (b_len < 2)
		return ;
	if (nb >= b_len)
	{
		ft_putnbr_lb(nb / b_len, base, count);
		ft_putnbr_lb(nb % b_len, base, count);
	}
	else
		*count += ft_putchar(base[nb]);
}
