/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_dot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 13:31:14 by haroun            #+#    #+#             */
/*   Updated: 2021/06/15 15:48:29 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_dot(const char *format, t_liste *tab, int i)
{
	while (format[i] == '.')
		i++;
	while (format[i] == '0')
		i++;
	if (ft_isdigit(format[i]))
	{
		tab->precision = ft_atoi(&format[i]);
		i += ft_len_nbr(tab->precision);
	}
	if (format[i] == '*' && tab->dot_exception == 0)
	{
		tab->star = 1;
		tab->precision = va_arg(tab->ap, int);
		dot_with_converter(format, tab, i + 1);
	}
	else if (tab->dot_exception == 1 || tab->is_minus == 1)
		ft_exception(format, tab, i);
	else
		dot_with_converter(format, tab, i);
}

void	dot_with_converter(const char *format, t_liste *tab, int i)
{
	int		nbr;
	char	c;
	char	*str;

	str = NULL;
	if (format[i] == 'd' || format[i] == 'i')
	{
		nbr = va_arg(tab->ap, int);
		ft_dot_di(tab, nbr);
		tab->index += i;
	}
	else if (format[i] == 's')
		ft_extra_dot_converter_2(tab, str, i);
	else if (format[i] == 'c')
	{
		c = va_arg(tab->ap, int);
		ft_putchar_fd(c, tab, 1);
		tab->index += i;
	}
	else
		dot_with_upxX(format, tab, i, str);
}

void	dot_with_upxX(const char *format, t_liste *tab, int i, char *str)
{
	int	nbr;

	str = NULL;
	if (format[i] == 'u')
	{
		nbr = va_arg(tab->ap, unsigned int);
		ft_dot_u(tab, nbr);
		tab->index += i;
	}
	else if (format[i] == 'x')
	{
		str = ft_itoa_base(va_arg(tab->ap, unsigned int), "0123456789abcdef");
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

void	ft_dot_u(t_liste *tab, unsigned int nbr)
{
	int	size_nbr;
	int	nbr_zero;

	size_nbr = get_nb_size(nbr);
	if (tab->largeur == 0 && tab->precision == 0 && nbr == 0)
		return ;
	if (tab->precision <= size_nbr)
		ft_putnbr_u(nbr, tab);
	else
	{
		nbr_zero = tab->precision - size_nbr;
		ft_putcharzero(nbr_zero, tab);
		ft_putnbr_fd(nbr, tab, 1);
	}
}

void	ft_dot_s(t_liste *tab, char *str)
{
	int	len_str;

	len_str = ft_strlen(str);
	if (tab->dot_exception == 1
		&& tab->largeur >= len_str && tab->precision > 0)
	{
		ft_putcharspace(tab->largeur - len_str, tab);
		str = ft_strndup(str, tab->precision);
		ft_putstr_fd(str, tab, 1);
		free(str);
	}
	else
	{
		if (tab->precision > 0)
		{
			str = ft_strndup(str, tab->precision);
			ft_putstr_fd(str, tab, 1);
			free(str);
		}
		else if (tab->precision == 0 && tab->largeur == 0)
			return ;
		else
			ft_putstr_fd(str, tab, 1);
	}
}
