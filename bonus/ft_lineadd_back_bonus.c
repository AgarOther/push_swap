/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lineadd_back_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:48:47 by scraeyme          #+#    #+#             */
/*   Updated: 2024/12/02 12:44:43 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_lineadd_back(t_line **lst, t_line *new)
{
	if (*lst)
		ft_linelast(*lst)->next = new;
	else
		*lst = new;
}
