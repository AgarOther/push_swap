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
	t_list	*tmp;

	i = 0;
	j = 0;
	size = ft_lstsize(*stack);
	tmp = *stack;
	while (tmp)
	{
		tmp->reach = j;
		if (i - 1 < (size - 1) / 2)
		{
			if (size % 2 == 0 || (size % 2 && i < (size - 1) / 2))
				j++;
		}
		else
			j--;
		tmp = tmp->next;
		i++;
	}
}
