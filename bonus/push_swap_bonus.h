/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 23:39:09 by scraeyme          #+#    #+#             */
/*   Updated: 2024/11/14 23:57:08 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
#include <unistd.h>
#include "../includes/push_swap.h"
#include "../libft.h"
#include "../get_next_line/get_next_line.h"

typedef struct s_parse
{
	char			*str;
	struct s_parse	*next;
}				t_parse;

t_parse	*ft_parsenew(char *str);

#endif