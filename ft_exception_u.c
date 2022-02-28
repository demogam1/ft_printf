/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exception_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 11:59:19 by misaev            #+#    #+#             */
/*   Updated: 2021/06/14 16:35:04 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_exception_u(unsigned int nbr, t_liste *tab)
{
	if (tab->dot_exception == 1 && tab->is_minus == 1
		&& nbr < 0 && tab->precision == get_nb_size(nbr))
	{
		ft_putcharzero(tab->precision - ft_len_nbr(nbr), tab);
		ft_putnbr_fd(nbr, tab, 1);
		ft_putcharspace(tab->largeur - tab->precision - 1, tab);
	}
	else if (tab->largeur > tab->precision
		&& tab->precision <= get_nb_size(nbr))
		ft_D_u(nbr, tab);
	else if (tab->precision >= get_nb_size(nbr))
		ft_C_u(nbr, tab);
	else if (tab->largeur == tab->precision
		&& nbr == 0 && tab->is_minus == 0)
	{
		if (nbr == 0)
			return ;
		else
			ft_putnbr_fd(nbr, tab, 1);
	}
	else
		ft_extra_u(nbr, tab);
}

void	ft_A_u(unsigned int nbr, t_liste *tab)
{
	if (tab->zero == 1 && tab->precision < 0)
	{
		ft_putcharzero(tab->largeur - get_nb_size(nbr), tab);
		ft_putchar_fd('0', tab, 1);
	}
	else if (tab->is_minus == 1 && tab->precision < 0)
	{
		ft_putchar_fd('0', tab, 1);
		ft_putcharspace(tab->largeur - get_nb_size(nbr), tab);
	}
	else
	{
		ft_putcharspace(tab->largeur - get_nb_size(nbr), tab);
		ft_putchar_fd('0', tab, 1);
	}
}

void	ft_B_u(unsigned int nbr, t_liste *tab)
{
	if (tab->zero == 1 && tab->precision > 0)
	{
		ft_putcharspace(tab->largeur - 1, tab);
		ft_putnbr_fd(nbr, tab, 1);
	}
	else if (tab->precision < 0 && nbr == 0)
		ft_A_u(nbr, tab);
	else if (tab->largeur > 0 && tab->precision > 0)
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
	else
		ft_putcharspace(tab->largeur, tab);
}

void	ft_C_u(unsigned int nbr, t_liste *tab)
{
	if (tab->largeur > tab->precision)
	{
		if (tab->is_minus != 0)
		{
			ft_putcharzero(tab->precision - get_nb_size(nbr), tab);
			ft_putnbr_fd(nbr, tab, 1);
			ft_putcharspace(tab->largeur - tab->precision, tab);
		}
		else
		{
			ft_putcharspace(tab->largeur - tab->precision, tab);
			ft_putcharzero(tab->precision - get_nb_size(nbr), tab);
			ft_putnbr_fd(nbr, tab, 1);
		}
	}
	else if (tab->largeur <= tab->precision)
	{
		ft_putcharzero(tab->precision - get_nb_size(nbr), tab);
		ft_putnbr_fd(nbr, tab, 1);
	}
}

void	ft_D_u(unsigned int nbr, t_liste *tab)
{
	if (nbr == 0)
		ft_B_u(nbr, tab);
	else if (tab->sign == 1 || tab->is_minus != 0)
	{
		ft_putnbr_fd(nbr, tab, 1);
		ft_putcharspace(tab->largeur - get_nb_size(nbr), tab);
	}
	else
	{
		if (tab->zero == 1 && tab->precision < 0)
			ft_putcharzero(tab->largeur - get_nb_size(nbr), tab);
		else
			ft_putcharspace(tab->largeur - get_nb_size(nbr), tab);
		ft_putnbr_fd(nbr, tab, 1);
	}
}
