/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 17:29:59 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/06/04 14:55:43 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_stack	*ft_index(t_stack **a)
{
	t_stack	*tmpa;
	t_stack	*tmpb;
	t_stack	*res;
	int		count;

	res = NULL;
	tmpa = *a;
	while (tmpa)
	{
		count = 0;
		tmpb = *a;
		while (tmpb)
		{
			if (tmpb->nb <= tmpa->nb)
				count++;
			tmpb = tmpb->next;
		}
		ft_lstaddback_ps(&res, ft_lstnew_ps(count));
		tmpa = tmpa->next;
	}
	return (res);
}

void	swap_one_batch(t_stack **a, t_stack **b, int n, int nb)
{
	int	count;

	count = 0;
	while (count < nb && *a)
	{
		if ((*a)->nb <= n * nb)
		{
			p(a, b, 'b');
			count++;
		}
		else if (*a)
			r(a, 'a');
	}
}

void	swap_batches(t_stack **a, t_stack **b)
{
	int	sizebatch;
	int	n;

	if (ft_stacksize(*a) <= 300)
		sizebatch = ft_stacksize(*a) / 7;
	else
		sizebatch = ft_stacksize(*a) / 12;
	if (sizebatch == 0)
		sizebatch = 1;
	n = 1;
	while (*a)
	{
		swap_one_batch(a, b, n, sizebatch);
		n++;
	}
}

void	sort_batches(t_stack **a, t_stack **b)
{
	int	max;

	while (*b)
	{
		max = ft_maxlst(*b);
		find_value(b, max, 'b');
		p(b, a, 'a');
	}
}

void	sort_big(t_stack **a, t_stack **b)
{
	t_stack	*stack_index;

	stack_index = ft_index(a);
	swap_batches(&stack_index, b);
	sort_batches(a, b);
	ft_stackclear(stack_index);
	return ;
}
