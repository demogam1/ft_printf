/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 17:03:18 by hkrifa            #+#    #+#             */
/*   Updated: 2021/06/14 14:40:42 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_flag(const char *format, t_liste *tab, int i)
{
	ft_tab_reinit(tab);
	if (format[i] == '0')
		ft_flag_zero(format, tab, i);
	else if (format[i] == '.')
		ft_flag_dot(format, tab, i);
	else if (format[i] == '*')
		ft_flag_star(format, tab, i);
	else if (format[i] == '-')
		ft_flag_minus(format, tab, i);
	else if (ft_isdigit(format[i]) == 1)
		ft_width(format, tab, i);
	else
		ft_check_format(format, tab, i);
}

void	ft_check_format(const char *format, t_liste *tab, int i)
{
	char	*str;

	if (format[i] == 'c')
	{
		ft_putchar_fd(va_arg(tab->ap, int), tab, 1);
		tab->index = i;
	}
	else if (format[i] == 's')
	{
		str = va_arg(tab->ap, char *);
		if (str == NULL)
			str = "(null)";
		ft_putstr_fd(str, tab, 1);
		tab->index = i;
	}
	else if (format[i] == 'd' || format[i] == 'i')
	{
		ft_putnbr_fd(va_arg(tab->ap, int), tab, 1);
		tab->index = i;
	}
	else
		ft_check_format_2(format, tab, i);
}

void	ft_check_format_2(const char *format, t_liste *tab, int i)
{
	char	*str;

	if (format[i] == 'p')
	{
		str = ft_print_type_pointer(tab);
		ft_putstr_fd(str, tab, 1);
		tab->index = i;
		free(str);
	}
	else if (format[i] == 'u')
	{
		ft_putnbr_u(va_arg(tab->ap, unsigned int), tab);
		tab->index = i;
	}
	else if (format[i] == 'x')
	{
		ft_putnbr_base(va_arg(tab->ap, unsigned int), tab, "0123456789abcdef");
		tab->index = i;
	}
	else
		ft_check_format_3(format, tab, i);
}

void	ft_check_format_3(const char *format, t_liste *tab, int i)
{
	if (format[i] == 'X')
	{
		ft_putnbr_base(va_arg(tab->ap, unsigned int), tab, "0123456789ABCDEF");
		tab->index = i;
	}
	else if (format[i] == '%')
	{
		ft_putchar_fd('%', tab, 1);
		 tab->index = i;
	}
}
