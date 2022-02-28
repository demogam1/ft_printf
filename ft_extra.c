/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 16:27:23 by misaev            #+#    #+#             */
/*   Updated: 2021/06/15 15:21:24 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_extra_u(unsigned int nbr, t_liste *tab)
{
	if (tab->largeur == 0 && tab->precision == 0
		&& nbr == 0 && tab->is_minus == 1)
		return ;
	else if ((tab->largeur == 0 && tab->precision == 0)
		|| (tab->largeur == 1 && tab->precision > 0))
		ft_putnbr_fd(nbr, tab, 1);
	else if (tab->largeur == 0
		&& tab->precision <= get_nb_size(nbr))
		ft_putnbr_fd(nbr, tab, 1);
	else
		ft_putnbr_fd(nbr, tab, 1);
}

void	ft_extra_x(char *str, t_liste *tab)
{
	if (str == 0)
	{
		if (tab->zero == 1 && tab->precision > 0)
		{
			ft_putcharspace(tab->largeur - 1, tab);
			ft_putstr_fd(str, tab, 1);
		}
		else
			ft_putcharspace(tab->largeur, tab);
	}
	else if (str[0] == 0 && tab->is_minus == 1 && tab->zero == 0)
	{
		if (tab->precision == 0)
			ft_putcharspace(tab->largeur, tab);
		else
		{
			ft_putchar_fd('0', tab, 1);
			ft_putcharspace(tab->largeur - 1, tab);
		}
	}
	else if (tab->sign == 1 || tab->is_minus != 0)
		ft_C_x(str, tab);
	else
		ft_D_x(str, tab);
}

void	ft_extra_di(long long int nbr, t_liste *tab)
{
	int	size_nbr;

	size_nbr = ft_len_nbr(nbr);
	if (tab->precision == size_nbr && tab->is_minus == 1)
	{
		ft_putnbr_fd(nbr, tab, 1);
		ft_putcharspace(tab->largeur - 1, tab);
	}
	else
	{
		ft_putcharspace(tab->largeur - 1, tab);
		ft_putnbr_fd(nbr, tab, 1);
	}
}

void	ft_extra_di_2(long long int nbr, t_liste *tab)
{
	if (tab->zero == 1 && tab->zero == 1
		&& tab->dot_exception == 1 && tab->star == 1)
		ft_putcharzero(tab->largeur - 1, tab);
	else if (tab->zero == 0)
		ft_putcharspace(tab->largeur - 1, tab);
	ft_putnbr_fd(nbr, tab, 1);
}
