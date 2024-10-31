/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:03:35 by scraeyme          #+#    #+#             */
/*   Updated: 2024/10/31 21:58:23 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_push(t_list **stack_a, t_list **stack_b, int size)
{
	if (size == 1)
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

	if (!*stack_a)
		return ;
	tmp = *stack_a;
	lstsize = ft_lstsize(*stack_a);
	if (lstsize <= 2)
		small_push(stack_a, stack_b, lstsize);
	else
	{
		while (tmp->next->next)
			tmp = tmp->next;
		if (!*stack_b)
			*stack_b = tmp->next;
		else
			ft_lstlast(*stack_b)->next = tmp->next;
		tmp->next = NULL;
	}
	if (!is_pb)
		ft_putendl_fd("pa", 1);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	if (!*stack_b)
		return ;
	pa(stack_b, stack_a, 1);
	ft_putendl_fd("pb", 1);
}
