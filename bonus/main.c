/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 23:39:41 by scraeyme          #+#    #+#             */
/*   Updated: 2024/11/15 00:04:40 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_parse	*get_instructions(t_list **stack_a, t_list **stack_b)
{
	t_parse	*new;
	t_parse	*instructions;
	char	*buffer;
	int		i;

	instructions = NULL;
	buffer = get_next_line(1);
	while (!buffer)
	{
		new = ft_parsenew(buffer);
		if (!new)
		{
			free(buffer);
			return (NULL);
		}
		if (!instructions)
			instructions = new;
		else
			ft_lstadd_back(&instructions, new);
		free(buffer);
		buffer = get_next_line(1);
	}
	if (buffer)
		free(buffer);
	return (instructions);
}

int	execute_instructions(t_list **stack_a, t_list **stack_b)
{
	int		size;

	size = ft_lstsize(stack_a);
	if (size == 1)
	{
		ft_lstclear(&stack_a);
		ft_putendl_fd("OK", 1);
		return (1);
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (!can_parse(argc, argv))
		return (0);
	stack_a = get_stack_a(argc - 1, argv);
	stack_b = NULL;
	if (!stack_a || !execute_instructions(&stack_a, &stack_b))
	{
		if (stack_a)
			ft_lstclear(&stack_a);
		ft_putendl_fd("Error", 1);
		return (1);
	}
	if (!is_sorted(stack_a))
		ft_putendl_fd("KO", 1);
	else
		ft_putendl_fd("OK", 1);
	ft_lstclear(&stack_a);
	if (stack_b)
		ft_lstclear(&stack_b);
}
