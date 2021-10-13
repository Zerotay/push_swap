/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:05:16 by dongguki          #+#    #+#             */
/*   Updated: 2021/10/13 17:05:18 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	print_error(t_inlst **head)
{
	write(1, "Error\n", 6);
	ft_inlstclear(&((*head)->next));
	free(*head);
	exit(1);
}

void	make_inlst(t_inlst **head, char *gv)
{
	t_inlst		*tmp;
	t_inlst		*curr;
	int			i;

	i = ft_atoi(gv);
	if (i == 0 && ft_strncmp(gv, "0", 1))
		print_error(head);
	if (i == -1 && ft_strncmp(gv, "-1", 2))
		print_error(head);
	tmp = ft_inlstnew(i);
	curr = (*head)->next;
	i = (*head)->content;
	while (i--)
	{
		if (tmp->content == curr->content)
			print_error(head);
		curr = curr->next;
	}
	(*head)->content++;
	ft_inlstadd_back(head, tmp);
}

void	free_all(t_inlst **ahead, t_inlst **bhead)
{
	ft_inlstclear(&(*ahead)->next);
	ft_inlstclear(&(*bhead)->next);
	free((*ahead));
	free((*bhead));
}

void	handle_few(int gc, char **gv, t_inlst **ahead)
{
	char	**curr;
	int		i;

	if (gc == 1)
		exit(0);
	if (gc < 1)
		print_error(ahead);
	(*ahead) = ft_inlstnew(0);
	curr = ft_split(gv[1], ' ');
	i = 0;
	while (curr[i])
		i++;
	while (i)
		make_inlst(ahead, curr[--i]);
}

int	main(int gc, char **gv)
{
	t_inlst	*ahead;
	t_inlst	*bhead;

	if (gc < 3)
		handle_few(gc, gv, &ahead);
	else
	{
		ahead = ft_inlstnew(0);
		while (--gc)
			make_inlst(&ahead, gv[gc]);
	}
	ahead->next->prev = ft_inlstlast(ahead);
	ft_inlstlast(ahead)->next = ahead->next;
	ahead->next = ahead->next->prev;
	bhead = ft_inlstnew(0);
	if (ahead->content == 3)
		onlyif3(&ahead);
	else if (ahead->content == 5)
		onlyif5(&ahead, &bhead);
	else
		atob(ahead->content, &ahead, &bhead);
	free_all(&ahead, &bhead);
	return (0);
}
