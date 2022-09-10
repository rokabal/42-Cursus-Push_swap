/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:14:48 by rkassouf          #+#    #+#             */
/*   Updated: 2022/09/10 23:22:45 by rkassouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	sort_2(t_list **stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->content)
		ft_sa(stack_a, 0);
}

static void	sort_3(t_list **stack_a)
{
	int		i;
	int		nb[3];
	t_list	*tmp;

	tmp = *stack_a;
	i = -1;
	while (tmp)
	{
		nb[++i] = tmp->content;
		tmp = tmp->next;
	}
	if (((nb[0] > nb[1]) && (nb[2] > nb[0]))
		|| ((nb[0] > nb[1]) && (nb[1] > nb[2]))
		|| ((nb[1] > nb[2]) && (nb[2] > nb[0])))
		ft_sa(stack_a, 0);
	if (((nb[0] > nb[1]) && (nb[1] > nb[2]))
		|| ((nb[1] > nb[0]) && (nb[0] > nb[2])))
		ft_rra(stack_a, 0);
	if (((nb[1] > nb[2]) && (nb[2] > nb[0]))
		|| ((nb[0] > nb[2]) && (nb[2] > nb[1])))
		ft_ra(stack_a, 0);
}

static int	find_rot(t_list **stack)
{
	int		smallest;
	int		rot;
	t_list	*tmp;

	smallest = find_smallest(stack);
	rot = 0;
	tmp = *stack;
	while (tmp->content != smallest)
	{
		rot++;
		tmp = tmp->next;
	}
	if (rot <= 2)
		return (rot);
	return (rot - ft_lstsize(*stack));
}

static void	sort_5(t_list **stack_a, t_list **stack_b)
{
	int	rot;

	while (ft_lstsize(*stack_a) > 3)
	{
		rot = find_rot(stack_a);
		while (rot > 0)
		{
			ft_ra(stack_a, 0);
			rot--;
		}
		while (rot < 0)
		{
			ft_rra(stack_a, 0);
			rot ++;
		}
		ft_pb(stack_a, stack_b);
	}
	sort_3(stack_a);
	while (ft_lstsize(*stack_b))
		ft_pa(stack_a, stack_b);
}

void	sort_small(t_list **stack_a, t_list **stack_b, int size)
{
	if (size == 2)
		sort_2(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size <= 5)
		sort_5(stack_a, stack_b);
}
