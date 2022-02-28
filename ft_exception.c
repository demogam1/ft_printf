/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exception.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 18:16:46 by misaev            #+#    #+#             */
/*   Updated: 2021/06/14 18:59:52 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_exception(const char *format, t_liste *tab, int i)
{
	int	nbr;

	if (tab->largeur < 0)
	{
		tab->largeur *= -1;
		tab->is_minus += 1;
	}
	if (format[i] == '*')
	{
		tab->precision = va_arg(tab->ap, long int);
		i++;
	}
	if (format[i] == 'd' || format[i] == 'i')
	{
		nbr = va_arg(tab->ap, int);
		ft_exception_di(nbr, tab);
		tab->index += i;
	}
	else
		ft_exception_A(format, tab, i);
}

void	ft_exception_A(const char *format, t_liste *tab, int i)
{
	int		nbr;
	char	*str;

	if (format[i] == 'u')
	{
		nbr = va_arg(tab->ap, unsigned int);
		ft_exception_u(nbr, tab);
		tab->index += i;
	}
	else if (format[i] == 'x')
	{
		str = ft_itoa_base(va_arg(tab->ap, unsigned int), "0123456789abcdef");
		ft_exception_xX(str, tab);
		tab->index = i;
		free(str);
	}
	else
		ft_exception_B(format, tab, i);
}

void	ft_exception_B(const char *format, t_liste *tab, int i)
{
	char	*str;

	if (format[i] == 'X')
	{
		str = ft_itoa_base_maj
			(va_arg(tab->ap, unsigned int), "0123456789abcdef");
		ft_exception_xX(str, tab);
		tab->index = i;
		free(str);
	}
	else if (format[i] == 's')
	{
		str = va_arg(tab->ap, char *);
		if (str == NULL)
			str = "(null)";
		ft_exception_s(tab, str);
		tab->index = i;
	}
}
