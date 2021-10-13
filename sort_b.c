/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 09:01:40 by dongguki          #+#    #+#             */
/*   Updated: 2021/10/13 16:47:31 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	conquer_b(int n, t_inlst **ahead, t_inlst **bhead)
{
	if (n == 3)
		return (bif3(ahead, bhead));
	else if (n == 2)
	{
		if ((*bhead)->next->content < (*bhead)->next->prev->content)
			sb(bhead);
		pa(ahead, bhead);
		pa(ahead, bhead);
	}
	else if (n == 1)
		pa(ahead, bhead);
	return (0);
}

int	zero_init_b(int *a, int *b, int *c)
{
	*a = 0;
	*b = 0;
	*c = 0;
	return (0);
}

int	init_pivot_b(int *p1, int *p2, t_inlst **ahead, t_inlst **bhead)
{
	*p1 = (*bhead)->next->content;
	*p2 = (*bhead)->next->prev->content;
	if ((*bhead)->next->content > (*bhead)->next->next->content)
	{
		*p1 = (*bhead)->next->prev->content;
		*p2 = (*bhead)->next->content;
	}
	return (0);
}

int	rewind_stack_b(int nra, int nrb, t_inlst **ahead, t_inlst **bhead)
{
	while (nra && nrb)
	{
		rrr(ahead, bhead);
		nra--;
		nrb--;
	}
	while (nra--)
		rra(ahead);
	while (nrb--)
		rrb(bhead);
	return (0);
}

int	btoa(int n, t_inlst **ahead, t_inlst **bhead)
{
	int	p[2];
	int	nra;
	int	npa;
	int	nrb;

	if (n < 4)
		return (conquer_b(n, ahead, bhead));
	zero_init_b(&nra, &npa, &nrb);
	init_pivot_b(&p[0], &p[1], ahead, bhead);
	while (n--)
	{
		if ((*bhead)->next->content < p[0])
			nrb += rb(bhead);
		else
		{
			npa += pa(ahead, bhead);
			if ((*ahead)->next->content < p[1])
				nra += ra(ahead);
		}
	}
	atob(npa - nra, ahead, bhead);
	rewind_stack_b(nra, nrb, ahead, bhead);
	atob(nra, ahead, bhead);
	btoa(nrb, ahead, bhead);
	return (0);
}
