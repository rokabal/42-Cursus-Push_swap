/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_px.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:53:12 by rkassouf          #+#    #+#             */
/*   Updated: 2022/09/28 20:40:27 by rkassouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_pa(t_ps *ps)
{
	t_list	*tmp;

	if (ps->stack_b == NULL)
		return ;
	tmp = ps->stack_b;
	ps->stack_b = (ps->stack_b)->next;
	tmp->next = ps->indexed;
	ps->indexed = tmp;
	add_cmd(&ps->cmds, new_cmd("pa\n"));
}

void	ft_pb(t_ps *ps)
{
	t_list	*tmp;

	if (ps->indexed == NULL)
		return ;
	tmp = ps->indexed;
	ps->indexed = (ps->indexed)->next;
	tmp->next = ps->stack_b;
	ps->stack_b = tmp;
	add_cmd(&ps->cmds, new_cmd("pb\n"));
}
