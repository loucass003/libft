/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arraylist_indexof.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelievr <llelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 19:42:47 by llelievr          #+#    #+#             */
/*   Updated: 2019/04/28 19:48:35 by llelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arraylist.h"

int		arraylist_indexof(t_arraylist *arr, void *elem)
{
	int	i;

	i = -1;
	while (++i < arr->len)
	{
		if (arr->values[i] == elem)
			return (i);
	}
	return (-1);
}
