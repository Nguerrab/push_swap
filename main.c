/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguerrab <nguerrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 15:38:19 by nguerrab          #+#    #+#             */
/*   Updated: 2026/11/24 14:07:07 by aisfi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/push_swap.h"

void    chunk_sort(t_ctr *s);

int	main()
{
	t_ctr *c;
	t_stack	*a;
	int		i;
	
	c = ctr_int(27);
	if (!c)
		return (1);
	a = c->a;
	stack_push(60, a);	
	stack_push(55, a);	
	stack_push(12, a);	
	stack_push(5, a);	
	stack_push(2, a);	
	stack_push(22, a);	
	stack_push(9, a);	
	stack_push(-19, a);	
	stack_push(40, a);	
	stack_push(25, a);	
	stack_push(71, a);	
	stack_push(10, a);	
	stack_push(-6, a);	
	stack_push(3, a);	
	stack_push(6, a);	
	stack_push(0, a);	
	stack_push(4, a);	
	stack_push(82, a);	
	stack_push(62, a);	
	stack_push(15, a);	
	stack_push(14, a);	
	stack_push(32, a);	
	stack_push(11, a);	
	stack_push(99, a);	
	stack_push(8, a);	
	stack_push(64, a);	
	stack_push(28, a);	

	i = 0;
	while (i < a->size)
	{
		printf("[%d] ", a->arr[(a->head + i) % a->capacity]);
		i++;
	}
	printf("\n");
	
	chunk_sort(c);

	i = 0;
	while (i < a->size)
	{
		printf("[%d] ", a->arr[(a->head + i) % a->capacity]);
		i++;
	}

	printf("\n");
	stack_free(c->a);
	stack_free(c->b);
	free(c);
	return (0);
}
