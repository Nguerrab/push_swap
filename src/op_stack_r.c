/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_stack_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisfi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 10:37:06 by aisfi             #+#    #+#             */
/*   Updated: 2026/11/22 10:04:07 by nguerrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ra(t_ctr *s)//valid
{
	if (stack_shift_up(s->a))
		write(1, "ra\n", 3);
}

void	rb(t_ctr *s)//valid
{
	if (stack_shift_up(s->b))
		write(1, "rb\n", 3);
}

void	rr(t_ctr *s)//valid
{
	int	a;
	int	b;

	a = stack_shift_up(s->a);
	b = stack_shift_up(s->b);
	if (!a && !b)
		return ;
	write(1, "rr\n", 3);
}

void	rra(t_ctr *s)//valid
{
	if (stack_shift_down(s->a))
		write(1, "rra\n", 4);
}

void	rrb(t_ctr *s)//valid
{
	if (stack_shift_down(s->b))
		write(1, "rrb\n", 4);
}
