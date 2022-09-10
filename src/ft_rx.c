/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:22:50 by rkassouf          #+#    #+#             */
/*   Updated: 2022/09/10 14:39:33 by rkassouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_ra(t_list **stack_a, int rr)
{
	t_list	*first;
	t_list	*last;

	if (*stack_a == NULL)
		return ;
	if ((*stack_a)->next == NULL)
		return ;
	first = *stack_a;
	last = *stack_a;
	while (last->next != NULL)
		last = last->next;
	*stack_a = first->next;
	first->next = NULL;
	last->next = first;
	if (!rr)
		write(1, "ra\n", 3);
}

void	ft_rb(t_list **stack_b, int rr)
{
	t_list	*first;
	t_list	*last;

	if (*stack_b == NULL)
		return ;
	if ((*stack_b)->next == NULL)
		return ;
	first = *stack_b;
	last = *stack_b;
	while (last->next != NULL)
		last = last->next;
	*stack_b = first->next;
	first->next = NULL;
	last->next = first;
	if (!rr)
		write(1, "rb\n", 3);
}

void	ft_rr(t_list **stack_a, t_list **stack_b)
{
	ft_ra(stack_a, 1);
	ft_rb(stack_b, 1);
	write(1, "rr\n", 3);
}
