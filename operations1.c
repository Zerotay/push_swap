#include <push_swap.h>

void	swap(t_inlst **head)
{
	t_inlst	*before;

}

void	sa(t_inlst **head)
{
	t_inlst	*before;

	if ((*head)->content == 1 || !(*head)->content)
		return ;
	if ((*head)->content == 2)
		(*head)->next = (*head)->next->next;
	else
	{
		before = (*head)->next->prev->prev;

		before->next = (*head)->next;
		(*head)->next->next->prev = (*head)->next->prev;

		(*head)->next->prev->prev = (*head)->next;
		(*head)->next->prev->next = (*head)->next->next;
		(*head)->next->next = (*head)->next->prev;
		(*head)->next->prev = before;

		(*head)->next = (*head)->next->next;
	}
	printf("sa\n");
}

void	sb(t_inlst **head)
{
	t_inlst	*before;

	if ((*head)->content == 1 || !(*head)->content)
		return ;
	if ((*head)->content == 2)
		(*head)->next = (*head)->next->next;
	else
	{
		before = (*head)->next->prev->prev;

		before->next = (*head)->next;
		(*head)->next->next->prev = (*head)->next->prev;

		(*head)->next->prev->prev = (*head)->next;
		(*head)->next->prev->next = (*head)->next->next;
		(*head)->next->next = (*head)->next->prev;
		(*head)->next->prev = before;

		(*head)->next = (*head)->next->next;
	}
	printf("sb\n");
}

void	ss(t_inlst **ahead, t_inlst **bhead)
{
	t_inlst	*before;

	if ((*ahead)->content == 1 || !(*ahead)->content)
		return ;
	if ((*bhead)->content == 1 || !(*bhead)->content)
		return ;
	if ((*ahead)->content == 2)
		(*ahead)->next = (*ahead)->next->next;
	else
	{
		before = (*ahead)->next->prev->prev;
		before->next = (*ahead)->next;
		(*ahead)->next->next->prev = (*ahead)->next->prev;
		(*ahead)->next->prev->prev = (*ahead)->next;
		(*ahead)->next->prev->next = (*ahead)->next->next;
		(*ahead)->next->next = (*ahead)->next->prev;
		(*ahead)->next->prev = before;
		(*ahead)->next = (*ahead)->next->next;
	}
	if ((*bhead)->content == 2)
		(*bhead)->next = (*bhead)->next->next;
	else
	{
		before = (*bhead)->next->prev->prev;
		before->next = (*bhead)->next;
		(*bhead)->next->next->prev = (*bhead)->next->prev;
		(*bhead)->next->prev->prev = (*bhead)->next;
		(*bhead)->next->prev->next = (*bhead)->next->next;
		(*bhead)->next->next = (*bhead)->next->prev;
		(*bhead)->next->prev = before;
		(*bhead)->next = (*bhead)->next->next;
	}
	printf("ss\n");
}

void	pa(t_inlst **ahead, t_inlst **bhead)
{
	t_inlst	*curr;

	if (!(*bhead)->content)
		return ;

	curr = (*bhead)->next;



	//일단 b안에 뭐가 있따고 쳐보자.

	(*bhead)->next->next->prev = (*bhead)->next->prev;
	(*bhead)->next->prev->next = (*bhead)->next->next;
	(*bhead)->next = (*bhead)->next->prev;

	if ((*bhead)->content == 1)
		(*bhead)->next = 0;

	if ((*ahead)->content == 0)
	{
		(*ahead)->next = curr;
		curr->next = curr;
		curr->prev = curr;
	}
	else
	{
		curr->next = (*ahead)->next->next;
		curr->prev = (*ahead)->next;
		(*ahead)->next->next->prev = curr;
		(*ahead)->next->next = curr;
		(*ahead)->next = curr;
	}

		(*bhead)->content--;
		(*ahead)->content++;

	printf("pa\n");
}

void	pb(t_inlst **ahead, t_inlst **bhead)
{
	t_inlst	*curr;

	if (!(*ahead)->content)
		return ;

	curr = (*ahead)->next;




	//일단 b안에 뭐가 있따고 쳐보자.

	(*ahead)->next->next->prev = (*ahead)->next->prev;
	(*ahead)->next->prev->next = (*ahead)->next->next;
	(*ahead)->next = (*ahead)->next->prev;

	if ((*ahead)->content == 1)
		(*ahead)->next = 0;

	if ((*bhead)->content == 0)
	{
		(*bhead)->next = curr;
		curr->next = curr;
		curr->prev = curr;
	}
	else
	{
		curr->next = (*bhead)->next->next;
		curr->prev = (*bhead)->next;
		(*bhead)->next->next->prev = curr;
		(*bhead)->next->next = curr;
		(*bhead)->next = curr;
	}



	(*ahead)->content--;
	(*bhead)->content++;
	// printf("repeat... prev of anext : %d\n", (*ahead)->next->next->prev->content);

	printf("pb\n");

}

void	ra(t_inlst **head)
{
	if ((*head)->content < 2)
		return ;
	(*head)->next = (*head)->next->prev;
	printf("ra\n");
}

void	rb(t_inlst **head)
{
	if ((*head)->content < 2)
	return ;
	(*head)->next = (*head)->next->prev;
	printf("rb\n");
}

void	rr(t_inlst **ahead, t_inlst **bhead)
{
	if ((*ahead)->content < 2 || (*bhead)->content < 2)
		return ;
	(*ahead)->next = (*ahead)->next->prev;
	(*bhead)->next = (*bhead)->next->prev;
	printf("rr\n");
}

void	rra(t_inlst **head)
{
	if ((*head)->content < 2)
		return ;
	(*head)->next = (*head)->next->next;
	printf("rra\n");
}

void	rrb(t_inlst **head)
{
	if ((*head)->content < 2)
		return ;
	(*head)->next = (*head)->next->next;
	printf("rrb\n");
}

void	rrr(t_inlst **ahead, t_inlst **bhead)
{
	if ((*ahead)->content < 2 || (*bhead)->content < 2)
		return ;
	(*ahead)->next = (*ahead)->next->next;
	(*bhead)->next = (*bhead)->next->next;
	printf("rrr\n");
}