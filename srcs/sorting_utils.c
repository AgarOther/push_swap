/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:00:27 by scraeyme          #+#    #+#             */
/*   Updated: 2024/12/02 17:48:27 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_reach(t_list **stack)
{
	int		i;
	int		j;
	int		size;
	int		med;
	t_list	*tmp;

	i = 1;
	j = 0;
	size = ft_lstsize(*stack);
	med = ((size + 1) / 2) + (size % 2 == 0);
	tmp = *stack;
	while (tmp)
	{
		tmp->reach = j;
		if (i < med)
			j++;
		else if (i > med || (size % 2 == 0 && i == med))
			j--;
		tmp = tmp->next;
		i++;
	}
}
