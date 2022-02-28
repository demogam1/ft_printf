/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 22:27:27 by haroun            #+#    #+#             */
/*   Updated: 2021/06/15 16:47:42 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, t_liste *tab, int fd)
{
	tab->len += write (fd, &c, 1);
}

void	ft_putnbr_fd(long long int n, t_liste *tab, int fd)
{
	unsigned int	nbr;

	if (n < 0)
	{
		ft_putchar_fd('-', tab, fd);
		nbr = (n * -1);
	}
	else
		nbr = n;
	if (nbr >= 10)
	{
		ft_putnbr_fd(nbr / 10, tab, fd);
		ft_putchar_fd((nbr % 10) + 48, tab, fd);
	}
	else
		ft_putchar_fd(nbr + 48, tab, fd);
}

void	ft_putstr_fd(char *s, t_liste *tab, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			ft_putchar_fd(s[i], tab, fd);
			i++;
		}
	}
}

void	ft_putnbr_u(unsigned int nb, t_liste *tab)
{
	if (nb >= 10)
	{
		ft_putnbr_u(nb / 10, tab);
		ft_putnbr_u(nb % 10, tab);
	}
	else
		ft_putchar_fd(nb + '0', tab, 1);
}

int	ft_putnbr_base(unsigned long nbr, t_liste *tab, char *base)
{
	unsigned long	len_base;

	len_base = ft_strlen(base);
	if (nbr < 0)
		nbr = nbr * -1;
	if (nbr >= len_base)
	{
		ft_putnbr_base(nbr / len_base, tab, base);
		ft_putchar_fd(base[nbr % len_base], tab, 1);
	}
	else if (nbr <= len_base)
		ft_putchar_fd(base[nbr], tab, 1);
	return (nbr);
}
