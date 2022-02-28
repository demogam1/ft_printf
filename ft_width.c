/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:36:23 by hkrifa            #+#    #+#             */
/*   Updated: 2021/06/15 17:07:01 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_width(const char *format, t_liste *tab, int i)
{
	int		nbr;
	char	*str;

	str = NULL;
	tab->largeur = ft_atoi(&format[i]);
	i += ft_len_nbr(tab->largeur);
	while (format[i] == '0')
		i++;
	if (format[i] == '.')
	{
		tab->dot_exception = 1;
		ft_flag_dot(format, tab, i);
	}
	else if (format[i] == 'd' || format[i] == 'i')
	{
		nbr = va_arg(tab->ap, int);
		ft_width_di(nbr, tab);
		tab->index = i;
	}
	else if (format[i] == 's')
		ft_width_s(str, tab, i);
	else
		ft_width_2(format, tab, i);
}

void	ft_width_2(const char *format, t_liste *tab, int i)
{
	char			c;
	char			*str;
	unsigned int	u_nbr;

	if (format[i] == 'c')
	{
		c = va_arg(tab->ap, int);
		ft_width_c(c, tab);
		tab->index = i;
	}
	else if (format[i] == 'u')
	{
		u_nbr = va_arg(tab->ap, unsigned int);
		ft_width_u(u_nbr, tab);
		tab->index = i;
	}
	else if (format[i] == 'x')
	{
		str = ft_itoa_base(va_arg(tab->ap, unsigned int), "0123456789abcdef");
		ft_width_x(str, tab);
		tab->index = i;
		free(str);
	}
	else
		ft_width_3(format, tab, i);
}

void	ft_width_3(const char *format, t_liste *tab, int i)
{
	char	*str;

	if (format[i] == 'X')
	{
		str = ft_itoa_base_maj
			(va_arg(tab->ap, unsigned int), "0123456789ABCDEF");
		ft_width_x(str, tab);
		tab->index = i;
		free(str);
	}
	else if (format[i] == 'p')
	{
		str = ft_print_type_pointer(tab);
		ft_width_p(str, tab);
		tab->index = i;
		free(str);
	}
}

void	ft_width_x(char *str, t_liste *tab)
{
	int	nbr_space;
	int	str_len;

	str_len = ft_strlen(str);
	if (tab->largeur <= str_len)
		ft_putstr_fd(str, tab, 1);
	else
	{
		nbr_space = tab->largeur - 1;
		ft_putcharspace(nbr_space, tab);
		ft_putchar_fd('0', tab, 1);
	}
}

void	ft_width_p(char *str, t_liste *tab)
{
	int	nbr_space;
	int	str_len;

	str_len = ft_strlen(str);
	if (tab->largeur <= str_len)
		ft_putstr_fd(str, tab, 1);
	else if (str == NULL)
	{
		nbr_space = tab->largeur - str_len;
		ft_putcharspace(nbr_space - 1, tab);
		ft_putstr_fd(str, tab, 1);
		ft_putchar_fd('0', tab, 1);
	}
	else if (tab->largeur > str_len)
	{
		nbr_space = tab->largeur - str_len;
		ft_putcharspace(nbr_space, tab);
		ft_putstr_fd(str, tab, 1);
	}
}
