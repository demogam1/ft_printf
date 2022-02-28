/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_minus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 22:49:07 by haroun            #+#    #+#             */
/*   Updated: 2021/06/15 15:50:49 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_minus(const char *format, t_liste *tab, int i)
{
	tab->is_minus = 1;
	while (format[i] == '-')
		i++;
	if (format[i] == '0')
		ft_flag_zero(format, tab, i);
	if (format[i] == '*')
		ft_flag_star(format, tab, i);
	if (ft_isdigit(format[i]))
	{
		tab->largeur = ft_atoi(&format[i]);
		i += ft_len_nbr(tab->largeur);
	}
	if (format[i] == '.')
		ft_flag_dot(format, tab, i);
	minus_with_converter(format, tab, i);
}

void	minus_with_converter(const char *format, t_liste *tab, int i)
{
	int		nbr;
	char	c;

	nbr = 0;
	if (format[i] == 'd' || format[i] == 'i')
	{
		nbr = va_arg(tab->ap, int);
		ft_minus_di(tab, nbr);
		tab->index = i;
	}
	else if (format[i] == 'u')
	{
		nbr = va_arg(tab->ap, unsigned int);
		ft_minus_u(tab, nbr);
		tab->index = i;
	}
	else if (format[i] == 'c')
	{
		c = va_arg(tab->ap, int);
		ft_minus_c(tab, c);
		tab->index = i;
	}
	else
		minus_with_pxX(format, tab, i);
}

void	ft_minus_di(t_liste *tab, int nbr)
{
	int	size_nbr;
	int	nbr_space;

	size_nbr = ft_len_nbr(nbr);
	if (tab->largeur <= size_nbr)
		ft_putnbr_fd(nbr, tab, 1);
	else
	{
		nbr_space = tab->largeur - size_nbr;
		ft_putnbr_fd(nbr, tab, 1);
		ft_putcharspace(nbr_space, tab);
	}
}

void	ft_minus_c(t_liste *tab, char c)
{
	int	nbr_space;

	if (tab->largeur <= 1)
		ft_putchar_fd(c, tab, 1);
	else
	{
		nbr_space = tab->largeur - 1;
		ft_putchar_fd(c, tab, 1);
		ft_putcharspace(nbr_space, tab);
	}
}

void	ft_minus_u(t_liste *tab, int nbr)
{
	int	size_nbr;
	int	nbr_space;

	size_nbr = get_nb_size(nbr);
	if (tab->largeur <= size_nbr)
		ft_putnbr_u(nbr, tab);
	else
	{
		nbr_space = tab->largeur - size_nbr;
		ft_putnbr_fd(nbr, tab, 1);
		ft_putcharspace(nbr_space, tab);
	}
}
