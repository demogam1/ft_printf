/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_star2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:04:33 by hkrifa            #+#    #+#             */
/*   Updated: 2021/06/15 16:29:58 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_star_p(char *str_p, t_liste *tab)
{
	int	size_nbr;

	size_nbr = ft_strlen(str_p);
	if (tab->largeur <= size_nbr)
		ft_putstr_fd(str_p, tab, 1);
	else if (tab->is_minus == 1)
	{
		ft_putstr_fd(str_p, tab, 1);
		ft_putcharspace(tab->largeur - size_nbr, tab);
	}
	else
	{
		ft_putcharspace(tab->largeur - size_nbr, tab);
		ft_putstr_fd(str_p, tab, 1);
	}
}

void	ft_star_di(int nbr, t_liste *tab)
{
	int	size_nbr;

	size_nbr = ft_len_nbr(nbr);
	if (tab->largeur <= size_nbr)
		ft_putnbr_fd(nbr, tab, 1);
	else if (tab->is_minus == 1)
	{
		ft_putnbr_fd(nbr, tab, 1);
		ft_putcharspace(tab->largeur - size_nbr, tab);
	}
	else if (nbr < 0 && tab->zero == 1)
		ft_star_di_2(nbr, tab);
	else if (nbr >= 0 && tab->zero == 1)
	{
		ft_putcharzero(tab->largeur - size_nbr, tab);
		ft_putnbr_fd(nbr, tab, 1);
	}
	else
	{
		ft_putcharspace(tab->largeur - size_nbr, tab);
		ft_putnbr_fd(nbr, tab, 1);
	}
}

void	ft_star_c(char c, t_liste *tab)
{
	int	nbr_space;

	if (tab->largeur <= 1)
		ft_putchar_fd(c, tab, 1);
	else
	{
		nbr_space = tab->largeur - 1;
		if (tab->is_minus == 1)
		{
			ft_putchar_fd(c, tab, 1);
			ft_putcharspace(nbr_space, tab);
		}
		else
		{
			ft_putcharspace(nbr_space, tab);
			ft_putchar_fd(c, tab, 1);
		}
	}
}

void	ft_star_s(char *str, t_liste *tab)
{
	int	nbr_space;
	int	str_len;

	str_len = ft_strlen(str);
	if (tab->largeur <= str_len)
		ft_putstr_fd(str, tab, 1);
	else if (tab->is_minus == 1)
	{
		ft_putstr_fd(str, tab, 1);
		ft_putcharspace(tab->largeur - str_len, tab);
	}
	else
	{
		nbr_space = tab->largeur - str_len;
		ft_putcharspace(nbr_space, tab);
		ft_putstr_fd(str, tab, 1);
	}
}

void	ft_star_x(char *str, t_liste *tab)
{
	if (tab->largeur <= ft_strlen(str))
	{
		if (str[0] == 0)
			ft_putchar_fd('0', tab, 1);
		else
			ft_putstr_fd(str, tab, 1);
	}
	else if (tab->is_minus == 1 && tab->zero == 1)
	{
		ft_putstr_fd(str, tab, 1);
		ft_putcharspace(tab->largeur - ft_strlen(str), tab);
	}
	else if (tab->zero == 1)
	{
		ft_putcharzero(tab->largeur - ft_strlen(str), tab);
		ft_putstr_fd(str, tab, 1);
	}
	else
	{
		if (str[0] == 0)
			ft_star_x_2(tab);
		else
			ft_star_x_3(str, tab);
	}
}
