/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 01:52:25 by rezzahra          #+#    #+#             */
/*   Updated: 2021/11/23 21:21:23 by rezzahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *buf, ...)
{
    va_list             ap;
    int                 i;
    int                 l;
    unsigned long long  n;

    i = 0;
    l = 0;
    va_start(ap, buf);
    while(buf[i])
    {
        if(buf[i] != '%')
        {   
            l = ft_putchar_fd(buf[i], 1,&l);
            i++;
        }
        else
        {
            i++;
            if(buf[i] == '%')
            {   
                l = ft_putchar_fd(buf[i], 1, &l);
                i++;
            }
            else if (buf[i] == 'p')
            {
                n = va_arg(ap, unsigned long long);
                write(1,"0x",2);
                l += 2;
                l = ft_putstr_fd(ft_itoa_base(n, "0123456789abcdef"), 1 ,&l);
                i++;
            }
            else if (buf[i] == 'i' || buf[i] == 'd')
            {
                n = va_arg(ap, int);
                l = ft_putstr_fd(ft_itoa(n), 1, &l);
                i++;
            }
            else if (buf[i] == 'x' || buf[i] == 'X')
            {
                n = va_arg(ap, unsigned int);
                if (buf[i] == 'X')
                    l = ft_putstr_fd(ft_itoa_base(n,"0123456789ABCDEF"), 1, &l);
                else
                    l = ft_putstr_fd(ft_itoa_base(n,"0123456789abcdef"), 1, &l);
                i++;
            }
            else if (buf[i] == 'c')
            {
                n = va_arg(ap, int);
                l = ft_putchar_fd(n,1,&l);
                i++;
            }
            else if (buf[i] == 's')
            {
                l = ft_putstr_fd(va_arg(ap, char*), 1, &l);
                i++;
            }
            else if (buf[i] == 'u')
            {
                n = va_arg(ap, unsigned int);
                l = ft_putstr_fd(ft_itoa_base(n, "0123456789"), 1, &l);
                i++;
            }
        }
        va_end(ap);
    }
    return l;
}
