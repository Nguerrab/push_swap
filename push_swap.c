/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguerrab <nguerrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 15:31:12 by nguerrab          #+#    #+#             */
/*   Updated: 2026/11/27 12:00:09 by aisfi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

void	push_swap(t_ctr *s, int flag)
{
	flag = flag + 1;
	//chunk_sort(s);
	radix_sort(s);
	print_arr(s->a);
}
