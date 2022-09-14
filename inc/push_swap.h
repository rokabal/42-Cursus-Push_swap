/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 23:14:45 by rkassouf          #+#    #+#             */
/*   Updated: 2022/09/14 11:16:42 by rkassouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/inc/libft.h"
# include <stdio.h>

# define ERR	"Error\n"

void	ft_sa(t_list **stack_a, int ss);
void	ft_sb(t_list **stack_b, int ss);
void	ft_ss(t_list **stack_a, t_list **stack_b);
void	ft_ra(t_list **stack_a, int rr);
void	ft_rb(t_list **stack_b, int rr);
void	ft_rr(t_list **stack_a, t_list **stack_b);
void	ft_rra(t_list **stack_a, int rrr);
void	ft_rrb(t_list **stack_b, int rrr);
void	ft_rrr(t_list **stack_a, t_list **stack_b);
void	ft_pa(t_list **stack_a, t_list **stack_b);
void	ft_pb(t_list **stack_a, t_list **stack_b);
void	lst_free(t_list **stack);
void	set_stack(int argc, char **argv, t_list **stack_a);
void	sort_small(t_list **stack_a, t_list **stack_b, int size);
void	lst_to_index(t_list **stack, t_list **indexed);
void	radix_sort(t_list **indexed, t_list **stack_b);
int		find_rot(t_list **stack);
int		sorted(t_list **stack);

#endif
