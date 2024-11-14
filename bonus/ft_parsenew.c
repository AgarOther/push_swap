/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsenew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 23:56:40 by scraeyme          #+#    #+#             */
/*   Updated: 2024/11/14 23:57:01 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_parse	*ft_parsenew(char *str)
{
	t_parse	*node;

	node = malloc(sizeof(t_parse));
	if (!node)
		return (NULL);
	node->str = str;
	node->next = NULL;
	return (node);
}
