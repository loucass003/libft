/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelievr <llelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 03:20:27 by llelievr          #+#    #+#             */
/*   Updated: 2019/03/03 18:40:46 by llelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_color		ft_i_color(int c)
{
	return ((t_color) {
		.a = (c >> 24) & 0xFF,
		.r = (c >> 16) & 0xFF,
		.g = (c >> 8) & 0xFF,
		.b = c & 0xFF,
	});
}
