/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 01:57:34 by rezzahra          #+#    #+#             */
/*   Updated: 2021/11/23 20:52:54 by rezzahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_F
# define FT_PRINTF_F


#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

int 	ft_putstr_fd(char *s, int fd, int *l);
int 	ft_putchar_fd(char c, int fd, int *l);
char	*ft_itoa(int nb);
int     ft_printf(const char *buf, ...);
char	*ft_itoa_base(unsigned long long nb,char *base);
#endif