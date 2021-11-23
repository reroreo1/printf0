/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 03:28:37 by rezzahra          #+#    #+#             */
/*   Updated: 2021/11/23 18:23:32 by rezzahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int	ft_putstr_fd(char *s, int fd, int *l)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
		(*l)++;
	}
	return (*l);
}

int	ft_putchar_fd(char c, int fd, int *l)
{
	write(fd, &c, 1);
	(*l)++;
	return (*l);
}
