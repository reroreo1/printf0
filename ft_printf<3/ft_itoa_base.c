/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 22:25:37 by rezzahra          #+#    #+#             */
/*   Updated: 2021/11/23 21:00:15 by rezzahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
static int	count_nb_base(unsigned long long nb ,char *base)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= ft_strlen(base);
		i++;
	}
	return (i);
}

static char	*allocate(int size)
{
	char	*ptr;

	ptr = malloc(size * sizeof(char));
	if (!ptr)
		return (0);
	return (ptr);
}



char	*ft_itoa_base(unsigned long long nb,char *base)
{
	char	*ptr;
	int		len;
	int		i;

	len = count_nb_base(nb, base);
	i = len;
	ptr = allocate(len + 1);
	if (!ptr)
		return (NULL);
	len--;
	while (len >= 0)
	{
		ptr[len--] = base[nb % ft_strlen(base)];
		nb /= ft_strlen(base);
	}
	ptr[i] = '\0';
	return (ptr);
}

