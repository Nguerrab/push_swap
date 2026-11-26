/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisfi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 10:52:54 by aisfi             #+#    #+#             */
/*   Updated: 2026/11/24 14:37:30 by nguerrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	bubble_sort(t_ctr *s)//valid
{
	int		i;
	int		s1;
	int		s2;

	if (s->b->size == 0 && stack_is_sorted(s->a))
		return ;
	while (s->a->size > 0)
	{
		i = 0;
		while (i < s->a->size - 1)
		{
			s1 = s->a->arr[s->a->head];
			s2 = s->a->arr[(s->a->head + 1) % s->a->capacity];
			if (s1 < s2)
				sa(s);
			ra(s);
			i++;
			if (s->b->size == 0 && stack_is_sorted(s->a))
				return ;
		}
		pb(s);
	}
	while (s->b->size > 0)
		pa(s);
}
