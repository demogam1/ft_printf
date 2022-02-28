/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_dot_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 15:23:06 by misaev            #+#    #+#             */
/*   Updated: 2021/06/15 17:12:15 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_dot_di(t_liste *tab, long long int nbr)
{
	if (nbr < 0 && tab->star == 1 && tab->zero == 0 && tab->precision > 1)
	{
		nbr = nbr * -1;
		ft_putchar_fd('-', tab, 1);
		ft_putcharzero(tab->precision - ft_len_nbr(nbr), tab);
		ft_putnbr_fd(nbr, tab, 1);
	}
	else if (nbr <= 0 || tab->precision < 0)
	{
		if (nbr == 0)
			ft_A_dot_di(tab, nbr);
		else
			ft_B_dot_di(tab, nbr);
	}
	else if (nbr > 0 || tab->sign == 1)
		ft_C_dot_di(tab, nbr);
}

void	ft_A_dot_di(t_liste *tab, long long int nbr)
{
	if (tab->zero == 1 && tab->dot_exception == 0
		&& tab->largeur == 0 && tab->precision == 0)
		return ;
	else if (tab->zero == 0 && tab->precision == 0)
		return ;
	else if (tab->precision > 0)
	{
		ft_putcharzero(tab->precision - ft_len_nbr(nbr), tab);
		ft_putnbr_fd(nbr, tab, 1);
	}
	else
		ft_putnbr_fd(nbr, tab, 1);
}

void	ft_B_dot_di(t_liste *tab, long long int nbr)
{
	if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar_fd('-', tab, 1);
		ft_putcharzero(tab->precision - ft_len_nbr(nbr), tab);
		ft_putnbr_fd(nbr, tab, 1);
	}
	else
	{
		ft_putcharzero(tab->precision - ft_len_nbr(nbr), tab);
		ft_putnbr_fd(nbr, tab, 1);
	}
}

void	ft_C_dot_di(t_liste *tab, long long int nbr)
{
	int	size_nbr;
	int	nbr_zero;

	size_nbr = ft_len_nbr(nbr);
	if (tab->precision <= size_nbr)
		ft_putnbr_fd(nbr, tab, 1);
	else
	{
		nbr_zero = tab->precision - size_nbr;
		ft_putcharzero(nbr_zero, tab);
		ft_putnbr_fd(nbr, tab, 1);
	}
}
