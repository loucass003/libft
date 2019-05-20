/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3_mul_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelievr <llelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:59:13 by llelievr          #+#    #+#             */
/*   Updated: 2019/05/20 23:05:52 by llelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec3		ft_vec3_mul_s(t_vec3 a, float v)
{
	a.x *= v;
	a.y *= v;
	a.z *= v;
	return (a);
}