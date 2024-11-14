/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:11:02 by kammi             #+#    #+#             */
/*   Updated: 2023/12/13 17:03:58 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_format(va_list args, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_putptr(va_arg(args, unsigned long)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int), 10, 0));
	else if (c == 'u')
		return (ft_putnbr(va_arg(args, unsigned int), 10, 0));
	else if (c == 'x')
		return (ft_putnbr(va_arg(args, unsigned int), 16, 0));
	else if (c == 'X')
		return (ft_putnbr(va_arg(args, unsigned int), 16, 1));
	else if (c == '%')
		return (ft_putchar('%'));
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += ft_format(args, format[i + 1]);
			i++;
		}
		else
		{
			ft_putchar(format[i]);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
/*
#include <limits.h>
#include <stdio.h>
int     main(void)
{
        int     count_ft;
        int     count_std;

        ft_printf("%p, %p", (void *)LONG_MIN, (void *)LONG_MAX);
        printf("\n%p, %p\n", (void *)LONG_MIN, (void *)LONG_MAX);


        count_ft = ft_printf("Char: %c\n", 'A');
        count_std = printf("Char: %c\n", 'A');
        printf("Chars written by ft_printf: %d, Chars written by printf: %d\n",
                count_ft, count_std);

        char *str = "Hello, World!";
        count_ft = ft_printf("String: %s\n", str);
        count_std = printf("String: %s\n", str);
        printf("Chars written by ft_printf: %d, Chars written by printf: %d\n",
                count_ft, count_std);

        int num = -123456;
        count_ft = ft_printf("Decimal: %d\n", num);
        count_std = printf("Decimal: %d\n", num);
        printf("Chars written by ft_printf: %d, Chars written by printf: %d\n",
                count_ft, count_std);
        unsigned int hex_num = 122254;
        count_ft = ft_printf("Hexadecimal: %x\n", hex_num);
        count_std = printf("Hexadecimal: %x\n", hex_num);
        printf("Chars written by ft_printf: %d, Chars written by printf: %d\n",
                count_ft, count_std);

        void *ptr = (void *)0x12345678;
        count_ft = ft_printf("Pointer: %p\n", ptr);
        count_std = printf("Pointer: %p\n", ptr);
        printf("Chars written by ft_printf: %d, Chars written by printf: %d\n",
                count_ft, count_std);

        unsigned int unsigned_num = 67890;
        count_ft = ft_printf("Unsigned: %u\n", unsigned_num);
        count_std = printf("Unsigned: %u\n", unsigned_num);
        printf("Chars written by ft_printf: %d, Chars written by printf: %d\n",
                count_ft, count_std);

        count_ft = ft_printf("Percentage: %%\n");
        count_std = printf("Percentage: %%\n");
        printf("Chars written by ft_printf: %d, Chars written by printf: %d\n",
                count_ft, count_std);

        return (0);
}
*/
