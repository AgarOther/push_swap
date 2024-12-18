/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:53:33 by scraeyme          #+#    #+#             */
/*   Updated: 2024/12/03 22:00:52 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <limits.h>

// Butterfly
int		get_highest_pos(t_list *stack_b, int size);
int		is_optimizable(t_list **stack_b, int max);
int		get_current_pos(t_list *stack_b, int n);

// Parsing
t_list	*get_stack_a(int argc, char **argv);
int		has_duplicates(int argc, char **argv, int i, int j);
int		has_overflow(char *str);
int		print_error(void);
int		has_space(char *str);
int		has_digit(char *str);
int		is_valid(int argc, char **argv);
int		set_ranks(t_list **stack_a, int size);
int		is_sorted(t_list *stack);

// Resolution
void	sort_2(t_list **stack_a);
void	sort_3(t_list **stack_a);
void	sort_5(t_list **stack_a, t_list **stack_b);
int		sort(t_list **stack_a, t_list **stack_b, int size);
int		elevator_sort(t_list **stack_a, t_list **stack_b, int size);

// Operations
void	sa(t_list **stack_a, int is_ss);
void	sb(t_list **stack_b, int is_ss);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b, int is_pb);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a, int is_rr);
void	rb(t_list **stack_b, int is_rr);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a, int is_rr);
void	rrb(t_list **stack_b, int is_rr);
void	rrr(t_list **stack_a, t_list **stack_b);
#endif