/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:14:48 by rkassouf          #+#    #+#             */
/*   Updated: 2022/09/28 20:44:31 by rkassouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	sort_2(t_ps *ps)
{
	if ((ps->indexed)->content > (ps->indexed)->next->content)
		ft_sa(ps, 0);
}

static void	sort_3(t_ps *ps)
{
	int		i;
	int		nb[3];
	t_list	*tmp;

	tmp = ps->indexed;
	i = -1;
	while (tmp)
	{
		nb[++i] = tmp->content;
		tmp = tmp->next;
	}
	if (((nb[0] > nb[1]) && (nb[2] > nb[0]))
		|| ((nb[0] > nb[1]) && (nb[1] > nb[2]))
		|| ((nb[1] > nb[2]) && (nb[2] > nb[0])))
		ft_sa(ps, 0);
	if (((nb[0] > nb[1]) && (nb[1] > nb[2]))
		|| ((nb[1] > nb[0]) && (nb[0] > nb[2])))
		ft_rra(ps, 0);
	if (((nb[1] > nb[2]) && (nb[2] > nb[0]))
		|| ((nb[0] > nb[2]) && (nb[2] > nb[1])))
		ft_ra(ps, 0);
}

static void	sort_5(t_ps *ps)
{
	int	rot;

	while (ft_lstsize(ps->indexed) > 3)
	{
		rot = find_rot(&ps->indexed);
		while (rot > 0)
		{
			ft_ra(ps, 0);
			rot--;
		}
		while (rot < 0)
		{
			ft_rra(ps, 0);
			rot ++;
		}
		ft_pb(ps);
	}
	sort_3(ps);
	while (ft_lstsize(ps->stack_b))
		ft_pa(ps);
}

void	sort_small(t_ps *ps)
{
	if (ps->size == 2)
		sort_2(ps);
	else
		sort_5(ps);
}
