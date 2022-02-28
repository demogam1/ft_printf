/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_star.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 09:21:21 by hkrifa            #+#    #+#             */
/*   Updated: 2021/06/15 16:08:14 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_star(const char *format, t_liste *tab, int i)
{
	int	lrg;

	lrg = 0;
	tab->star = 1;
	if (format[i] == '*')
	{
		lrg = va_arg(tab->ap, int);
		i++;
	}
	tab->largeur = lrg;
	if (format[i] == '.')
	{
		tab->dot_exception = 1;
		ft_flag_dot(format, tab, i);
	}
	if (tab->largeur < 0)
	{
		tab->largeur *= -1;
		minus_with_converter(format, tab, i);
	}
	else
		star_with_converter(format, tab, i);
}

void	star_with_converter(const char *format, t_liste *tab, int i)
{
	int		nbr;
	char	*str;

	nbr = 0;
	str = NULL;
	if (format[i] == 'd' || format[i] == 'i')
	{
		nbr = va_arg(tab->ap, int);
		ft_star_di(nbr, tab);
		tab->index += i;
	}
	else if (format[i] == 'p')
	{
		str = ft_print_type_pointer(tab);
		ft_star_p(str, tab);
		tab->index += i;
		free(str);
	}
	else
		star_with_converter_2(format, tab, i);
}

void	star_with_converter_2(const char *format, t_liste *tab, int i)
{
	int		nbr;
	char	c;
	char	*str;

	nbr = 0;
	if (format[i] == 'c')
	{
		c = va_arg(tab->ap, int);
		ft_star_c(c, tab);
		tab->index += i;
	}
	else if (format[i] == 'u')
	{
		nbr = va_arg(tab->ap, unsigned int);
		ft_star_u(nbr, tab);
		tab->index += i;
	}
	else if (format[i] == 's')
	{
		str = va_arg(tab->ap, char *);
		ft_star_s(str, tab);
		tab->index += i;
	}
	else
		star_with_converter_3(format, tab, i);
}

void	star_with_converter_3(const char *format, t_liste *tab, int i)
{
	char	*str;

	if (format[i] == 'x')
	{
		str = ft_itoa_base
			(va_arg(tab->ap, unsigned int), "0123456789abcdef");
		ft_star_x(str, tab);
		tab->index += i;
		free(str);
	}
	else if (format[i] == 'X')
	{
		str = ft_itoa_base_maj
			(va_arg(tab->ap, unsigned int), "0123456789ABCDEF");
		ft_star_x(str, tab);
		tab->index += i;
		free(str);
	}
}

void	ft_star_u(int nbr, t_liste *tab)
{
	if (tab->largeur <= get_nb_size(nbr))
		ft_putnbr_u(nbr, tab);
	else if (tab->is_minus == 1 && tab->zero == 1)
	{
		ft_putnbr_u(nbr, tab);
		ft_putcharspace(tab->largeur - get_nb_size(nbr), tab);
	}
	else if (tab->zero == 1)
	{
		ft_putcharzero(tab->largeur - get_nb_size(nbr), tab);
		ft_putnbr_u(nbr, tab);
	}
	else
	{
		if (tab->is_minus == 1)
		{
			ft_putnbr_u(nbr, tab);
			ft_putcharspace(tab->largeur - get_nb_size(nbr), tab);
		}
		else
		{
			ft_putcharspace(tab->largeur - get_nb_size(nbr), tab);
			ft_putnbr_u(nbr, tab);
		}
	}
}
