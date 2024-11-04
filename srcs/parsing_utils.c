/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:23:14 by scraeyme          #+#    #+#             */
/*   Updated: 2024/11/04 16:39:38 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_overflow(char *str)
{
	int		i;
	int		j;
	long	val;

	i = 0;
	j = 0;
	while (str[i])
	{
		val = ft_atol(&str[i]);
		if (val > INT_MAX || val < INT_MIN)
			return (1);
		i += ft_intlen(val) + (val < 0);
	}
	return (0);
}

int	has_space(char *str)
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

static void	get_element(t_list **stack, char *str, int i, int j)
{
	int		num;
	t_list	*new;
	char	*strnum;

	while (str[i])
	{
		if (!has_space(&str[i]))
			num = ft_atoi(&str[i], 0);
		else
		{
			while (str[i] && str[i] == ' ')
				i++;
			j = i;
			while (str[j] && (ft_isdigit(str[j]) || str[j] == '-'))
				j++;
			strnum = ft_substr(&str[i], 0, j);
			num = ft_atoi(strnum, 1);
		}
		new = ft_lstnew(num);
		if (!stack)
			stack = &new;
		else
			ft_lstadd_back(stack, new);
		i += ft_intlen(num) + (num < 0);
	}
}

t_list	*get_stack_a(int argc, char **argv)
{
	t_list	*stack;
	int		i;

	stack = NULL;
	i = 1;
	while (i <= argc)
	{
		argv[i] = ft_strtrim(argv[i], " ");
		if (has_overflow(argv[i]))
		{
			free(argv[i]);
			return (NULL);
		}
		get_element(&stack, argv[i], 0, 0);
		free(argv[i]);
		i++;
	}
	return (stack);
}

int	is_valid(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (!has_digit(argv[i]))
			return (0);
		while (argv[i][j])
		{
			if (argv[i][j] == '-' && argv[i][j + 1] == '-')
				return (0);
			else if (argv[i][j] == '-' && argv[i][j + 1] == '0')
				return (0);
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != ' '
				&& argv[i][j] != '-')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
