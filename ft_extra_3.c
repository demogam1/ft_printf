/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 21:02:26 by misaev            #+#    #+#             */
/*   Updated: 2021/06/15 15:45:40 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_extra_di_7(long long int nbr, t_liste *tab)
{
	nbr *= -1;
	ft_putchar_fd('-', tab, 1);
	ft_putcharzero(tab->precision - ft_len_nbr(nbr), tab);
	ft_putnbr_fd(nbr, tab, 1);
	ft_putcharspace(tab->largeur - ft_len_nbr(nbr) - 2, tab);
}

void	ft_extra_di_8(long long int nbr, t_liste *tab)
{
	ft_putcharspace(tab->largeur - ft_len_nbr(nbr) - 1, tab);
	nbr *= -1;
	ft_putchar_fd('-', tab, 1);
	ft_putcharzero(tab->precision - ft_len_nbr(nbr), tab);
	ft_putnbr_fd(nbr, tab, 1);
}

void	ft_extra_di_9(long long int nbr, t_liste *tab)
{
	int	size_nbr;

	size_nbr = ft_len_nbr(nbr);
	if (tab->zero == 1 && tab->dot_exception == 1
		&& tab->star == 1 && tab->precision < 0)
	{
		if (nbr < 0)
		{
			nbr *= -1;
			ft_putchar_fd('-', tab, 1);
		}
		ft_putcharzero(tab->largeur - size_nbr, tab);
	}
	else
		ft_putcharspace(tab->largeur - size_nbr, tab);
	ft_putnbr_fd(nbr, tab, 1);
}

void	ft_extra_dot_converter_2(t_liste *tab, char *str, int i)
{
	str = va_arg(tab->ap, char *);
	if (str == NULL)
		ft_extra_dot_converter_1(tab, str, i);
	else
	{
		ft_dot_s(tab, str);
		tab->index += i;
	}
}

void	ft_extra_dot_converter_1(t_liste *tab, char *str, int i)
{
	if (tab->precision == 0)
	{
		tab->index += i;
		return ;
	}
	else if (tab->precision > 0)
	{
		str = "(null)";
		ft_dot_s(tab, str);
		tab->index += i;
	}
	else
	{
		ft_putstr_fd("(null)", tab, 1);
		tab->index += i;
		return ;
	}
}
