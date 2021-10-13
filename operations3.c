/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:05:32 by dongguki          #+#    #+#             */
/*   Updated: 2021/10/13 17:05:33 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	ra(t_inlst **head)
{
	(*head)->next = (*head)->next->prev;
	write(1, "ra\n", 3);
	return (1);
}

int	rb(t_inlst **head)
{
	(*head)->next = (*head)->next->prev;
	write(1, "rb\n", 3);
	return (1);
}

int	rr(t_inlst **ahead, t_inlst **bhead)
{
	(*ahead)->next = (*ahead)->next->prev;
	(*bhead)->next = (*bhead)->next->prev;
	write(1, "rr\n", 3);
	return (1);
}
