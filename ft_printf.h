/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 23:06:43 by haroun            #+#    #+#             */
/*   Updated: 2021/06/15 17:20:15 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
typedef struct s_liste
{
	va_list	ap;
	int		zero;
	int		largeur;
	int		index;
	int		len;
	int		sign;
	int		dot_exception;
	int		precision;
	int		is_minus;
	int		tl;
	int		star;
}					t_liste;
void	ft_check_format_2(const char *format, t_liste *tab, int i);
void	ft_check_format_3(const char *format, t_liste *tab, int i);
/* void output function  */
void	ft_putchar_fd(char c, t_liste *tab, int fd);
void	ft_putstr_fd(char *s, t_liste *tab, int fd);
void	ft_putnbr_fd(long long int n, t_liste *tab, int fd);
void	ft_putnbr_u(unsigned int nb, t_liste *tab);
void	ft_putcharzero(int size, t_liste *tab);
void	ft_putcharspace(int size, t_liste *tab);
void	ft_putcharzero2(int size, t_liste *tab);
/* void width fonction */
void	ft_width(const char *format, t_liste *tab, int i);
void	ft_width_2(const char *format, t_liste *tab, int i);
void	ft_width_3(const char *format, t_liste *tab, int i);
void	ft_width_x(char *str, t_liste *tab);
void	ft_width_di(int nbr, t_liste *tab);
void	ft_width_s(char *str, t_liste *tab, int i);
void	ft_width_c(char c, t_liste *tab);
void	ft_width_u(unsigned int u_nbr, t_liste *tab);
/*  int function  */
int		ft_printf(const char *format, ...);
int		ft_putnbr_base(unsigned long nbr, t_liste *tab, char *base);
/*  void function  */
void	ft_check_format(const char *format, t_liste *tab, int i);
void	ft_check_flag(const char *format, t_liste *tab, int i);
/* flag '0' */
void	ft_flag_zero(const char *format, t_liste *tab, int i);
void	zero_with_converter(const char *format, t_liste *tab, int i);
void	ft_zero_di(t_liste *tab, int nbr);
void	ft_zero_s(t_liste *tab, char *str);
void	ft_zero_u(t_liste *tab, unsigned int nbr);
void	ft_zero_with_c(t_liste *tab, char c);
void	ft_zero_with_x(char *str, t_liste *tab);
void	ft_zero_with_x2(t_liste *tab);
void	zero_di_extra(t_liste *tab, int nbr, int i);
void	zero_with_cpxX(const char *format, t_liste *tab, char *str, int i);
/* flag '.' */
void	ft_flag_dot(const char *format, t_liste *tab, int i);
void	ft_dot_di(t_liste *tab, long long int nbr);
void	ft_dot_s(t_liste *tab, char *str);
void	ft_dot_u(t_liste *tab, unsigned int nbr);
void	ft_A_dot_di(t_liste *tab, long long int nbr);
void	ft_B_dot_di(t_liste *tab, long long int nbr);
void	ft_C_dot_di(t_liste *tab, long long int nbr);
void	ft_width_p(char *str, t_liste *tab);
void	dot_with_converter(const char *format, t_liste *tab, int i);
void	dot_with_upxX(const char *format, t_liste *tab, int i, char *str);
void	dot_with_upx_2(const char *format, t_liste *tab, int i, char *str);
/* flag '*' */
void	star_with_converter(const char *format, t_liste *tab, int i);
void	star_with_converter_2(const char *format, t_liste *tab, int i);
void	star_with_converter_3(const char *format, t_liste *tab, int i);
void	ft_flag_star(const char *format, t_liste *tab, int i);
void	ft_star_di(int nbr, t_liste *tab);
void	ft_star_di_2(int nbr, t_liste *tab);
void	ft_star_p(char *str_p, t_liste *tab);
void	ft_star_u(int nbr, t_liste *tab);
void	ft_star_c(char c, t_liste *tab);
void	ft_star_s(char *str, t_liste *tab);
void	ft_star_x(char *str, t_liste *tab);
void	ft_star_x_2(t_liste *tab);
void	ft_star_x_3(char *str, t_liste *tab);
/* flag '-' */
void	ft_flag_minus(const char *format, t_liste *tab, int i);
void	minus_with_converter(const char *format, t_liste *tab, int i);
void	ft_minus_di(t_liste *tab, int nbr);
void	ft_minus_c(t_liste *tab, char c);
void	ft_minus_u(t_liste *tab, int nbr);
void	ft_minus_s(t_liste *tab, char *str, int i);
void	ft_minus_with_xX(char *str, t_liste *tab);
void	ft_minus_with_p(char *str, t_liste *tab);
void	minus_with_pxX(const char *format, t_liste *tab, int i);
void	minus_with_pxX2(const char *format, t_liste *tab, int i);
/* exception */
void	ft_exception(const char *format, t_liste *tab, int i);
void	ft_exception_di(long long int nbr, t_liste *tab);
void	ft_exception_u(unsigned int nbr, t_liste *tab);
void	ft_exception_xX(char *str, t_liste *tab);
void	ft_exception_s(t_liste *tab, char *str);
void	ft_exception_A(const char *format, t_liste *tab, int i);
void	ft_exception_B(const char *format, t_liste *tab, int i);
void	ft_exception_di_2(long long int nbr, t_liste *tab);
void	ft_exception_di_3(long long int nbr, t_liste *tab);
void	ft_exception_di_4(long long int nbr, t_liste *tab);
/*  char function  */
char	*ft_print_type_pointer(t_liste *tab);
/* Fonction en plus pour gagner des ligne */
void	ft_extra_u(unsigned int nbr, t_liste *tab);
void	ft_extra_x(char *str, t_liste *tab);
void	ft_extra_di(long long int nbr, t_liste *tab);
void	ft_extra_di_2(long long int nbr, t_liste *tab);
void	ft_extra_di_3(long long int nbr, t_liste *tab);
void	ft_extra_di_4(long long int nbr, t_liste *tab);
void	ft_extra_di_5(long long int nbr, t_liste *tab);
void	ft_extra_di_6(long long int nbr, t_liste *tab);
void	ft_extra_di_7(long long int nbr, t_liste *tab);
void	ft_extra_di_8(long long int nbr, t_liste *tab);
void	ft_extra_dot_converter_1(t_liste *tab, char *str, int i);
void	ft_extra_dot_converter_2(t_liste *tab, char *str, int i);
int		ft_negatif_nbr(long long int nbr, t_liste *tab);
void	ft_extra_di_9(long long int nbr, t_liste *tab);
void	ft_A(t_liste *tab, char *str);
void	ft_B(t_liste *tab, char *str);
void	ft_C(t_liste *tab, char *str);
void	ft_A_u(unsigned int nbr, t_liste *tab);
void	ft_B_u(unsigned int nbr, t_liste *tab);
void	ft_C_u(unsigned int nbr, t_liste *tab);
void	ft_D_u(unsigned int nbr, t_liste *tab);
void	ft_A_x(char *str, t_liste *tab);
void	ft_B_x(char *str, t_liste *tab);
void	ft_D_x(char *str, t_liste *tab);
void	ft_C_x(char *str, t_liste *tab);
/*  t_liste function  */
t_liste	*ft_tab_init(t_liste *tab);
t_liste	*ft_tab_reinit(t_liste *tab);

#endif
