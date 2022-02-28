/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 20:16:24 by misaev            #+#    #+#             */
/*   Updated: 2021/06/15 15:17:09 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_extra_di_3(long long int nbr, t_liste *tab)
{
	int	size_nbr;

	size_nbr = ft_len_nbr(nbr);
	if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar_fd('-', tab, 1);
		size_nbr -= 1;
	}
	ft_putcharzero(tab->precision - size_nbr, tab);
	ft_putnbr_fd(nbr, tab, 1);
}

void	ft_extra_di_4(long long int nbr, t_liste *tab)
{
	int	size_nbr;

	size_nbr = ft_len_nbr(nbr);
	ft_putcharzero(tab->precision - size_nbr, tab);
	ft_putnbr_fd(nbr, tab, 1);
	ft_putcharspace(tab->largeur - tab->precision, tab);
}

void	ft_extra_di_5(long long int nbr, t_liste *tab)
{
	int	size_nbr;

	size_nbr = ft_len_nbr(nbr);
	ft_putcharspace(tab->largeur - tab->precision, tab);
	ft_putcharzero(tab->precision - size_nbr, tab);
	ft_putnbr_fd(nbr, tab, 1);
}

void	ft_extra_di_6(long long int nbr, t_liste *tab)
{
	int	size_nbr;

	size_nbr = ft_len_nbr(nbr);
	ft_putcharspace(tab->largeur - tab->precision, tab);
	ft_putchar_fd('-', tab, 1);
	ft_putcharzero(tab->precision - size_nbr - 1, tab);
	ft_putnbr_fd(nbr, tab, 1);
}

int	ft_negatif_nbr(long long int nbr, t_liste *tab)
{
	nbr *= -1;
	tab->precision += 1;
	tab->sign = 1;
	return (nbr);
}
