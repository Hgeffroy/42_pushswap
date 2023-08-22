/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 18:52:35 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/06/04 14:00:35 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/header/libft.h"
# include <stdlib.h>

typedef struct s_stack
{
	int				nb;
	struct s_stack	*next;
}	t_stack;

//Parsing
int		check_doubles(t_stack *a);
int		check_args(char *arg);
int		fill_stack(t_stack **a, char **arg);
int		returnerrors(int checkargs, t_stack *a, char **arg);
int		is_sorted(t_stack *a);

//Algo big stack
t_stack	*ft_index(t_stack **a);
void	swap_one_batch(t_stack **a, t_stack **b, int n, int nb);
void	swap_batches(t_stack **a, t_stack **b);
void	sort_batches(t_stack **a, t_stack **b);
void	sort_big(t_stack **a, t_stack **b);

//Operations
void	s(t_stack **a, char c);
void	p(t_stack **src, t_stack **dest, char c);
void	rr(t_stack **a, char c);
void	r(t_stack **a, char c);

//Lists
void	ft_lstaddback_ps(t_stack **alst, t_stack *elt);
void	ft_lstaddfront_ps(t_stack **alst, t_stack *new);
void	ft_stackclear(t_stack *a);
t_stack	*ft_lstnew_ps(int nb);
int		ft_stacksize(t_stack *a);

//Little stacks
void	find_value(t_stack **a, int value, char c);
void	sort_two(t_stack **a);
void	sort_three(t_stack **a);
void	sort_five(t_stack **a, t_stack **b, int argc);

//Utils
int		ft_maxlst(t_stack *a);
int		ft_minlst(t_stack *a);
void	freestrstr(char **a);

//Main

#endif
