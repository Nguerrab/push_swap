/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_U2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguerrab <nguerrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 14:30:56 by nguerrab          #+#    #+#             */
/*   Updated: 2026/11/26 14:43:11 by nguerrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	repetition(t_ctr *s, int n, int *i)
{
	int	j;

	j = 0;
	while (j < (*i))
	{
		if (s->a->arr[j] == n)
			return (0);
		j++;
	}
	return (1);
}

void	print_arr(t_stack *s)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (i < s->size)
	{
		index = (s->head + i) % s->capacity;
		ft_putnbr(s->arr[index]);
		write(1, ", ", 2);
		i++;
	}
}

static void	print(long nb)
{
	char	c;

	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		print(nb / 10);
	c = (nb % 10) + '0';
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	long	nb;

	nb = (long)n;
	print(nb);
}

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
