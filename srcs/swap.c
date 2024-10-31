/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:31:32 by scraeyme          #+#    #+#             */
/*   Updated: 2024/10/31 10:06:06 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **stack_a, int is_ss)
{
	t_list	*tmp;
	t_list	*last;

	tmp = *stack_a;
	while (tmp && tmp->next && tmp->next->next && tmp->next->next->next)
		tmp = tmp->next;
	last = tmp->next->next;
	last->next = tmp->next;
	tmp->next = last;
	tmp->next->next->next = NULL;
	if (!is_ss)
		ft_putendl_fd("sa", 1);
}

void	sb(t_list **stack_b, int is_ss)
{
	sa(stack_b, 1);
	if (!is_ss)
		ft_putendl_fd("sb", 1);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a, 1);
	sb(stack_b, 1);
	ft_putendl_fd("ss", 1);
}
