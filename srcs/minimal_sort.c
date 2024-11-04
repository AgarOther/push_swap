/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimal_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:54:56 by scraeyme          #+#    #+#             */
/*   Updated: 2024/11/04 16:36:42 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_list **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a, 0);
}

void	sort_3(t_list **stack_a)
{
	if ((*stack_a)->value < (*stack_a)->next->value)
	{
		if ((*stack_a)->value > (*stack_a)->next->next->value)
			rra(stack_a, 0);
		else
		{
			rra(stack_a, 0);
			sa(stack_a, 0);
		}
		return ;
	}
	if ((*stack_a)->next->value > (*stack_a)->next->next->value)
	{
		ra(stack_a, 0);
		sa(stack_a, 0);
		return ;
	}
	else
	{
		if ((*stack_a)->value < (*stack_a)->next->next->value)
			sa(stack_a, 0);
		else
			ra(stack_a, 0);
	}
}

static void	push_and_sort(t_list **stack_a, t_list **stack_b)
{
	pa(stack_a, stack_b, 0);
	if ((*stack_a)->rank == 4)
		ra(stack_a, 0);
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	if (is_sorted((*stack_a)->next))
	{
		ra(stack_a, 0);
		return ;
	}
	while (ft_lstsize(*stack_a) > 3)
	{
		if ((*stack_a)->rank == 0 || (*stack_a)->rank == 4)
			pb(stack_a, stack_b);
		else
			ra(stack_a, 0);
	}
	if (!is_sorted(*stack_a))
		sort_3(stack_a);
	push_and_sort(stack_a, stack_b);
	push_and_sort(stack_a, stack_b);
}

int	is_sorted(t_list *stack)
{
	int		tmp;

	if (ft_lstsize(stack) == 1)
		return (1);
	while (stack->next)
	{
		tmp = stack->value;
		stack = stack->next;
		if (tmp > stack->value)
			return (0);
	}
	return (1);
}
