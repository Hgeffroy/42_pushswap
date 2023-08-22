/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 17:30:10 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/06/04 14:54:40 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	sort_two(t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	tmp = tmp->next;
	if ((*a)->nb > tmp->nb)
		s(a, 'a');
	return ;
}

void	sort_three(t_stack **a)
{
	int		max;
	int		min;
	t_stack	*tmp;

	max = ft_maxlst(*a);
	min = ft_minlst(*a);
	tmp = *a;
	while (tmp->next)
	{
		if (tmp->nb == min && (tmp->next)->nb == max)
			s(a, 'a');
		tmp = tmp->next;
	}
	tmp = *a;
	if (tmp->nb == max)
	{
		while (tmp->next)
			tmp = tmp->next;
		if (tmp->nb == min)
			s(a, 'a');
	}
	if ((*a)->nb == max)
		r(a, 'a');
	else if (!((*a)->nb == min))
		rr(a, 'a');
}

void	find_value(t_stack **a, int value, char c)
{
	int		count;
	t_stack	*tmp;

	count = 0;
	tmp = *a;
	while (tmp->nb != value)
	{
		count++;
		tmp = tmp->next;
	}
	if (count > ft_stacksize(*a) / 2)
	{
		while ((*a)->nb != value)
			rr(a, c);
	}
	else
	{
		while ((*a)->nb != value)
			r(a, c);
	}
}

void	sort_five(t_stack **a, t_stack **b, int argc)
{
	int	min;
	int	max;

	min = ft_minlst(*a);
	max = ft_maxlst(*a);
	find_value(a, max, 'a');
	p(a, b, 'b');
	if (argc == 6)
	{
		find_value(a, min, 'a');
		p(a, b, 'b');
	}
	sort_three(a);
	while (*b)
		p(b, a, 'a');
	r(a, 'a');
}
