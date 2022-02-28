/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 16:24:54 by hkrifa            #+#    #+#             */
/*   Updated: 2021/06/14 14:32:19 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int		ft_strlen(const char *str);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_len_nbr(long long int nbr);
int		ft_isdigit(int c);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*ft_rev_tab(char *rev, int i);
char	*ft_itoa_base(unsigned long long int n, char *base);
char	*ft_itoa_base_maj(unsigned long long int n, char *base);
char	*ft_strndup(char const *s, size_t n);
int		ft_isalpha(int c);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strcat(char *dest, char *src);
int		get_nb_size(unsigned int nb);

#endif
