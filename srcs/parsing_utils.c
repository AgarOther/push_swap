/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:23:14 by scraeyme          #+#    #+#             */
/*   Updated: 2024/11/07 23:47:29 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_overflow(char *str)
{
	int		i;
	int		j;
	int		len;
	long	val;

	i = 0;
	while (str[i])
	{
		j = i;
		len = 0;
		while (str[j] && ft_isdigit(str[j]))
		{
			j++;
			len++;
		}
		if (len > 12 && !is_valid_int(&str[i]))
			return (1);
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

static void	put_element(t_list **stack, char *str)
{
	int		i;
	int		num;
	t_list	*new;

	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		num = ft_atoi(&str[i], 0);
		new = ft_lstnew(num);
		if (!*stack)
			*stack = new;
		else
			ft_lstadd_back(stack, new);
		while (str[i] && (ft_isdigit(str[i]) || ft_isoperand(str[i])))
			i++;
	}
	free(str);
	return ;
}

t_list	*get_stack_a(int argc, char **argv)
{
	char	*str;
	t_list	*stack;
	int		i;

	str = ft_strdup(argv[1]);
	if (!str)
		return (NULL);
	stack = NULL;
	i = 2;
	while (i <= argc)
	{
		str = ft_strjoin(str, argv[i], i != argc);
		if (!str || has_overflow(str))
		{
			if (stack)
				ft_lstclear(&stack);
			if (str)
				free(str);
			return (NULL);
		}
		i++;
	}
	str = ft_strtrim(str, " ");
	put_element(&stack, str);
	return (stack);
}

int	is_valid(int argc, char **argv)
{
	int	i;
	int	j;
	int	operand;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		if (!has_digit(argv[i]) || argv[0] == 0)
			return (0);
		while (argv[i][j])
		{
			operand = ft_isoperand(argv[i][j]);
			if (operand && !ft_isdigit(argv[i][j + 1]))
				return (0);
			else if (ft_isdigit(argv[i][j]) && ft_isoperand(argv[i][j + 1]))
				return (0);
			else if (!ft_isdigit(argv[i][j]) && !operand && argv[i][j] != ' ')
				return (0);
			j++;
		}
	}
	return (1);
}
