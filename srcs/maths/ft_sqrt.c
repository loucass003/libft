/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelievr <llelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:49:12 by llelievr          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/03/01 15:30:00 by llelievr         ###   ########.fr       */
=======
/*   Updated: 2019/02/24 21:05:21 by llelievr         ###   ########.fr       */
>>>>>>> 458652633c483e8b529787afdbf603059c226184
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float		ft_sqrt(float n)
{
	float	out;
	float	last;

	if (n <= 0)
		return (0);
	last = 0;
	out = n / 2;
	while (out != last)
	{
		last = out;
		out = 0.5 * (out + n / out);
	}
	return (out);
}
