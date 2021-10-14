/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 00:00:20 by dongguki          #+#    #+#             */
/*   Updated: 2021/10/14 16:05:45 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(t_inlst **head)
{
	write(1, "Error\n", 6);
	ft_inlstclear(&((*head)->next));
	free(*head);
	exit(1);
}

void	free_all(t_inlst **ahead, t_inlst **bhead)
{
	ft_inlstclear(&((*ahead)->next));
	ft_inlstclear(&((*bhead)->next));
	free((*ahead));
	free((*bhead));
}

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}