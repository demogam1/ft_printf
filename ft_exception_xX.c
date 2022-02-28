/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exception_xX.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:41:23 by misaev            #+#    #+#             */
/*   Updated: 2021/06/14 17:23:00 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_exception_xX(char *str, t_liste *tab)
{
	if (tab->dot_exception == 1 && tab->is_minus == 1
		&& str < 0 && tab->precision == ft_strlen(str))
	{
		ft_putcharzero(tab->precision - ft_strlen(str), tab);
		ft_putstr_fd(str, tab, 1);
		ft_putcharspace(tab->largeur - tab->precision - 1, tab);
	}
	else if (tab->largeur > tab->precision && tab->precision <= ft_strlen(str))
		ft_extra_x(str, tab);
	else if (tab->precision >= ft_strlen(str))
		ft_B_x(str, tab);
	else if (tab->largeur == tab->precision && str == 0 && tab->is_minus == 0)
		ft_putstr_fd(str, tab, 1);
	else if ((tab->largeur == 1 && tab->precision > 0)
		|| (tab->largeur == 0 && tab->precision == 0))
		ft_putstr_fd(str, tab, 1);
	else if (tab->largeur == 0
		&& tab->precision <= ft_strlen(str))
		ft_putstr_fd(str, tab, 1);
	else
		ft_putstr_fd(str, tab, 1);
}

void	ft_A_x(char *str, t_liste *tab)
{
	if ((tab->largeur > 0 && tab->precision < 0)
		|| (tab->largeur == 0 && tab->precision < 0))
	{
		if (tab->zero == 1 && tab->precision < 0)
			ft_putcharzero(tab->largeur - 1, tab);
		else
			ft_putcharspace(tab->largeur - 1, tab);
		ft_putchar_fd('0', tab, 1);
	}
	else if (tab->largeur > 0 && tab->precision <= ft_strlen(str))
		ft_putcharspace(tab->largeur, tab);
	else
	{
		ft_putcharspace(tab->largeur - 1, tab);
		ft_putchar_fd('0', tab, 1);
	}
}

void	ft_B_x(char *str, t_liste *tab)
{
	if (tab->largeur > tab->precision)
	{
		if (tab->is_minus != 0)
		{
			ft_putcharzero(tab->precision - ft_strlen(str), tab);
			ft_putstr_fd(str, tab, 1);
			ft_putcharspace(tab->largeur - tab->precision, tab);
		}
		else
		{
			ft_putcharspace(tab->largeur - tab->precision, tab);
			ft_putcharzero(tab->precision - ft_strlen(str), tab);
			ft_putstr_fd(str, tab, 1);
		}
	}
	else if (tab->largeur <= tab->precision)
	{
		ft_putcharzero(tab->precision - ft_strlen(str), tab);
		ft_putstr_fd(str, tab, 1);
	}
}

void	ft_C_x(char *str, t_liste *tab)
{
	if (str[0] == 0)
	{
		if (tab->precision == 0)
			ft_putcharspace(tab->largeur, tab);
		else
			ft_putchar_fd('0', tab, 1);
	}
	else
	{
		ft_putstr_fd(str, tab, 1);
		ft_putcharspace(tab->largeur - ft_strlen(str), tab);
	}
}

void	ft_D_x(char *str, t_liste *tab)
{
	if (str[0] == 0)
		ft_A_x(str, tab);
	else
	{
		if (tab->zero == 1 && tab->precision < 0)
			ft_putcharzero(tab->largeur - ft_strlen(str), tab);
		else
			ft_putcharspace(tab->largeur - ft_strlen(str), tab);
		ft_putstr_fd(str, tab, 1);
	}
}
