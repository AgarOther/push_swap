/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:23:14 by scraeyme          #+#    #+#             */
/*   Updated: 2024/10/29 16:44:35 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_error(void)
{
	ft_putendl_fd("Error!", 1);
	return (1);
}

void	get_number(t_list *stack, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[j] && ft_isdigit(str[j]))
		{
			ft_lstadd_back(&stack, ft_lstnew((ft_atoi(ft_substr(str, j, i)))));
			while (ft_isdigit(str[j]) && str[j])
				j++;
		}
		i = j;
	}
}

t_list	*get_stack(t_list *stack, int argc, char **argv)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	res = 0;
	while (i <= argc)
	{
		j = 0;
		while (argv[i][j])
			get_number(stack, &argv[i][j]);
		i++;
	}
}
