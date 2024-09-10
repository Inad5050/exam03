/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonz3 <dangonz3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:36:44 by dangonz3          #+#    #+#             */
/*   Updated: 2024/09/10 20:17:19 by dangonz3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "unistd.h"
#include "stdarg.h"

void putstr(char *str, int *len)
{
    if (!str)
        str = "(null)";
    while (*str)
        len += write(1, str, 1);
}

int ptf(const char *s, va_list args, int i, int len)
{
    if (!s[i])
        return (len);
    if (s[i] == '%' && s[i + 1] == 's')
        return (ptf(s, args, i + 2, len + putstr(va_arg(args, char *), &len)));
    if (s[i] == '%' && s[i + 1] == 'd')
        return (ptf(s, args, i + 2, len + putnum(va_arg(args, int), 10, &len)));
    if (s[i] == '%' && s[i + 1] == 'x')
        return (ptf(s, args, i + 2, len + putnum(va_arg(args, int), 16, &len)));
    write(1, &s[i], 1);
    return (ptf(s, args, i + 1, len + 1));
}

int ft_printf(const char *s, ...)
{
    va_list args;
    int     len;
    
    len = 0;
    va_start(args, s);
    len =+ ptf(s, args, 0, 0);
    va_end(args);
    return (len);
}

int putnum(int num, int base, int *len)
{
    char    *hexa = "0123456789abcdef";
    
    if (num < 0)
    {
        *len += write(1, "-", 1);
        num *= -1;
    }






}

