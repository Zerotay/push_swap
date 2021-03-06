/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:05:35 by dongguki          #+#    #+#             */
/*   Updated: 2021/10/13 23:38:43 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(t_inlst **head)
{
	(*head)->next = (*head)->next->next;
	write(1, "rra\n", 4);
	return (1);
}

int	rrb(t_inlst **head)
{
	(*head)->next = (*head)->next->next;
	write(1, "rrb\n", 4);
	return (1);
}

int	rrr(t_inlst **ahead, t_inlst **bhead)
{
	(*ahead)->next = (*ahead)->next->next;
	(*bhead)->next = (*bhead)->next->next;
	write(1, "rrr\n", 4);
	return (1);
}
