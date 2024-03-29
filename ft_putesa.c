/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putesa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanghel <aanghel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 13:58:03 by aanghel           #+#    #+#             */
/*   Updated: 2022/02/07 23:47:17 by aanghel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_digitesa(uintptr_t nb, char *base)
{
	if (nb < 0)
	{
		ft_char('-');
		ft_digitesa(-nb, base);
	}
	else if (nb >= 16)
	{
		ft_digitesa(nb / 16, base);
		ft_char(base[nb % 16]);
	}
	else if (nb >= 0)
	{
		ft_char(base[nb % 16]);
	}
}

int	ft_lenesa(uintptr_t nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

int	ft_putesa(uintptr_t num)
{
	int		count;
	char	*base;

	write(1, "0x", 2);
	count = 2;
	count += ft_lenesa(num);
	base = "0123456789abcdef";
	ft_digitesa(num, base);
	return (count);
}
