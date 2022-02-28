/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exception_di.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 18:25:07 by misaev            #+#    #+#             */
/*   Updated: 2021/06/15 15:28:57 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_exception_di(long long int nbr, t_liste *tab)
{
	int	size_nbr;

	size_nbr = ft_len_nbr(nbr);
	if (tab->dot_exception == 1
		&& tab->is_minus == 1 && nbr < 0 && tab->precision == size_nbr)
	{
		nbr *= -1;
		ft_putchar_fd('-', tab, 1);
		ft_putcharzero(tab->precision - ft_len_nbr(nbr), tab);
		ft_putnbr_fd(nbr, tab, 1);
		ft_putcharspace(tab->largeur - tab->precision - 1, tab);
	}
	else if (tab->largeur > tab->precision && tab->precision <= size_nbr)
		ft_exception_di_4(nbr, tab);
	else if (tab->precision >= size_nbr)
		ft_exception_di_3(nbr, tab);
	else if ((nbr == 0 && tab->precision < 1))
		return ;
	else
		ft_putnbr_fd(nbr, tab, 1);
}

void	ft_exception_di_2(long long int nbr, t_liste *tab)
{
	if (tab->zero == 1 && tab->precision > 0)
		ft_extra_di(nbr, tab);
	else if (tab->is_minus != 0
		&& tab->dot_exception == 1 && tab->precision > 0)
	{
		ft_putnbr_fd(nbr, tab, 1);
		ft_putcharspace(tab->largeur - 1, tab);
	}
	else if (tab->is_minus != 0
		&& tab->dot_exception == 1 && tab->precision < 0)
	{
		ft_putnbr_fd(nbr, tab, 1);
		ft_putcharspace(tab->largeur - 1, tab);
	}
	else if (tab->largeur >= 0 && tab->precision < 0)
		ft_extra_di_2(nbr, tab);
	else if (nbr == 0 && tab->largeur > 0 && tab->precision == 1)
	{
		ft_putcharspace(tab->largeur - 1, tab);
		ft_putnbr_fd(nbr, tab, 1);
	}
	else
		ft_putcharspace(tab->largeur, tab);
}

void	ft_exception_di_3(long long int nbr, t_liste *tab)
{
	int	size_nbr;

	size_nbr = ft_len_nbr(nbr);
	if (tab->largeur > tab->precision)
	{
		if (nbr < 0)
			nbr = ft_negatif_nbr(nbr, tab);
		if (tab->sign == 1 && tab->is_minus == 1)
		{
			ft_putchar_fd('-', tab, 1);
			ft_putcharzero(tab->precision - size_nbr, tab);
			ft_putnbr_fd(nbr, tab, 1);
			ft_putcharspace(tab->largeur - tab->precision, tab);
		}
		else if (tab->sign == 1)
			ft_extra_di_6(nbr, tab);
		else if (tab->is_minus != 0)
			ft_extra_di_4(nbr, tab);
		else
			ft_extra_di_5(nbr, tab);
	}
	else if (tab->largeur <= tab->precision)
		ft_extra_di_3(nbr, tab);
}

void	ft_exception_di_4(long long int nbr, t_liste *tab)
{
	int	size_nbr;

	size_nbr = ft_len_nbr(nbr);
	if (nbr == 0)
		ft_exception_di_2(nbr, tab);
	else if (nbr < 0 && tab->precision >= ft_len_nbr(nbr) && tab->is_minus == 1)
		ft_extra_di_7(nbr, tab);
	else if (tab->sign == 1 || tab->is_minus != 0)
	{
		ft_putnbr_fd(nbr, tab, 1);
		ft_putcharspace(tab->largeur - size_nbr, tab);
	}
	else if (nbr < 0 && tab->precision >= ft_len_nbr(nbr))
		ft_extra_di_8(nbr, tab);
	else
		ft_extra_di_9(nbr, tab);
}
