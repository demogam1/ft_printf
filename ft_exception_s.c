/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exception_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 16:00:33 by misaev            #+#    #+#             */
/*   Updated: 2021/06/14 15:40:26 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_exception_s(t_liste *tab, char *str)
{
	if (tab->dot_exception == 1 && tab->precision == 0)
		ft_putcharspace(tab->largeur, tab);
	else if (tab->precision < ft_strlen(str))
	{
		if (tab->precision < 0)
			ft_A(tab, str);
		else if (tab->is_minus != 0)
		{
			str = ft_strndup(str, tab->precision);
			ft_putstr_fd(str, tab, 1);
			ft_putcharspace(tab->largeur - tab->precision, tab);
			free(str);
		}
		else
		{
			str = ft_strndup(str, tab->precision);
			ft_putcharspace(tab->largeur - tab->precision, tab);
			ft_putstr_fd(str, tab, 1);
			free(str);
		}
	}
	else if (tab->is_minus == 1 && tab->dot_exception == 1)
		ft_B(tab, str);
	else
		ft_C(tab, str);
}

void	ft_A(t_liste *tab, char *str)
{
	if (tab->precision < 0 && (tab->is_minus == 1 || tab->dot_exception == 1))
	{
		if (tab->is_minus == 0)
		{
			ft_putcharspace(tab->largeur - ft_strlen(str), tab);
			ft_putstr_fd(str, tab, 1);
		}
		else
		{
			ft_putstr_fd(str, tab, 1);
			ft_putcharspace(tab->largeur - ft_strlen(str), tab);
		}
	}
	else
		ft_putstr_fd(str, tab, 1);
}

void	ft_B(t_liste *tab, char *str)
{
	ft_putstr_fd(str, tab, 1);
	ft_putcharspace(tab->largeur - ft_strlen(str), tab);
}

void	ft_C(t_liste *tab, char *str)
{
	if (tab->is_minus != 0)
	{
		ft_putstr_fd(str, tab, 1);
		ft_putcharspace(tab->largeur - ft_strlen(str), tab);
		return ;
	}
	else if (tab->dot_exception == 1 && tab->largeur >= ft_strlen(str))
		ft_putcharspace(tab->largeur - ft_strlen(str), tab);
	str = ft_strndup(str, tab->precision);
	ft_putstr_fd(str, tab, 1);
	free(str);
}
