/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelievr <llelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 23:15:59 by llelievr          #+#    #+#             */
/*   Updated: 2019/02/18 02:56:21 by llelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	elem_put(t_json_element **alst, t_json_element *n)
{
	t_json_element *e;

	if (!*alst)
	{
		*alst = n;
		return ;
	}
	e = *alst;
	while (e->next)
		e = e->next;
	e->next = n;
}

static t_json_value	*parse_elements(t_json_state *s, t_json_array *arr)
{
	char			c;
	t_json_element	*elem;

	if (s->pos < s->len)
	{
		if (!(elem = (t_json_element *)malloc(sizeof(t_json_element))))
			return (NULL);
		elem->next = NULL;
		if (!(elem->value = parse_value(s)))
			return (json_free_ret(elem));//FREE elem
		elem_put(&arr->elements, elem);
		arr->elems_count++;
		c = json_skip_ws(s);
		if (c == ']')
			return ((t_json_value *)arr);
		else if (c  == ',')
			return (parse_elements(s, arr));
	}
	return (NULL);
}

t_json_value	*json_parse_array(t_json_state *state)
{
	t_json_array		*arr;
	char				c;

	if (state->pos < state->len)
	{
		c = json_skip_ws(state);
		if (state->pos >= state->len)
			return (NULL);
		if (!(arr = (t_json_array *)malloc(sizeof(t_json_array))))
			return (NULL);
		arr->super.type = JSON_ARRAY;
		arr->elems_count = 0;
		arr->elements = NULL;
		if (c == ']')
			return ((t_json_value *)arr);
		state->pos--;
		if (!parse_elements(state, arr))
		{
			if (arr->elements)
				json_free_array(&arr->elements);
			return (json_free_ret(arr)); // FREE arr
		}
		return ((t_json_value *)arr);
	}
	return (NULL);
}