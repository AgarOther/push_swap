/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:03:35 by scraeyme          #+#    #+#             */
/*   Updated: 2024/11/01 09:52:28 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_push(t_list **stack_a, t_list **stack_b, int size)
{
	t_list	*tmp;
	
	if (size == 0)
	{
		tmp = *stack_b;
		while (tmp->next->next)
			tmp = tmp->next;
		*stack_a = tmp->next;
		(*stack_a)->next = NULL;
		tmp->next = NULL;
	}
	else if (size == 1)
	{
		ft_lstlast(*stack_b)->next = *stack_a;
		*stack_a = NULL;
	}
	else
	{
		ft_lstlast(*stack_b)->next = (*stack_a)->next;
		(*stack_a)->next = NULL;
	}
}

void	pa(t_list **stack_a, t_list **stack_b, int is_pb)
{
	t_list	*tmp;
	int		lstsize;

	tmp = *stack_b;
	lstsize = ft_lstsize(*stack_b);
	if (lstsize <= 2)
		small_push(stack_b, stack_a, lstsize);
	else
	{
		while (tmp->next->next)
			tmp = tmp->next;
		if (!*stack_a)
			*stack_a = tmp->next;
		else
			ft_lstlast(*stack_a)->next = tmp->next;
		tmp->next = NULL;
	}
	if (!is_pb)
		ft_putendl_fd("pa", 1);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	pa(stack_b, stack_a, 1);
	ft_putendl_fd("pb", 1);
}
