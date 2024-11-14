/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:10:13 by kammi             #+#    #+#             */
/*   Updated: 2023/11/29 15:10:19 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putnbr(long nbr, int base, int u_case)
{
	size_t	len;
	char	*charset;

	if (u_case)
		charset = "0123456789ABCDEF";
	else
		charset = "0123456789abcdef";
	if (nbr < 0)
	{
		write(1, "-", 1);
		return (ft_putnbr(-nbr, base, u_case) + 1);
	}
	else if (nbr < base)
		return (ft_putchar(charset[nbr]));
	else
	{
		len = ft_putnbr(nbr / base, base, u_case);
		return (len + ft_putnbr(nbr % base, base, u_case));
	}
}
