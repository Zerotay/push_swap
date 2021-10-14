/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:05:06 by dongguki          #+#    #+#             */
/*   Updated: 2021/10/14 15:56:59 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_inlst	*ft_inlstnew(int content)
{
	t_inlst	*s;

	s = (t_inlst *)malloc(sizeof(t_inlst));
	if (!s)
		return (ft_inlstnew(content));
	s->content = content;
	s->next = 0;
	s->prev = 0;
	return (s);
}

t_inlst	*ft_inlstlast(t_inlst *lst)
{
	t_inlst	*curr;

	if (!lst)
		return (0);
	curr = lst;
	while (curr->next)
		curr = curr->next;
	return (curr);
}

void	ft_inlstadd_back(t_inlst **lst, t_inlst *new)
{
	t_inlst	*curr;

	if (!new || !lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	curr = ft_inlstlast(*lst);
	new->prev = curr;
	curr->next = new;
}

void	ft_inlstclear(t_inlst **lst)
{
	t_inlst	*curr;
	t_inlst	*currnext;

	if (!(*lst))
		return ;
	curr = *lst;
	while (curr)
	{
		currnext = curr->next;
		free(curr);
		if (currnext == *lst)
			break ;
		curr = currnext;
	}
	*lst = 0;
}
