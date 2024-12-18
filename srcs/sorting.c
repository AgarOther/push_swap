/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:25:30 by scraeyme          #+#    #+#             */
/*   Updated: 2024/12/03 23:08:57 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	smart_rotate(t_list **stack_a, t_list **stack_b,
		void (*rotate)(t_list **stack_b, int is_rr), int size)
{
	if (size > 1 && is_optimizable(stack_b, size))
	{
		while ((*stack_b)->rank != size - 1)
			rotate(stack_b, 0);
		pa(stack_a, stack_b, 0);
		while ((*stack_b)->rank != size)
			rotate(stack_b, 0);
		pa(stack_a, stack_b, 0);
		sa(stack_a, 0);
	}
	else
	{
		while ((*stack_b)->rank != size)
			rotate(stack_b, 0);
		pa(stack_a, stack_b, 0);
	}
}

static void	ft_complete_sort(t_list **stack_a, t_list **stack_b)
{
	int	pos;
	int	size;
	int	max;

	while (*stack_b != NULL)
	{
		size = ft_lstsize(*stack_b);
		max = size - 1;
		pos = get_highest_pos(*stack_b, max);
		if (pos > size / 2)
			smart_rotate(stack_a, stack_b, rrb, max);
		else
			smart_rotate(stack_a, stack_b, rb, max);
	}
}

static void	ft_butterfly(t_list **stack_a, t_list **stack_b,
		int chunk, int size)
{
	int	chunk_elems;
	int	range;
	int	i;

	chunk_elems = size / chunk;
	range = chunk_elems;
	i = 1;
	while (*stack_a)
	{
		while (i <= range && *stack_a)
		{
			if ((*stack_a)->rank < range)
			{
				pb(stack_a, stack_b);
				if ((*stack_b)->rank > range - size / (chunk * 2))
					rb(stack_b, 0);
				i++;
			}
			else
				ra(stack_a, 0);
		}
		range += chunk_elems;
	}
	ft_complete_sort(stack_a, stack_b);
}

static void	sort_small(t_list **stack_a, t_list **stack_b, int size)
{
	if (size == 2)
		sort_2(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 5)
		sort_5(stack_a, stack_b);
	else
		ft_butterfly(stack_a, stack_b, 1, size);
}

int	sort(t_list **stack_a, t_list **stack_b, int size)
{
	if (!set_ranks(stack_a, size))
	{
		ft_lstclear(stack_a);
		return (0);
	}
	if (size <= 5)
		sort_small(stack_a, stack_b, size);
	else if (size <= 100)
		ft_butterfly(stack_a, stack_b, 3, size);
	else if (size <= 200)
		ft_butterfly(stack_a, stack_b, 4, size);
	else if (size <= 300)
		ft_butterfly(stack_a, stack_b, 5, size);
	else if (size <= 400)
		ft_butterfly(stack_a, stack_b, 6, size);
	else
		ft_butterfly(stack_a, stack_b, 8, size);
	return (1);
}
