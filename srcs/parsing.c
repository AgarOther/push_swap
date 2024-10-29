/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:23:20 by scraeyme          #+#    #+#             */
/*   Updated: 2024/10/29 16:38:11 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	has_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	count_numbers(char *str)
{
	int	i;
	int	is_spaced;
	int	numbers;

	i = 0;
	is_spaced = 1;
	numbers = 0;
	if (!has_digit(str))
		return (0);
	str = ft_strtrim(str, " ");
	while (str[i])
	{
		if (is_spaced && str[i] != ' ')
		{
			numbers++;
			is_spaced = 0;
		}
		else if (!is_spaced && str[i] == ' ')
			is_spaced = 1;
		i++;
	}
	return (numbers);
}

static int	has_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

static int	get_stack_size(int argc, char **argv)
{
	int	i;
	int	size;

	i = 1;
	size = 0;
	while (i <= argc)
	{
		if (has_space(argv[i]))
			size += count_numbers(argv[i]);
		else if (has_digit(argv[i]))
			size++;
		i++;
	}
	return (size);
}

t_list	*get_stack_a(int argc, char **argv)
{
	t_list	*stack;
	int		i;
	int		size;

	i = 0;
	size = get_stack_size(argc, argv);
	if (size == 0)
		return (NULL);
	stack = malloc(size * sizeof(t_list));
	if (!stack)
		return (NULL);
	stack = get_stack(stack, argc, argv);
	return (stack);
}
