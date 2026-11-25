/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisfi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 10:35:43 by aisfi             #+#    #+#             */
/*   Updated: 2026/11/24 16:01:05 by aisfi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static int	ft_sqrt(int n)
{
	int	i;

	i = 0;
	while ((i + 1) * (i + 1)  <= n)
		i++;
	return (i);
}

static void	sort(t_ctr *s, int chunk_size)
{
	t_stack	*a;
	t_stack	*b;
	int		i;
	int		j;
	int		max;
	int		max_position;

	a = s->a;
	b = s->b;
	i = 0;
	while (chunk_size > i)
	{
		max = b->arr[b->head];
		max_position = 0;
		j = 0;
		while (chunk_size - i > j)
		{
			if (max < b->arr[(s->b->head + j) % s->b->capacity])
			{
				max = b->arr[(s->b->head + j) % s->b->capacity];
				max_position = j;
			}
			j++;
		}
		while (j >= 0)
		{
			if (j == max_position)
				pa(s);
			else
				rb(s);
			j--;
		}
		i++;
	}
	i = 0;
	while (i < chunk_size)
	{
		pb(s);
		i++;
	}
}

void	chunk_sort(t_ctr *s)
{
	int	k;
	int	chunk_size;
	int	i;
	int	j;
	int	low;
	int	high;
	int	max;
	int	min;
	int	count;
	int	org_size;

	k = ft_sqrt(s->a->size);
	if (k < 1)
		k = 1;
	i = 0;
	max = s->a->arr[s->a->head];
	min = s->a->arr[s->a->head];
	while (i < s->a->size)
	{
		if (s->a->arr[(s->a->head + i) % s->a->capacity] > max)
			max = s->a->arr[(s->a->head + i) % s->a->capacity];
		if (s->a->arr[(s->a->head + i) % s->a->capacity] < min)
			min = s->a->arr[(s->a->head + i) % s->a->capacity];
		i++;
	}
	chunk_size = (s->a->size + k - 1) / k;
	i = 0;
	while (i < k)
	{
		low = min + (i * chunk_size);
		if (i + 1 == k)
			high = max;
		else
			high = low + chunk_size - 1;
		j = 0;
		count = 0;
		org_size = s->a->size;
		while (j < org_size)
		{
			if (s->a->arr[s->a->head] >= low && s->a->arr[s->a->head] <= high)
			{
				pb(s);
				count++;
			}
			else
				ra(s);
			j++;
		}
		sort(s, count);
		i++;
	}
	while (s->b->size > 0)
		pa(s);
}
