/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elevator_sorting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 22:27:24 by marvin            #+#    #+#             */
/*   Updated: 2024/11/04 16:22:46 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	
	Shouldn't be used for more than 10 numbers.
	This was my algorithm, but too slow.
	It sorts 500 numbers in 33k moves.
	I wanted to give it a go with my own solution.
	However, I then learned about radix and went for this solution.
*/

static void	reverse_search(t_list **stack_a, t_list **stack_b, t_list *bottom_b)
{
	if (!*stack_a || !*stack_b)
		return ;
	rrb(stack_b, 0);
	pa(stack_a, stack_b, 0);
	if (bottom_b->rank - 1 == (*stack_a)->rank)
		ra(stack_a, 0);
}

static void	elevator_execute(t_list **stack_a, t_list **stack_b)
{
	t_list	*bottom_a;
	t_list	*bottom_b;

	while (*stack_b)
	{
		bottom_a = ft_lstlast(*stack_a);
		bottom_b = ft_lstlast(*stack_b);
		if ((*stack_a)->rank - 1 == (*stack_b)->rank)
			pa(stack_a, stack_b, 0);
		else if (bottom_a->rank + 1 == (*stack_b)->rank)
		{
			pa(stack_a, stack_b, 0);
			ra(stack_a, 0);
		}
		else if (bottom_b->rank + 1 == (*stack_a)->rank
			|| bottom_b->rank - 1 == (*stack_a)->rank)
			reverse_search(stack_a, stack_b, bottom_b);
		else
			rb(stack_b, 0);
	}
}

static void	find_closest_rank(t_list **stack_a, t_list **stack_b)
{
	int	size_b;
	int	i;

	size_b = ft_lstsize(*stack_b);
	i = 0;
	while (i < size_b)
	{
		if ((*stack_b)->rank + 1 == (*stack_a)->rank
			|| (*stack_b)->rank - 1 == (*stack_a)->rank)
		{
			pa(stack_a, stack_b, 0);
			sort_2(stack_a);
			return ;
		}
		rb(stack_b, 0);
		i++;
	}
}

int	elevator_sort(t_list **stack_a, t_list **stack_b, int size)
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
	elevator_execute(stack_a, stack_b);
	return (1);
}
