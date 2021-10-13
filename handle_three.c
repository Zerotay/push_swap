/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_three.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:05:03 by dongguki          #+#    #+#             */
/*   Updated: 2021/10/13 17:05:04 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	onlyif3(t_inlst **ahead)
{
	int	a;
	int	b;
	int	c;

	a = (*ahead)->next->content;
	b = (*ahead)->next->prev->content;
	c = (*ahead)->next->prev->prev->content;
	if (a > b && a > c)
	{
		ra(ahead);
		if (b > c)
			sa(ahead);
		return ;
	}
	if (c > b && c > a)
	{
		if (a > b)
			sa(ahead);
		return ;
	}
	rra(ahead);
	if (a < c)
		sa(ahead);
	return ;
}

int	aif3(t_inlst **ahead, t_inlst **bhead)
{
	int	a;
	int	b;
	int	c;

	a = (*ahead)->next->content;
	b = (*ahead)->next->prev->content;
	c = (*ahead)->next->prev->prev->content;
	if (a > b)
	{
		sa(ahead);
		if (c > a)
			return (0);
	}
	if (c > b)
		return (0);
	ra(ahead);
	sa(ahead);
	rra(ahead);
	if (c < a && c < b)
		sa(ahead);
	return (0);
}

int	bif3(t_inlst **ahead, t_inlst **bhead)
{
	int	a;
	int	b;
	int	c;

	a = (*bhead)->next->content;
	b = (*bhead)->next->prev->content;
	c = (*bhead)->next->prev->prev->content;
	pa(ahead, bhead);
	if (c > b && c > a)
		sb(bhead);
	pa(ahead, bhead);
	if (!(a > b && a > c))
		sa(ahead);
	pa(ahead, bhead);
	aif3(ahead, bhead);
	return (0);
}
