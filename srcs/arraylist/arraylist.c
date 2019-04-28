/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arraylist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelievr <llelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 19:34:12 by llelievr          #+#    #+#             */
/*   Updated: 2019/04/28 19:55:18 by llelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_arraylist	*create_arraylist(int capacity)
{
	t_arraylist	*arr;

	if (!(arr = (t_arraylist *)malloc(sizeof(t_arraylist) + sizeof(void *) * capacity)))
		return (NULL);
	arr->capacity = capacity;
	return (arr);
}

void		arraylist_clear(t_arraylist *arr, void (*del_val)(void *elem))
{
	int		i;

	if (del_val)
	{
		i = -1;
		while (++i < (arr)->len)
			del_val((arr)->values[i]);
	}
	free(arr);
}
