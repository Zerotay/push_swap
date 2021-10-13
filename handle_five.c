#include <push_swap.h>

int	find_second(t_inlst *ahead)
{
	int	first;
	int	tmp;
	int	i;

	tmp = ahead->next->content;
	i = ahead->content;
	while (i--)
	{
		if (tmp > ahead->next->content)
			tmp = ahead->next->content;
		ahead->next = ahead->next->next;
	}
	first = tmp;
	tmp = ahead->next->content;
	if (first == ahead->next->content)
		tmp = ahead->next->next->content;
	i = ahead->content;
	while (i--)
	{
		if (tmp > ahead->next->content && ahead->next->content != first)
			tmp = ahead->next->content;
		ahead->next = ahead->next->next;
	}
	return (tmp);
}

void	onlyif5(t_inlst **ahead, t_inlst **bhead)
{
	int	i;
	int	second;

	second = find_second(*ahead);
	i = 0;
	while (i < 2)
	{
		if ((*ahead)->next->content <= second)
		{
			pb(ahead, bhead);
			i++;
		}
		else
			ra(ahead);
	}
	onlyif3(ahead);
	if ((*bhead)->next->content < (*bhead)->next->prev->content)
		sb(bhead);
	pa(ahead, bhead);
	pa(ahead, bhead);
}
