#include <stdio.h>
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

void	onlyif3(t_inlst **ahead)
{
	int	a;
	int	b;
	int	c;

	a = (*ahead)->next->content;
	b = (*ahead)->next->prev->content;
	c = (*ahead)->next->prev->prev->content;

	if (a > b && a > c)
	{
		ra(ahead);
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
	rra(ahead);
	if (a < c)
		sa(ahead);
	return ;
}

void	onlyif5(t_inlst **ahead, t_inlst **bhead)
{
	int	tmp;
	int	i;
	int small;
	t_inlst	*curr;

	curr = (*ahead)->next;
	tmp = (*ahead)->next->content;
	i = (*ahead)->content;
	while (i--)
	{
		if (tmp > curr->content)
			tmp = curr->content;
		curr = curr->next;
	}
	small = tmp;
	if (small == (*ahead)->next->content)
		tmp = (*ahead)->next->next->content;
	else
		tmp = (*ahead)->next->content;
	i = (*ahead)->content;
	while (i--)
	{
		if (tmp > curr->content && curr->content != small)
			tmp = curr->content;
		curr = curr->next;
	}
	while (i < 1)
	{
		if ((*ahead)->next->content <= tmp)
		{
			pb(ahead, bhead);
			i++;
		}
		ra(ahead);
	}
	onlyif3(ahead);
	if ((*bhead)->next->content < (*bhead)->next->prev->content)
		sb(bhead);
	pa(ahead, bhead);
	pa(ahead, bhead);
}


int main(int gc, char **gv)
{
	t_inlst	*ahead;

	if (gc == 1)
		return (0);
	if (gc < 2)
		print_error(&ahead);

	ahead = (t_inlst *)malloc(sizeof(t_inlst));
	if (!ahead)
		return (0);
	ahead->content = 0;
	ahead->next = 0;
	ahead->prev = 0;


	int i = gc;
	while (--i)
	{
		make_inlst(&ahead, gv[i]);
	}


	ahead->next->prev = ft_inlstlast(ahead);
	ft_inlstlast(ahead)->next = ahead->next;
	ahead->next = ahead->next->prev;

	t_inlst		*bhead;

	bhead = (t_inlst *)malloc(sizeof(t_inlst));
	if (!bhead)
		return (0);
	bhead->content = 0;
	bhead->next = 0;
	bhead->prev = 0;




	if (ahead->content == 3)
		onlyif3(&ahead);
	if (ahead->content == 5)
		onlyif5(&ahead, &bhead);
	else
		atob(ahead->content, &ahead, &bhead);

//확인용
	// printf("\n");
	// printf("\n");

	// printf("asize %d\n", ahead->content);

	// if (ahead->next)
	// {
	// 	curr = ahead->next->next;
	// 	printf("A :\n");
	// printf("head %d / headnext %d / headprev %d\n", ahead->next->content, ahead->next->next->content, ahead->next->prev->content);
	// printf("nexthead %d / nextnext %d / nextprev %d\n", ahead->next->next->content, ahead->next->next->next->content, ahead->next->next->prev->content);
	// printf("prevhead %d / prevnext %d / prevprev %d\n", ahead->next->prev->content, ahead->next->prev->next->content, ahead->next->prev->prev->content);
	// 	for (int i = 0; i < ahead->content; i++)
	// 	{
	// 		printf("%d ", curr->content);
	// 		curr = curr->next;
	// 	}
	// }

	// if (bhead->next)
	// {
	// 		curr = bhead->next->next;
	// 	printf("\nB :\n");
	// 	printf("head %d / headnext %d / headprev %d\n", bhead->next->content, bhead->next->next->content, bhead->next->prev->content);
	// 	printf("nexthead %d / nextnext %d / nextprev %d\n", bhead->next->next->content, bhead->next->next->next->content, bhead->next->next->prev->content);
	// 	printf("prevhead %d / prevnext %d / prevprev %d\n", bhead->next->prev->content, bhead->next->prev->next->content, bhead->next->prev->prev->content);

	// 	for (int i = 0; i < bhead->content; i++)
	// 	{
	// 		printf("%d ", curr->content);
	// 		curr = curr->next;
	// 	}
	// }
	// printf("\n");



	ft_inlstclear(&ahead->next);
	ft_inlstclear(&bhead->next);

	free(ahead);
	free(bhead);
	return(0);

}
