/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:27:07 by scraeyme          #+#    #+#             */
/*   Updated: 2024/12/02 14:09:52 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ra(t_list **stack_a)
{
	t_list	*head;
	t_list	*last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	head = *stack_a;
	last = ft_lstlast(*stack_a);
	*stack_a = head->next;
	last->next = head;
	head->next = NULL;
}

void	rb(t_list **stack_b)
{
	if (!*stack_b || !(*stack_b)->next)
		return ;
	ra(stack_b);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
