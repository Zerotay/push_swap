#include <stdio.h>
// #include <libft.h>
#include <push_swap.h>
#include <time.h> // 난수 생성을 위하여

// void make_list(t_list *head, char *gv)
// {
// 	t_list	*tmp;

// 	tmp = ft_lstnew(gv);
// 	// printf("text : %s\n", (char*)tmp->content);
// 	if (!tmp)
// 		return ;
// 	ft_lstadd_back(&head, tmp);
// }

void	make_inlst(t_inlst **head, char *gv)
{
	t_inlst		*tmp;
	tmp = ft_inlstnew(ft_atoi(gv));
	if (!tmp)
		return ;
	(*head)->content++;
	ft_inlstadd_back(head, tmp);
}

void ft_fakeclear(t_list **lst)
{
	t_list	*curr;
	t_list	*currnext;

	if (!(*lst))
		return ;
	curr = *lst;
	while (curr)
	{
		currnext = curr->next;
		if (currnext == *lst)
			break ;
		free(curr);
		curr = currnext;
	}
	*lst = 0;
}

int main(int gc, char **gv)
{
	if (gc < 2)
	{
		printf("arguement lack\n");
		return (0);
	}

// 	t_list	*head;
// 	head = (t_list *)malloc(sizeof(t_list));
// 	if (!head)
// 		return (0);
// 	head->content = 0;
// 	head->next = 0;
// 	head->prev = 0;

// 	// int i = 1;
// 	// while (i < gc)
// 	// {
// 	// 	make_list(head, gv[i++]);
// 	// } 이쪾이 기본이기는 함 난수를 위해 일단 잠시...


// //여기는 난수 만들어주는 곳
// 	char random = 0;
// 	int com = 1;
// 	int con = 0;
// 	char test[8];
// 	srand(time(NULL));
// 		random = rand() % 9 + 1;
// 	test[0] = (char)(random);
// 	while (1)
// 	{
// 		random = rand() % 9 + 1;
// 		for (int j = 0; j <= com; j++)
// 		{
// 			if((char)(random) == test[j])
// 			{
// 				con = 1;
// 				break;
// 			}
// 		}
// 		if (con)
// 		{
// 			con = 0;
// 			continue;
// 		}
// 		test[com] = random;
// 		if (com++ == 7)
// 			break;
// 	}

// 	for (int i = 0; test[i]; i++)
// 	{
// 		printf("%d is %d\n", i, test[i]);
// 	}
// // 어련히 난수 변수를 받아서 연결리스트 생성
// 	int i = 0;
// 	while (i < 8)
// 	{
// 		make_list(head, ft_itoa(test[i++]));
// 	}

// 	head = head->next;
// 	head->prev = ft_lstlast(head);
// 	ft_lstlast(head)->next = head;

// 	// t_list	*curr;
// 	// curr = head;
// 	// while (curr)
// 	// {
// 	// 	printf("look %s\n", curr->content);
// 	// 	curr = curr->next;
// 	// }


// 	ft_fakeclear(&head);
// 	return(0);


	t_inlst	*ahead;
	ahead = (t_inlst *)malloc(sizeof(t_inlst));
	if (!ahead)
		return (0);
	ahead->content = 0;
	ahead->next = 0;
	ahead->prev = 0;

	int i = 1;
	// while (i < gc)
	// {
	// 	make_inlst(&ahead, gv[i++]);
	// }


//여기는 난수 만들어주는 곳
	char random = 0;
	int com = 1;
	int con = 0;
	char test[8];
	srand(time(NULL));
		random = rand() % 9 + 1;
	test[0] = (char)(random);
	while (1)
	{
		random = rand() % 9 + 1;
		for (int j = 0; j <= com; j++)
		{
			if((char)(random) == test[j])
			{
				con = 1;
				break;
			}
		}
		if (con)
		{
			con = 0;
			continue;
		}
		test[com] = random;
		if (com++ == 7)
			break;
	}

	// for (int i = 0; test[i]; i++)
	// {
	// 	printf("%d ", test[i]);
	// }
	// printf("\n");
// 어련히 난수 변수를 받아서 연결리스트 생성
	 i = 0;
	while (i < 8)
	{
		t_inlst	*tmp;

		tmp = ft_inlstnew(test[i++]);
		// printf("text : %s\n", (char*)tmp->content);
		if (!tmp)
			return (0);
		ft_inlstadd_back(&ahead, tmp);
		ahead->content++;
	}

	ahead->next->prev = ft_inlstlast(ahead);
	ft_inlstlast(ahead)->next = ahead->next;
	ahead->next = ahead->next->prev;

// 	ahead->next->content = 4;
// 	ahead->next->next->content = 6;
// 	ahead->next->next->next->content = 2;
// 	ahead->next->next->next->next->content = 3;
// 	ahead->next->next->next->next->next->content = 9;
// 	ahead->next->next->next->next->next->next->content = 7;


//여기까지가 a스택을 만든느  과정.


	t_inlst		*bhead;

	bhead = (t_inlst *)malloc(sizeof(t_inlst));
	if (!bhead)
		return (0);
	bhead->content = 0;
	bhead->next = 0;
	bhead->prev = 0;


	t_inlst	*curr;



	atob(ahead->content, &ahead, &bhead);

	// pb(&ahead, &bhead);
	// rrb(&bhead);
	// rb(&bhead);
	// rrb(&bhead);
	// rb(&bhead);
	// rb(&bhead);
	// pa(&ahead, &bhead);
	// rb(&bhead);
	// rb(&bhead);
	// rrb(&bhead);
	// pa(&ahead, &bhead);

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



	// printf("\n");
	ft_inlstclear(&ahead->next);
	ft_inlstclear(&bhead->next);

	free(ahead);
	free(bhead);
	return(0);

}
