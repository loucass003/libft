/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelievr <llelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:14:30 by llelievr          #+#    #+#             */
/*   Updated: 2019/10/04 03:02:21 by llelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dst, int car, size_t len)
{
	const uint16_t	b = ((uint16_t)car << 8 | (uint16_t)car);
	const uint32_t	c = ((uint32_t)b << 16 | (uint32_t)b);
	const uint64_t	d = ((uint64_t)c << 32 | (uint64_t)c);

	while (len >= 8)
	{
		len -= 8;
		((uint64_t *)dst)[len / 8] = d;
	}
	while (len >= 4)
	{
		len -= 4;
		((uint32_t *)dst)[len / 4] = c;
	}
	while (len >= 2)
	{
		len -= 2;
		((uint16_t *)dst)[len / 2] = b;
	}
	while (len >= 1)
		((uint8_t *)dst)[--len] = car;
	return (dst);
}
