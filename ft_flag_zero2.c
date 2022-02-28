/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_zero2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 18:14:08 by hkrifa            #+#    #+#             */
/*   Updated: 2021/06/15 16:45:09 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_zero_u(t_liste *tab, unsigned int nbr)
{
	int	size_nbr;
	int	nbr_zero;

	size_nbr = get_nb_size(nbr);
	if (tab->largeur <= size_nbr)
		ft_putnbr_u(nbr, tab);
	else
	{
		nbr_zero = tab->largeur - size_nbr;
		ft_putcharzero(nbr_zero, tab);
		ft_putnbr_fd(nbr, tab, 1);
	}
}

void	ft_zero_with_c(t_liste *tab, char c)
{
	int	nbr_zero;

	if (tab->largeur <= 1)
		ft_putchar_fd(c, tab, 1);
	else
	{
		nbr_zero = tab->largeur - 1;
		ft_putcharzero(nbr_zero, tab);
		ft_putchar_fd(c, tab, 1);
	}
}

void	ft_zero_with_x(char *str, t_liste *tab)
{
	if (tab->largeur <= ft_strlen(str))
	{
		if (str[0] == 0 && tab->precision == 0)
			return ;
		else if (str[0] == 0)
			ft_zero_with_x2(tab);
		else
		{
			if (tab->precision > 0)
			{
				ft_putcharzero(tab->precision - ft_strlen(str), tab);
				ft_putstr_fd(str, tab, 1);
			}
			else
				ft_putstr_fd(str, tab, 1);
		}
	}
	else
	{
		ft_putcharzero(tab->largeur - ft_strlen(str), tab);
		ft_putstr_fd(str, tab, 1);
	}
}

void	ft_zero_with_x2(t_liste *tab)
{
	if (tab->precision > 0)
	{
		ft_putcharzero(tab->precision - 1, tab);
		ft_putchar_fd('0', tab, 1);
	}
	else
		ft_putchar_fd('0', tab, 1);
}
