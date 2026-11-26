/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_ut.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguerrab <nguerrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 13:45:43 by nguerrab          #+#    #+#             */
/*   Updated: 2026/11/26 14:31:44 by nguerrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	sqre(int n)
{
	long long	i;

	i = 0;
	while ((i + 1) * (i + 1) < n)
		i++;
	if (i == 0)
		i = 1;
	return ((int)i);
}

int	*ranking(t_stack *a)
{
	int	i;
	int	j;
	int	r;
	int	*rank;

	i = 0;
	rank = malloc(sizeof(int) * a->size);
	if (!rank)
		return (NULL);
	while (i < a->size)
	{
		j = 0;
		r = 0;
		while (j < a->size)
		{
			if (a->arr[j] < a->arr[i])
				r++;
			j++;
		}
		rank[r] = a->arr[i];
		i++;
	}
	return (rank);
}

int	fft_max(t_stack *s)
{
	int	max;
	int	index;
	int	i;
	int	r;

	i = 0;
	max = s->arr[s->head];
	r = s->head;
	while (i < s->size)
	{
		index = (s->head + i) % s->capacity;
		if (s->arr[index] > max)
		{
			max = s->arr[index];
			r = index;
		}
		i++;
	}
	return (r);
}

int	ft_index(int n, int *arr, t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->capacity)
	{
		if (n == arr[i])
			break ;
		i++;
	}
	return (i);
}
