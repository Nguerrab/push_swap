/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguerrab <nguerrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 15:31:12 by nguerrab          #+#    #+#             */
/*   Updated: 2026/11/24 15:37:15 by nguerrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

void	push_swap(t_ctr *s, int flag)
{
	flag = flag + 1;
	bubble_sort(s);
	print_arr(s->a);
}
