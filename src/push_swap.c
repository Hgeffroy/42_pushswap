/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:56:24 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/06/04 14:54:12 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	sort(t_stack **a, t_stack **b)
{
	int	stacksize;

	stacksize = ft_stacksize(*a);
	if (stacksize == 2)
	{
		sort_two(a);
		ft_stackclear(*a);
		return ;
	}
	if (stacksize == 3)
	{
		sort_three(a);
		ft_stackclear(*a);
		return ;
	}
	if (stacksize <= 5)
	{
		sort_five(a, b, stacksize + 1);
		ft_stackclear(*a);
		ft_stackclear(*b);
		return ;
	}
	sort_big(a, b);
	ft_stackclear(*a);
	ft_stackclear(*b);
}

int	main(int argc, char **argv)
{
	int		checkargs;
	int		i;
	t_stack	*a;
	t_stack	*b;
	char	**arg;

	if (argc <= 1)
		return (1);
	a = NULL;
	i = 0;
	while (++i < argc)
	{
		arg = ft_split(argv[i], ' ');
		checkargs = fill_stack(&a, arg);
		if (checkargs != 1)
			return (returnerrors(checkargs, a, arg));
		freestrstr(arg);
	}
	checkargs = check_doubles(a);
	if (checkargs != 1)
		return (returnerrors(checkargs, a, arg));
	if (is_sorted(a) == 1)
		return (ft_stackclear(a), 1);
	b = NULL;
	return (sort(&a, &b), 1);
}
