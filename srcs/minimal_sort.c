/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimal_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:54:56 by scraeyme          #+#    #+#             */
/*   Updated: 2024/11/02 19:12:58 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	empty_but_3(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	while (size > 3)
	{
		pb(stack_a, stack_b);
		size--;
	}
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

void	sort_2(t_list **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a, 0);
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

int	is_fully_sorted(t_list *stack, int size)
{
	int		tmp;
	int		lst_size;
	lst_size = ft_lstsize(stack);
	if (lst_size == 1 && size == 1)
		return (1);
	else if (lst_size != size)
		return (0);
	while (stack->next)
	{
		tmp = stack->value;
		stack = stack->next;
		if (tmp > stack->value)
			return (0);
	}
	return (1);
}
