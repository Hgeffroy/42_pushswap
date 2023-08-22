/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 17:36:36 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/06/04 14:55:25 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	s(t_stack **a, char c)
{
	t_stack	*tmp;
	t_stack	*tmpb;
	t_stack	*tmpc;

	if (!((*a)->next))
		return ;
	tmp = *a;
	tmpb = (*a)->next;
	tmpc = tmpb->next;
	*a = tmpb;
	tmpb->next = tmp;
	tmp->next = tmpc;
	write(1, "s", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	p(t_stack **src, t_stack **dest, char c)
{
	t_stack	*tmp;

	tmp = (*src)->next;
	ft_lstaddfront_ps(dest, *src);
	*src = tmp;
	write(1, "p", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	rr(t_stack **a, char c)
{
	t_stack	*tmp;

	tmp = *a;
	if (!(tmp->next))
		return ;
	while ((tmp->next)->next)
		tmp = tmp->next;
	ft_lstaddfront_ps(a, tmp->next);
	tmp->next = NULL;
	write(1, "rr", 2);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	r(t_stack **a, char c)
{
	t_stack	*tmp;

	if (!((*a)->next))
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = NULL;
	ft_lstaddback_ps(a, tmp);
	write(1, "r", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}
