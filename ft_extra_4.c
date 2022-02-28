/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:04:01 by misaev            #+#    #+#             */
/*   Updated: 2021/06/15 17:10:31 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_star_di_2(int nbr, t_liste *tab)
{
	int	size_nbr;

	size_nbr = ft_len_nbr(nbr);
	nbr *= -1;
	ft_putchar_fd('-', tab, 1);
	ft_putcharzero(tab->largeur - size_nbr, tab);
	ft_putnbr_fd(nbr, tab, 1);
}

void	ft_star_x_2(t_liste *tab)
{
	if (tab->is_minus == 1)
	{
		ft_putchar_fd('0', tab, 1);
		ft_putcharspace(tab->largeur - 1, tab);
	}
	else
	{
		ft_putcharspace(tab->largeur - 1, tab);
		ft_putchar_fd('0', tab, 1);
	}
}

void	ft_star_x_3(char *str, t_liste *tab)
{
	int	str_len;

	str_len = ft_strlen(str);
	if (tab->is_minus == 1)
	{
		ft_putstr_fd(str, tab, 1);
		ft_putcharspace(tab->largeur - str_len, tab);
	}
	else
	{
		ft_putcharspace(tab->largeur - str_len, tab);
		ft_putstr_fd(str, tab, 1);
	}
}

void	zero_di_extra(t_liste *tab, int nbr, int i)
{
	nbr = va_arg(tab->ap, int);
	if (nbr < 0)
	{
		tab->sign = 1;
		ft_zero_di(tab, nbr);
		tab->index += i;
	}
	else
	{
		ft_zero_di(tab, nbr);
		tab->index += i;
	}
}
