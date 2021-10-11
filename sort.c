#include <push_swap.h>

void	aif3(t_inlst **ahead, t_inlst **bhead)
{
	int	a;
	int	b;
	int	c;

	a = (*ahead)->next->content;
	b = (*ahead)->next->prev->content;
	c = (*ahead)->next->prev->prev->content;

	if (a > b && a > c)
	{
		sa(ahead);
		ra(ahead);
		sa(ahead);
		rra(ahead);
		if (b > c)
			sa(ahead);
		return ;
	}
	if (c > b && c > a)
	{
		if (a > b)
			sa(ahead);
		return ;
	}
	ra(ahead);
	sa(ahead);
	rra(ahead);
	if (c < a)
		sa(ahead);
	return ;
}

void	atob(int n, t_inlst **ahead, t_inlst **bhead)
{
	int p1;
	int	p2;
	int nra;
	int npb;
	int nrb;
	int i;
	t_inlst	*curr;

	nra = 0;
	npb = 0;
	nrb = 0;

	if (n == 3)
	{
		aif3(ahead, bhead);
		return ;
	}
	if ((n == 2) && ((*ahead)->next->content > (*ahead)->next->prev->content))
	{
		sa(ahead);
		return ;
	}
	if (n < 3)
		return ;

	i = n / 2;
	curr = (*ahead)->next;

	if (curr->content > curr->prev->content)
	{
		p1 = curr->content;
		p2 = curr->prev->content;
	}
	else
	{
		p1 = curr->prev->content;
		p2 = curr->content;
	}

	while (n--)
	{
		if ((*ahead)->next->content >= p1)
		{
			ra(ahead);
			nra++;
		}
		else
		{
			pb(ahead, bhead);
			npb++;
			if ((*bhead)->next->content > p2)
			{
				rb(bhead);
				nrb++;
			}
		}
	}
	i = nra;
	while(i--)
	{
		rra(ahead);
	}
	i = nrb;
	while (i--)
	{
		rrb(bhead);
	}
	atob(nra, ahead, bhead);
	btoa(nrb, ahead, bhead);
	btoa(npb - nrb, ahead, bhead);

}

void	bif3(t_inlst **ahead, t_inlst **bhead)
{
	int	a;
	int	b;
	int	c;

	a = (*bhead)->next->content;
	b = (*bhead)->next->prev->content;
	c = (*bhead)->next->prev->prev->content;

	if (a > b && a > c)
	{
		pa(ahead, bhead);
		if (b < c)
			sb(bhead);
		pa(ahead, bhead);
		pa(ahead, bhead);
		return ;
	}
	if (b > c && b > a)
	{
		rb(bhead);
		pa(ahead, bhead);
		rrb(bhead);
		if (c > a)
			sb(bhead);
		pa(ahead, bhead);
		pa(ahead, bhead);
		return ;
	}
	rb(bhead);
	sb(bhead);
	pa(ahead, bhead);
	rrb(bhead);
	if (b > a)
		sb(bhead);
	pa(ahead, bhead);
	pa(ahead, bhead);
	return ;
}

void	btoa(int n, t_inlst **ahead, t_inlst **bhead)
{
	int p1;
	int	p2;
	int nra;
	int npa;
	int nrb;
	int i;
	t_inlst *curr;

	nra = 0;
	npa = 0;
	nrb = 0;
	if (n == 3)
	{
		bif3(ahead, bhead);
		return ;
	}
	if (n == 2)
	{
		if ((*bhead)->next->content < (*bhead)->next->prev->content)
			sb(bhead);
		pa(ahead, bhead);
		pa(ahead, bhead);
		return ;
	}
	if (n == 1)
	{
		pa(ahead,bhead);
		return;
	}
	if (!n)
		return ;

	i = n/2;
	curr = (*bhead)->next;

	if (curr->content > curr->next->content)
	{
		p1 = curr->prev->content;
		p2 = curr->content;
	}
	else
	{
		p1 = curr->content;
		p2 = curr->prev->content;
	}

	while (n--)
	{
		if ((*bhead)->next->content < p1)
		{
			rb(bhead);
			nrb++;
		}
		else
		{
			pa(ahead, bhead);
			npa++;
			if ((*ahead)->next->content < p2)
			{
				ra(ahead);
				nra++;
			}
		}

	}
	atob(npa - nra, ahead, bhead);
	i = nra;
	while(i--)
	{
		rra(ahead);
	}
	i = nrb;
	while (i--)
	{
		rrb(bhead);
	}
	atob(nra, ahead, bhead);
	btoa(nrb, ahead, bhead);
}