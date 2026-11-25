/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisfi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 10:35:43 by aisfi             #+#    #+#             */
/*   Updated: 2026/11/25 18:59:40 by aisfi            ###   ########.fr       */
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

static int	position_in_rank(int index, t_stack *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < s->capacity)
	{
		if (s->arr[(s->head + index) % s->capacity] > s->arr[(s->head + i) % s->capacity])
			j++;
		i++;
	}
	return (j);
}

static int	*rank(t_stack *s)
{
	int	*arr;
	int	i;

	arr = malloc(s->capacity * sizeof(int));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < s->capacity)
	{
		arr[position_in_rank(i, s)] = s->arr[(s->head + i) % s->capacity];
			i++;
	}
	return (arr);
}

static int	index_of(int n, int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (n == arr[i])
			break ;
		i++;
	}
	return (i);
}

static void	sort(t_ctr *s, int chunk_size, int *rank)
{
	t_stack	*a;
	t_stack	*b;
	int		i;
	int		j;
	int		max;
	int		max_position;
	int		value;

	a = s->a;
	b = s->b;
	i = 0;
	while (chunk_size > i)
	{
		max = index_of(b->arr[b->head], rank, a->capacity);
		max_position = 0;
		j = 0;
		while (chunk_size - i > j)
		{
			value = index_of(b->arr[(b->head + j) % b->capacity], rank, b->capacity);
			if (max < value)
			{
				max = value;
				max_position = j;
			}
			j++;
		}
		while (max != index_of(b->arr[b->head], rank, b->capacity))
			rb(s);
		while (j >= 0)
		{
			rrb(s);
			j--;
		}
		pa(s);
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
	int	count;
	int	org_size;
	int	*rk;
	int	value;

	rk = rank(s->a);
	if (!rk)
		return ;
	k = ft_sqrt(s->a->capacity) / 2;
	if (k < 1)
		k = 1;
	chunk_size = (s->a->size + k - 1) / k;
	i = 0;
	while (i < k)
	{
		low = i * chunk_size;
		high = low + chunk_size - 1;
		j = 0;
		count = 0;
		org_size = s->a->size;
		while (j < org_size)
		{
			value = index_of(s->a->arr[s->a->head], rk, s->a->capacity);
			if (value >= low && value <= high)
			{
				pb(s);
				count++;
			}
			else
				ra(s);
			j++;
		}
		sort(s, count, rk);
		i++;
	}
	while (s->b->size > 0)
		pa(s);
	free(rk);
}
