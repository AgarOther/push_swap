/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:19:18 by scraeyme          #+#    #+#             */
/*   Updated: 2024/11/04 14:59:35 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_small(t_list **stack_a, t_list **stack_b, int size)
{
	if (size == 2)
		sort_2(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 5)
		sort_5(stack_a, stack_b);
	else
		elevator_sort(stack_a, stack_b, size);
}

static void	radix(t_list **stack_a, t_list **stack_b, int size)
{
	int	max_bits;
	int	bits;
	int	total_elements;

	max_bits = 0;
	while ((1 << max_bits) <= size)
		max_bits++;
	bits = 0;
	while (bits < max_bits)
	{
		total_elements = size;
		while (total_elements--)
		{
			if (((*stack_a)->rank >> bits) & 1)
				ra(stack_a, 0);
			else
				pb(stack_a, stack_b);
			if (is_sorted(*stack_a))
				break ;
		}
		while (*stack_b)
			pa(stack_a, stack_b, 0);
		bits++;
	}
}

int	sort(t_list **stack_a, t_list **stack_b, int size)
{
	if (!set_ranks(stack_a, size))
	{
		ft_lstclear(stack_a);
		return (0);
	}
	if (size <= 10)
		sort_small(stack_a, stack_b, size);
	else
		radix(stack_a, stack_b, size);
	return (1);
}
