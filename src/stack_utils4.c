/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguerrab <nguerrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 19:49:25 by nguerrab          #+#    #+#             */
/*   Updated: 2026/11/24 15:10:40 by nguerrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ifelse(int flag, int argc, char **argv, t_ctr *s)
{
	int	c;

	if (flag == 0)
		c = add_to(s, argc - 1, argv + 1);
	else
		c = add_to(s, argc - 2, argv + 2);
	if (c == 0)
	{
		free(s);
		error();
	}
}

void	stack_swap(t_stack *s)//valid
{
	int	tmp;

	if (s->size >= 2)
	{
		tmp = s->arr[s->head];
		s->arr[s->head] = s->arr[(s->head + 1) % s->capacity];
		s->arr[(s->head + 1) % s->capacity] = tmp;
	}
}

void	stack_free(t_stack *s)//valid
{
	if (!s)
		return ;
	free(s->arr);
	free(s);
}

int	stack_pop(t_stack *s, int *val)//valid; return = val or ERROR
{
	if (s->size == 0)
		return (0);
	*val = s->arr[s->head];
	s->head = (s->head + 1) % s->capacity;
	s->size--;
	return (1);
}
