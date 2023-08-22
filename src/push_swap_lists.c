/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lists.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:52:52 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/06/04 14:55:00 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_lstaddfront_ps(t_stack **alst, t_stack *new)
{
	if (!alst || !new)
		return ;
	new->next = *alst;
	*alst = new;
}

void	ft_lstaddback_ps(t_stack **a, t_stack *elt)
{
	t_stack	*tmp;

	if (!a)
		return ;
	if (!*a)
	{
		*a = elt;
		return ;
	}
	tmp = *a;
	while ((tmp->next) != NULL)
		tmp = tmp->next;
	tmp->next = elt;
}

t_stack	*ft_lstnew_ps(int nb)
{
	t_stack	*elt;

	elt = (t_stack *)malloc(sizeof(t_stack));
	if (!elt)
		return (NULL);
	elt->nb = nb;
	elt->next = NULL;
	return (elt);
}

void	ft_stackclear(t_stack *a)
{
	t_stack	*tmp;

	if (!a)
		return ;
	if (!(a->next))
	{
		free(a);
		return ;
	}
	tmp = a;
	a = a->next;
	while (a)
	{
		free(tmp);
		tmp = a;
		a = a->next;
	}
	free(tmp);
}

int	ft_stacksize(t_stack *a)
{
	int	count;

	count = 0;
	while (a)
	{
		a = a->next;
		count ++;
	}
	return (count);
}
