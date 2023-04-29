/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:51:02 by isibio            #+#    #+#             */
/*   Updated: 2022/12/07 15:51:03 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_fprintf.h"

int	fp_flag_d(int fd, int number);
int	fp_flag_i(int fd, int number);
int	fp_flag_u(int fd, unsigned int number);
int	ft_putnbr(int fd, int n);
int	ft_putunbr(int fd, unsigned int n);

int	fp_flag_d(int fd, int number)
{
	int		res;

	res = ft_putnbr(fd, number);
	return (res);
}

int	fp_flag_i(int fd, int number)
{
	int		res;

	res = ft_putnbr(fd, number);
	return (res);
}

int	fp_flag_u(int fd, unsigned int number)
{
	int	res;

	res = ft_putunbr(fd, number);
	return (res);
}

int	ft_putnbr(int fd, int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		i += ft_putnbr(fd, n / 10);
		ft_putchar_fd('8', fd);
		i++;
		return (i);
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		i++;
		i += ft_putnbr(fd, n * -1);
		return (i);
	}
	if (n >= 10)
		i += ft_putnbr(fd, n / 10);
	ft_putchar_fd(n % 10 + '0', fd);
	i++;
	return (i);
}

int	ft_putunbr(int fd, unsigned int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		i++;
		i += ft_putnbr(fd, n * -1);
		return (i);
	}
	if (n >= 10)
		i += ft_putnbr(fd, n / 10);
	ft_putchar_fd(n % 10 + '0', fd);
	i++;
	return (i);
}
