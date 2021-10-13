#include <push_swap.h>

void	swap(t_inlst **head)
{
	t_inlst	*before;

	before = (*head)->next->prev->prev;
	before->next = (*head)->next;
	(*head)->next->next->prev = (*head)->next->prev;
	(*head)->next->prev->prev = (*head)->next;
	(*head)->next->prev->next = (*head)->next->next;
	(*head)->next->next = (*head)->next->prev;
	(*head)->next->prev = before;
	(*head)->next = (*head)->next->next;
}

int	sa(t_inlst **head)
{
	t_inlst	*before;

	if ((*head)->content == 1 || !(*head)->content)
		return (0);
	if ((*head)->content == 2)
		(*head)->next = (*head)->next->next;
	else
		swap(head);
	write(1, "sa\n", 3);
	return (1);
}

int	sb(t_inlst **head)
{
	t_inlst	*before;

	if ((*head)->content == 1 || !(*head)->content)
		return (0);
	if ((*head)->content == 2)
		(*head)->next = (*head)->next->next;
	else
		swap(head);
	write(1, "sb\n", 3);
	return (1);
}

int	ss(t_inlst **ahead, t_inlst **bhead)
{
	t_inlst	*before;

	if ((*ahead)->content == 1 || !(*ahead)->content)
		return (0);
	if ((*bhead)->content == 1 || !(*bhead)->content)
		return (0);
	if ((*ahead)->content == 2)
		(*ahead)->next = (*ahead)->next->next;
	else
		swap(ahead);
	if ((*bhead)->content == 2)
		(*bhead)->next = (*bhead)->next->next;
	else
		swap(bhead);
	write(1, "ss\n", 3);
	return (1);
}
