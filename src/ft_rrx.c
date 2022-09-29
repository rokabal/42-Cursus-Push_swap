/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 22:38:07 by rkassouf          #+#    #+#             */
/*   Updated: 2022/09/28 20:43:21 by rkassouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_rra(t_ps *ps, int both)
{
	t_list	*tmp;
	t_list	*last;

	if (ps->indexed == NULL)
		return ;
	if ((ps->indexed)->next == NULL)
		return ;
	tmp = ps->indexed;
	last = ps->indexed;
	while (last->next != NULL)
	{
		tmp = last;
		last = last->next;
	}
	last->next = ps->indexed;
	ps->indexed = last;
	tmp->next = NULL;
	if (!both)
		add_cmd(&ps->cmds, new_cmd("rra\n"));
}

void	ft_rrb(t_ps *ps, int both)
{
	t_list	*tmp;
	t_list	*last;

	if (ps->stack_b == NULL)
		return ;
	if ((ps->stack_b)->next == NULL)
		return ;
	tmp = ps->stack_b;
	last = ps->stack_b;
	while (last->next != NULL)
	{
		tmp = last;
		last = last->next;
	}
	last->next = ps->stack_b;
	ps->stack_b = last;
	tmp->next = NULL;
	if (!both)
		add_cmd(&ps->cmds, new_cmd("rrb\n"));
}

void	ft_rrr(t_ps *ps)
{
	ft_rra(ps, 1);
	ft_rrb(ps, 1);
	add_cmd(&ps->cmds, new_cmd("rrr\n"));
}
