/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_U.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguerrab <nguerrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 20:02:34 by nguerrab          #+#    #+#             */
/*   Updated: 2026/11/26 14:39:11 by nguerrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h" 

static	void	skip_spaces(char *str, int *i)
{
	while (str[*i] == ' ')
		(*i)++;
}

static	int	parse_number(char *str, int *i, long long *result, long long *lm)
{
	long long	number;
	int			sg;

	sg = 1;
	number = 0;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
		{
			sg = -1;
			*lm = (long long)INT_MAX + 1;
		}
		(*i)++;
	}
	if (str[*i] < '0' || str[*i] > '9')
		return (0);
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		if (number > (*lm - (str[*i] - '0')) / 10)
			return (0);
		number = number * 10 + (str[*i] - '0');
		(*i)++;
	}
	*result = number * sg;
	return (1);
}

static	int	add_number(int number, t_ctr *s, int *i)
{
	if (repetition(s, number, i) == 0)
		return (0);
	s->a->arr[*i] = number;
	s->a->size++;
	(*i)++;
	return (1);
}

int	valid_add(char *av, t_ctr *s, int *i)
{
	long long	limit;
	long long	result;
	int			j;

	j = 0;
	while (av[j])
	{
		result = 0;
		limit = INT_MAX;
		skip_spaces(av, &j);
		if (av[j] == '\0')
			break ;
		if (parse_number(av, &j, &result, &limit) == 0)
			return (0);
		if (av[j] != ' ' && av[j] != '\0')
			return (0);
		if (add_number((int)result, s, i) == 0)
			return (0);
	}
	return (1);
}
