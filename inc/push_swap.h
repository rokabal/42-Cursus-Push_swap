/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 23:14:45 by rkassouf          #+#    #+#             */
/*   Updated: 2022/09/28 15:41:14 by rkassouf         ###   ########.fr       */
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

typedef struct s_cmd
{
	char			*cmd;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_ps
{
	int		size;
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*indexed;
	t_cmd	*cmds;
}	t_ps;

/*
 **		Operations
 */

void	ft_pa(t_ps *ps);
void	ft_pb(t_ps *ps);
void	ft_sa(t_ps *ps, int both);
void	ft_sb(t_ps *ps, int both);
void	ft_ss(t_ps *ps, int both);
void	ft_ra(t_ps *ps, int both);
void	ft_rb(t_ps *ps, int both);
void	ft_rr(t_ps *ps);
void	ft_rra(t_ps *ps, int both);
void	ft_rrb(t_ps *ps, int both);
void	ft_rrr(t_ps *ps);

/*
 **		Sorting
 */

void	sort_small(t_ps *ps);
void	radix_sort(t_ps *ps);
int		sorted(t_list **stack);

/*
 **		Utils and parsing
 */

void	lst_to_index(t_ps *ps);
int		find_rot(t_list **stack);
void	lst_free(t_list **stack);
void	set_stack(int argc, char **argv, t_list **stack_a);

/*
 **		Commands
 */

t_cmd	*new_cmd(char *cmd);
void	print_cmds(t_cmd **cmds);
void	add_cmd(t_cmd **cmds, t_cmd *new_cmd);

#endif
