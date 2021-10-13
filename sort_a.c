#include <push_swap.h>

int	conquer_a(int n, t_inlst **ahead, t_inlst **bhead)
{
	if (n == 3)
		return (aif3(ahead, bhead));
	if ((n == 2) && ((*ahead)->next->content > (*ahead)->next->prev->content))
	{
		sa(ahead);
		return (0);
	}
	return (0);
}

int	zero_init_a(int *a, int *b, int *c)
{
	*a = 0;
	*b = 0;
	*c = 0;
	return (0);
}

int	init_pivot_a(int *p1, int *p2, t_inlst **ahead, t_inlst **bhead)
{
	*p1 = (*ahead)->next->prev->content;
	*p2 = (*ahead)->next->content;
	if ((*ahead)->next->content > (*ahead)->next->prev->content)
	{
		*p1 = (*ahead)->next->content;
		*p2 = (*ahead)->next->prev->content;
	}
	return (0);
}

int	rewind_stack_a(int nra, int nrb, t_inlst **ahead, t_inlst **bhead)
{
	while (nra && nrb)
	{
		rrr(ahead, bhead);
		nra--;
		nrb--;
	}
	while (nra--)
		rra(ahead);
	while (nrb--)
		rrb(bhead);
	return (0);
}

int	atob(int n, t_inlst **ahead, t_inlst **bhead)
{
	int	p1;
	int	p2;
	int	nra;
	int	npb;
	int	nrb;

	if (n < 4)
		return (conquer_a(n, ahead, bhead));
	zero_init_a(&nra, &npb, &nrb);
	init_pivot_a(&p1, &p2, ahead, bhead);
	while (n--)
	{
		if ((*ahead)->next->content >= p1)
			nra += ra(ahead);
		else
		{
			npb += pb(ahead, bhead);
			if ((*bhead)->next->content > p2)
				nrb += rb(bhead);
		}
	}
	rewind_stack_a(nra, nrb, ahead, bhead);
	atob(nra, ahead, bhead);
	btoa(nrb, ahead, bhead);
	btoa(npb - nrb, ahead, bhead);
}
