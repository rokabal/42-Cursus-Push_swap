/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:22:50 by rkassouf          #+#    #+#             */
/*   Updated: 2022/09/28 20:43:07 by rkassouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_ra(t_ps *ps, int both)
{
	t_list	*first;
	t_list	*last;

	if (ps->indexed == NULL)
		return ;
	if ((ps->indexed)->next == NULL)
		return ;
	first = ps->indexed;
	last = ps->indexed;
	while (last->next != NULL)
		last = last->next;
	ps->indexed = first->next;
	first->next = NULL;
	last->next = first;
	if (!both)
		add_cmd(&ps->cmds, new_cmd("ra\n"));
}

void	ft_rb(t_ps *ps, int both)
{
	t_list	*first;
	t_list	*last;

	if (ps->stack_b == NULL)
		return ;
	if ((ps->stack_b)->next == NULL)
		return ;
	first = ps->stack_b;
	last = ps->stack_b;
	while (last->next != NULL)
		last = last->next;
	ps->stack_b = first->next;
	first->next = NULL;
	last->next = first;
	if (!both)
		add_cmd(&ps->cmds, new_cmd("rb\n"));
}

void	ft_rr(t_ps *ps)
{
	ft_ra(ps, 1);
	ft_rb(ps, 1);
	add_cmd(&ps->cmds, new_cmd("rr\n"));
}
