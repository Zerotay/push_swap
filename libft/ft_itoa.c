/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 13:11:31 by dongguki          #+#    #+#             */
/*   Updated: 2021/10/13 14:43:38 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*ans;
	size_t	i;
	int		j;

	i = 1;
	if (n < 0)
		i = 2;
	j = n;
	while (n /= 10)
		i++;
	ans = ft_calloc(i + 1, 1);
	if (!ans)
		return (0);
	ans[0] = '0';
	if (j < 0)
		ans[0] = '-';
	while (j)
	{
		n = j % 10;
		if (n < 0)
			n *= -1;
		ans[--i] = '0' + n;
		j /= 10;
	}
	return (ans);
}
