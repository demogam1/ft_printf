/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_minus2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 14:23:10 by hkrifa            #+#    #+#             */
/*   Updated: 2021/06/15 15:58:27 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	minus_with_pxX(const char *format, t_liste *tab, int i)
{
	char	*str;

	str = NULL;
	if (format[i] == 'x')
	{
		str = ft_itoa_base
			(va_arg(tab->ap, unsigned int), "0123456789abcdef");
		ft_minus_with_xX(str, tab);
		tab->index += i;
		free(str);
	}
	else if (format[i] == 'X')
	{
		str = ft_itoa_base_maj
			(va_arg(tab->ap, unsigned int), "0123456789ABCDEF");
		ft_minus_with_xX(str, tab);
		tab->index += i;
		free(str);
	}
	else if (format[i] == 's')
		ft_minus_s(tab, str, i);
	else
		minus_with_pxX2(format, tab, i);
}

void	ft_minus_s(t_liste *tab, char *str, int i)
{
	int	nbr_space;
	int	str_len;

	str = va_arg(tab->ap, char *);
	if (str == NULL)
		str = "(null)";
	tab->index += i;
	str_len = ft_strlen(str);
	if (tab->largeur <= str_len)
		ft_putstr_fd(str, tab, 1);
	else
	{
		nbr_space = tab->largeur - str_len;
		ft_putstr_fd(str, tab, 1);
		ft_putcharspace(nbr_space, tab);
	}
}

void	minus_with_pxX2(const char *format, t_liste *tab, int i)
{
	char	*str;

	if (format[i] == 'p')
	{
		str = ft_print_type_pointer(tab);
		ft_minus_with_p(str, tab);
		tab->index += i;
		free(str);
	}
}

void	ft_minus_with_p(char *str, t_liste *tab)
{
	int	len_str;
	int	nbr_space;

	len_str = ft_strlen(str);
	if (tab->largeur <= len_str)
		ft_putstr_fd(str, tab, 1);
	else if (tab->is_minus == 1)
	{
		nbr_space = tab->largeur - 1;
		ft_putstr_fd(str, tab, 1);
		ft_putcharspace(tab->largeur - len_str, tab);
	}
	else
	{
		nbr_space = tab->largeur - len_str;
		ft_putstr_fd(str, tab, 1);
		ft_putcharspace(nbr_space, tab);
	}
}

void	ft_minus_with_xX(char *str, t_liste *tab)
{
	int	len_str;
	int	nbr_space;

	len_str = ft_strlen(str);
	if (tab->largeur <= len_str)
		ft_putstr_fd(str, tab, 1);
	else if (tab->is_minus == 1)
	{
		nbr_space = tab->largeur - 1;
		ft_putchar_fd('0', tab, 1);
		ft_putcharspace(nbr_space, tab);
	}
	else
	{
		nbr_space = tab->largeur - len_str;
		if (str[0] == 0)
			ft_putchar_fd('0', tab, 1);
		else
		{
			ft_putstr_fd(str, tab, 1);
			ft_putcharspace(nbr_space, tab);
		}
	}
}
