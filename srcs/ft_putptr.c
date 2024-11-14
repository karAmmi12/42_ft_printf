/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:10:31 by kammi             #+#    #+#             */
/*   Updated: 2023/11/29 15:10:36 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putptr_base(unsigned long nbr, unsigned long base)
{
	size_t	len;
	char	*charset;

	charset = "0123456789abcdef";
	if (nbr < base)
		return (ft_putchar(charset[nbr]));
	else
	{
		len = ft_putptr_base(nbr / base, base);
		return (len + ft_putptr_base(nbr % base, base));
	}
}

size_t	ft_putptr(unsigned long ptr)
{
	size_t	len;

	len = 0;
	if (ptr == 0)
		return (len += ft_putstr("(nil)"));
	else
	{
		len += write(1, "0x", 2);
		len += ft_putptr_base(ptr, 16);
	}
	return (len);
}
