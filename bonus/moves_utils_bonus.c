/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:57:18 by scraeyme          #+#    #+#             */
/*   Updated: 2024/12/02 22:04:47 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static t_line	*get_lines_as_list(void)
{
	char	*tmp;
	t_line	*lines;

	lines = NULL;
	while (!lines || tmp)
	{
		tmp = get_next_line(1);
		if (!tmp)
			break ;
		if (!lines)
			lines = ft_linenew(tmp);
		else
			ft_lineadd_back(&lines, ft_linenew(tmp));
	}
	free(tmp);
	return (lines);
}

static int	ft_mvcmp(char *str, char *move, int len)
{
	int	i;
	int	nl;

	i = 0;
	nl = 0;
	while (str[i] && i < len)
	{
		if (str[i] != move[i])
			return (0);
		i++;
	}
	if (str[i])
	{
		while (str[i])
		{
			if (str[i] != '\n' || (str[i] == '\n' && nl))
				return (0);
			else if (str[i] == '\n' && !nl)
				nl = 0;
			i++;
		}
	}
	return (1);
}

int	check_moves(char **moves)
{
	int	i;

	i = 0;
	if (!moves || !*moves)
		return (1);
	while (moves[i])
	{
		if ((ft_mvcmp(moves[i], "ra", 2) || ft_mvcmp(moves[i], "rb", 2)
				|| ft_mvcmp(moves[i], "rr", 2) || ft_mvcmp(moves[i], "sa", 2)
				|| ft_mvcmp(moves[i], "sb", 2) || ft_mvcmp(moves[i], "ss", 2)
				|| ft_mvcmp(moves[i], "rra", 3) || ft_mvcmp(moves[i], "rrb", 3)
				|| ft_mvcmp(moves[i], "rrr", 3) || ft_mvcmp(moves[i], "pa", 2)
				|| ft_mvcmp(moves[i], "pb", 2)))
		{
			i++;
			continue ;
		}
		else
			return (0);
	}
	return (1);
}

char	**get_moves(int i)
{
	t_line	*lines;
	t_line	*head;
	char	**moves;

	lines = get_lines_as_list();
	if (!lines)
		return (NULL);
	head = lines;
	moves = malloc(sizeof(char *) * (ft_linesize(lines) + 1));
	if (!moves)
	{
		free(lines);
		return (NULL);
	}
	while (lines)
	{
		moves[i] = lines->line;
		lines = lines->next;
		i++;
	}
	ft_lineclear(&head);
	moves[i] = 0;
	return (moves);
}

void	do_move(t_list **stack_a, t_list **stack_b, char *move)
{
	if (ft_mvcmp(move, "rra", 3))
		rra(stack_a);
	else if (ft_mvcmp(move, "rrb", 3))
		rrb(stack_b);
	else if (ft_mvcmp(move, "rrr", 3))
		rrr(stack_a, stack_b);
	else if (ft_mvcmp(move, "ra", 2))
		ra(stack_a);
	else if (ft_mvcmp(move, "rb", 2))
		rb(stack_b);
	else if (ft_mvcmp(move, "rr", 2))
		rr(stack_a, stack_b);
	else if (ft_mvcmp(move, "sa", 2))
		sa(stack_a);
	else if (ft_mvcmp(move, "sb", 2))
		sb(stack_b);
	else if (ft_mvcmp(move, "ss", 2))
		ss(stack_a, stack_b);
	else if (ft_mvcmp(move, "pa", 2))
		pa(stack_a, stack_b);
	else if (ft_mvcmp(move, "pb", 2))
		pb(stack_a, stack_b);
}
