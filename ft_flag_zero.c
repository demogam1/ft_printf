/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_zero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:44:50 by hkrifa            #+#    #+#             */
/*   Updated: 2021/06/15 16:38:40 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_zero(const char *format, t_liste *tab, int i)
{
	int	lrg;

	lrg = 0;
	tab->zero = 1;
	while (format[i] == '0')
		i++;
	if (format[i] == '.')
		ft_flag_dot(format, tab, i);
	else if (format[i] == '-')
		ft_flag_minus(format, tab, i);
	else if (format[i] == '*')
		ft_flag_star(format, tab, i);
	if (ft_isdigit(format[i]) == 1)
	{
		lrg = ft_atoi(&format[i]);
		if (ft_isdigit(format[i + ft_len_nbr(lrg)])
			== 0 && ft_isalpha(format[i + ft_len_nbr(lrg)]) == 0)
			ft_width(format, tab, i);
		else
			i += ft_len_nbr(lrg);
	}
	tab->largeur = lrg;
	zero_with_converter(format, tab, i);
}

void	zero_with_converter(const char *format, t_liste *tab, int i)
{
	int				nbr;
	unsigned int	nbr_u;
	char			*str;

	str = NULL;
	nbr = 0;
	if (format[i] == 'd' || format[i] == 'i')
		zero_di_extra(tab, nbr, i);
	else if (format[i] == 's')
	{
		str = va_arg(tab->ap, char *);
		ft_zero_s(tab, str);
		tab->index += i;
	}
	else if (format[i] == 'u')
	{
		nbr_u = va_arg(tab->ap, unsigned int);
		ft_zero_u(tab, nbr_u);
		tab->index += i;
	}
	else
		zero_with_cpxX(format, tab, str, i);
}

void	zero_with_cpxX(const char *format, t_liste *tab, char *str, int i)
{
	char	c;

	if (format[i] == 'c')
	{
		c = va_arg(tab->ap, int);
		ft_zero_with_c(tab, c);
		tab->index += i;
	}
	else if (format[i] == 'x')
	{
		str = ft_itoa_base
			(va_arg(tab->ap, unsigned int), "0123456789abcdef");
		ft_zero_with_x(str, tab);
		tab->index += i;
		free(str);
	}
	else if (format[i] == 'X')
	{
		str = ft_itoa_base_maj
			(va_arg(tab->ap, unsigned int), "0123456789ABCDEF");
		ft_zero_with_x(str, tab);
		tab->index += i;
		free(str);
	}
}

void	ft_zero_di(t_liste *tab, int nbr)
{
	int	size_nbr;
	int	nbr_zero;

	size_nbr = ft_len_nbr(nbr);
	nbr_zero = tab->largeur - size_nbr;
	if (tab->largeur <= size_nbr)
		ft_putnbr_fd(nbr, tab, 1);
	else if (tab->sign == 1)
	{
		nbr *= -1;
		ft_putchar_fd('-', tab, 1);
		ft_putcharzero(nbr_zero, tab);
		ft_putnbr_fd(nbr, tab, 1);
	}
	else
	{
		ft_putcharzero(nbr_zero, tab);
		ft_putnbr_fd(nbr, tab, 1);
	}
}

void	ft_zero_s(t_liste *tab, char *str)
{
	int	len_str;
	int	nbr_zero;

	len_str = ft_strlen(str);
	if (tab->largeur <= len_str)
		ft_putstr_fd(str, tab, 1);
	else
	{
		nbr_zero = tab->largeur - len_str;
		ft_putcharzero(nbr_zero, tab);
		ft_putstr_fd(str, tab, 1);
	}
}
