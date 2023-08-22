/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 17:29:52 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/06/03 18:59:37 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	is_sorted(t_stack *a)
{
	t_stack	*tmpa;
	t_stack	*tmpb;

	tmpa = a->next;
	tmpb = a;
	while (tmpb->next)
	{
		if (tmpa->nb < tmpb->nb)
			return (-1);
		tmpa = tmpa->next;
		tmpb = tmpb->next;
	}
	return (1);
}

int	check_doubles(t_stack *a)
{
	t_stack	*tmpa;
	t_stack	*tmpb;

	tmpa = a;
	tmpb = a->next;
	while (tmpa->next)
	{
		tmpb = tmpa->next;
		while (tmpb)
		{
			if (tmpa->nb == tmpb->nb)
				return (-2);
			tmpb = tmpb->next;
		}
		tmpa = tmpa->next;
	}
	return (1);
}

int	check_args(char *arg)
{
	int	i;
	int	arglen;

	i = 0;
	if (ft_isstrdigit(arg) == -1)
		return (-1);
	arglen = ft_strlen(arg);
	if (arglen > 11)
		return (-1);
	if (ft_atoi(arg) > 2147483647 || ft_atoi(arg) < -2147483648)
		return (-1);
	i++;
	return (1);
}

int	fill_stack(t_stack **a, char **arg)
{
	int	i;

	i = 0;
	if (check_args(arg[i]) == -1)
		return (-1);
	while (arg[i])
	{
		ft_lstaddback_ps(a, ft_lstnew_ps(ft_atoi(arg[i])));
		i++;
	}
	return (1);
}

int	returnerrors(int checkargs, t_stack *a, char **arg)
{
	if (checkargs == -2)
	{
		write (2, "Error\n", 6);
		ft_stackclear(a);
		return (-1);
	}
	if (checkargs == -1)
	{
		write (2, "Error\n", 6);
		ft_stackclear(a);
		freestrstr(arg);
		return (-1);
	}
	if (checkargs == 0)
	{
		ft_stackclear(a);
		freestrstr(arg);
		return (-1);
	}
	return (1);
}
