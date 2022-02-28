/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 14:15:50 by hkrifa            #+#    #+#             */
/*   Updated: 2021/06/15 17:27:57 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_rev(char *dest, int i)
{
	char	*str;
	int		j;

	j = 0;
	str = ft_calloc(sizeof(str), i);
	i--;
	while (i >= 0)
	{
		str[j] = dest[i];
		i--;
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_itoa_base(unsigned long long int nbr, char *base)
{
	char	*dest;
	char	*str;
	int		i;
	int		len;
	int		remain;

	i = 0;
	remain = 0;
	len = ft_strlen(base);
	dest = ft_calloc(sizeof(dest), 20);
	if (!dest)
		return (NULL);
	while (nbr > 0)
	{
		remain = nbr % len;
		if (remain < 10)
			dest[i] = remain + '0';
		else
			dest[i] = 'a' + (remain - 10);
		nbr = nbr / len;
		i++;
	}
	str = ft_rev(dest, i);
	free(dest);
	return (str);
}

char	*ft_itoa_base_maj(unsigned long long int nbr, char *base)
{
	char	*dest;
	char	*str;
	int		i;
	int		len;
	int		remain;

	i = 0;
	remain = 0;
	len = ft_strlen(base);
	dest = ft_calloc(sizeof(dest), 20);
	if (!dest)
		return (NULL);
	while (nbr > 0)
	{
		remain = nbr % len;
		if (remain < 10)
			dest[i] = remain + '0';
		else
			dest[i] = 'A' + (remain - 10);
		nbr = nbr / len;
		i++;
	}
	str = ft_rev(dest, i);
	free(dest);
	return (str);
}
