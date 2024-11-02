/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:19:18 by scraeyme          #+#    #+#             */
/*   Updated: 2024/11/02 20:19:40 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	elevator_algo(t_list **stack_a, t_list **stack_b)
{
	t_list	*bottom_a;
	
	bottom_a = ft_lstlast(*stack_a);
	while (*stack_b)
	{
		if ((*stack_a)->rank - 1 == (*stack_b)->rank)
			pa(stack_a, stack_b, 0);
		else if (bottom_a->rank + 1 == (*stack_b)->rank)
		{
			pa(stack_a, stack_b, 0);
			ra(stack_a, 0);
			bottom_a = ft_lstlast(*stack_a);
		}
		else
			rb(stack_b, 0);
	}
}

void	find_closest_rank(t_list **stack_a, t_list **stack_b)
{
	int		i;

	i = 0;
	while (1)
	{
		if ((*stack_b)->rank + 1 == (*stack_a)->rank
			|| (*stack_b)->rank - 1 == (*stack_a)->rank)
		{
			rb(stack_b, 0);
			pa(stack_a, stack_b, 0);
			sort_2(stack_a);
			return ;
		}
		rb(stack_b, 0);
		i++;
	}
}

int	sort(t_list **stack_a, t_list **stack_b, int size)
{
	if (!set_ranks(stack_a, size))
	{
		ft_lstclear(stack_a);
		return (0);
	}
	while (size > 1)
	{
		pb(stack_a, stack_b);
		size--;
	}
	find_closest_rank(stack_a, stack_b);
	elevator_algo(stack_a, stack_b);
	return (1);
}
