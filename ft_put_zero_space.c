/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_zero_space.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 12:46:27 by haroun            #+#    #+#             */
/*   Updated: 2021/06/15 16:50:37 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_print_type_pointer(t_liste *tab)
{
	char	*str;
	char	*str_p;

	str = "0x";
	str_p = ft_itoa_base((unsigned long long int)
			va_arg(tab->ap, unsigned long long int), "0123456789abcdef");
	str = ft_strjoin(str, str_p);
	if (ft_strcmp(str, "0x") == 0)
		str = ft_strcat(str, "0");
	free(str_p);
	return (str);
}

void	ft_putcharzero(int size, t_liste *tab)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putchar_fd('0', tab, 1);
		i++;
	}
}

void	ft_putcharspace(int size, t_liste *tab)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putchar_fd(' ', tab, 1);
		i++;
	}
}
