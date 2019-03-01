/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelievr <llelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 23:00:59 by llelievr          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/03/01 15:44:03 by llelievr         ###   ########.fr       */
=======
/*   Updated: 2019/03/01 18:16:53 by llelievr         ###   ########.fr       */
>>>>>>> fix number
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static double	parse_floating(t_json_state *state)
{
	char	c;
	double	part;
	int		pos;

	part = 0;
	pos = state->pos;
	c = state->str[state->pos++];
	while (ft_isdigit(c) && state->pos < state->len)
	{
		part = part * 10 + (c - '0');
		c = state->str[state->pos++];
	}
	return (part / (ft_pow(10, (state->pos - 1 - pos))));
}

t_json_value	*json_parse_number(t_json_state *state)
{
	char			sign;
	char 			c;
	t_json_number	*num;

	if (state->pos < state->len)
	{
		c = state->str[state->pos++];
		if (!(num = (t_json_number *)malloc(sizeof(t_json_number))))
			return (NULL);
		num->value = 0;
		num->super.type = JSON_NUMBER;
		if (c == '+' || c == '-')
		{
			sign = (c == '+' ? 1 : -1);
			c = state->str[state->pos++];
		}
		while (ft_isdigit(c) && state->pos < state->len)
		{
			num->value = num->value * 10 + (c - '0');
			c = state->str[state->pos++];
		}
		if (c == '.')
			num->value += parse_floating(state);
		num->value *= sign;
		state->pos--;
		return ((t_json_value *)num);
	}
	return (NULL);
}

double			*json_to_number(t_json_value *value)
{
	if (!value || value->type != JSON_NUMBER)
		return (NULL);
	return (&(((t_json_number *)value)->value));
}

double			*json_get_number(t_json_object *obj, char *key)
{
	return (json_to_number(json_object_get(obj, key)));
}
