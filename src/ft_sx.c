/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:24:57 by rkassouf          #+#    #+#             */
/*   Updated: 2022/09/28 20:42:43 by rkassouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_sa(t_ps *ps, int both)
{
	t_list	*tmp;

	tmp = ps->indexed;
	ps->indexed = (ps->indexed)->next;
	tmp->next = (ps->indexed)->next;
	(ps->indexed)->next = tmp;
	if (!both)
		add_cmd(&ps->cmds, new_cmd("sa\n"));
}

void	ft_sb(t_ps *ps, int both)
{
	t_list	*tmp;

	tmp = ps->stack_b;
	ps->stack_b = (ps->stack_b)->next;
	tmp->next = (ps->stack_b)->next;
	(ps->stack_b)->next = tmp;
	if (!both)
		add_cmd(&ps->cmds, new_cmd("sb\n"));
}

void	ft_ss(t_ps *ps, int both)
{
	ft_sa(ps, both);
	ft_sb(ps, both);
	add_cmd(&ps->cmds, new_cmd("ss\n"));
}
