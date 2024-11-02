/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_rank.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 10:21:49 by scraeyme          #+#    #+#             */
/*   Updated: 2024/11/02 20:08:25 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*sort_int_tab(int *tab, int size)
{
	int		i;
	int		j;
	int		tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (tab);
}

static int	*get_int_list(t_list *stack_a, int size)
{
	int		*num_list;
	int		i;

	i = 0;
	num_list = malloc(size * sizeof(int));
	if (!num_list)
		return (0);
	while (stack_a)
	{
		num_list[i] = stack_a->value;
		stack_a = stack_a->next;
		i++;
	}
	num_list = sort_int_tab(num_list, size);
	return (num_list);
}

int	get_rank(int value, int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (value == tab[i])
			return (i + 1);
		i++;
	}
	return (-1);
}

int	set_ranks(t_list **stack_a, int size)
{
	int		*num_list;
	int		rank;
	int		tmp_rank;
	t_list	*tmp;

	num_list = get_int_list(*stack_a, size);
	if (!num_list)
		return (0);
	tmp = *stack_a;
	rank = 0;
	while (tmp)
	{
		rank++;
		tmp_rank = get_rank(tmp->value, num_list, size);
		if (tmp_rank == -1)
		{
			free(num_list);
			return (0);
		}
		tmp->rank = tmp_rank;
		tmp = tmp->next;
	}
	free(num_list);
	return (1);
}
