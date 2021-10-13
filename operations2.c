#include <push_swap.h>

void	push(t_inlst **head, t_inlst **curr)
{
	if ((*head)->content == 0)
	{
		(*head)->next = *curr;
		(*curr)->next = *curr;
		(*curr)->prev = *curr;
	}
	else
	{
		(*curr)->next = (*head)->next->next;
		(*curr)->prev = (*head)->next;
		(*head)->next->next->prev = *curr;
		(*head)->next->next = *curr;
		(*head)->next = *curr;
	}
}

int	pa(t_inlst **ahead, t_inlst **bhead)
{
	t_inlst	*curr;

	if (!(*bhead)->content)
		return (0);
	curr = (*bhead)->next;
	(*bhead)->next->next->prev = (*bhead)->next->prev;
	(*bhead)->next->prev->next = (*bhead)->next->next;
	(*bhead)->next = (*bhead)->next->prev;
	if ((*bhead)->content == 1)
		(*bhead)->next = 0;
	push(ahead, &curr);
	(*bhead)->content--;
	(*ahead)->content++;
	write(1, "pa\n", 3);
	return (1);
}

int	pb(t_inlst **ahead, t_inlst **bhead)
{
	t_inlst	*curr;

	if (!(*ahead)->content)
		return (0);
	curr = (*ahead)->next;
	(*ahead)->next->next->prev = (*ahead)->next->prev;
	(*ahead)->next->prev->next = (*ahead)->next->next;
	(*ahead)->next = (*ahead)->next->prev;
	if ((*ahead)->content == 1)
		(*ahead)->next = 0;
	push(bhead, &curr);
	(*ahead)->content--;
	(*bhead)->content++;
	write(1, "pb\n", 3);
	return (1);
}