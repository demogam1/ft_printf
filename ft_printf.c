/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 15:40:30 by haroun            #+#    #+#             */
/*   Updated: 2021/06/15 16:49:09 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_liste	*ft_tab_init(t_liste *tab)
{
	tab->tl = 0;
	tab->largeur = 0;
	tab->index = 0;
	tab->len = 0;
	tab->sign = 0;
	tab->precision = 0;
	tab->zero = 0;
	tab->dot_exception = 0;
	tab->is_minus = 0;
	return (tab);
}

t_liste	*ft_tab_reinit(t_liste *tab)
{
	tab->largeur = 0;
	tab->index = 0;
	tab->sign = 0;
	tab->zero = 0;
	tab->precision = 0;
	tab->dot_exception = 0;
	tab->is_minus = 0;
	return (tab);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	t_liste	*tab;

	tab = malloc(sizeof(t_liste));
	if (!tab || format == NULL)
		return (-1);
	ft_tab_init(tab);
	va_start(tab->ap, format);
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			ft_check_flag(format, tab, i + 1);
			i = tab->index;
		}
		else
			tab->tl += write(1, &format[i], 1);
	}
	tab->tl += tab->len;
	va_end (tab->ap);
	free(tab);
	return (tab->tl);
}
