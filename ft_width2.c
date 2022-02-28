/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_widht2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 17:07:32 by misaev            #+#    #+#             */
/*   Updated: 2021/06/15 17:07:58 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_width_u(unsigned int u_nbr, t_liste *tab)
{
	int	size_nbr;
	int	nbr_zero;

	size_nbr = get_nb_size(u_nbr);
	if (tab->largeur <= size_nbr)
		ft_putnbr_u(u_nbr, tab);
	else
	{
		nbr_zero = tab->largeur - size_nbr;
		ft_putcharspace(nbr_zero, tab);
		ft_putnbr_fd(u_nbr, tab, 1);
	}
}

void	ft_width_c(char c, t_liste *tab)
{
	int	nbr_space;

	if (tab->largeur <= 1)
		ft_putchar_fd(c, tab, 1);
	else
	{
		nbr_space = tab->largeur - 1;
		ft_putcharspace(nbr_space, tab);
		ft_putchar_fd(c, tab, 1);
	}
}

void	ft_width_s(char *str, t_liste *tab, int i)
{
	int	str_len;
	int	nbr_space;

	str = va_arg(tab->ap, char *);
	if (str == NULL)
		str = "(null)";
	tab->index = i;
	str_len = ft_strlen(str);
	if (tab->largeur <= str_len)
		ft_putstr_fd(str, tab, 1);
	else
	{
		nbr_space = tab->largeur - str_len;
		ft_putcharspace(nbr_space, tab);
		ft_putstr_fd(str, tab, 1);
	}
}

void	ft_width_di(int nbr, t_liste *tab)
{
	int	size_nbr;
	int	nbr_space;

	size_nbr = ft_len_nbr(nbr);
	if (tab->largeur <= size_nbr)
		ft_putnbr_fd(nbr, tab, 1);
	else
	{
		nbr_space = tab->largeur - size_nbr;
		ft_putcharspace(nbr_space, tab);
		ft_putnbr_fd(nbr, tab, 1);
	}
}
