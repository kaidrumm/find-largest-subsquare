/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrumm <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/30 19:53:15 by kdrumm            #+#    #+#             */
/*   Updated: 2016/07/30 19:53:15 by kdrumm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_list		*stack_create_elem(char data)
{
	t_list *newlist;

	newlist = malloc(sizeof(t_list));
	if (!newlist)
		return (NULL);
	newlist->data = data;
	newlist->next = NULL;
	return (newlist);
}

int			stack_check_ifempty(t_list *begin_list)
{
	if (begin_list == NULL)
		return (1);
	else
		return (0);
}

void		stack_push_front(t_list **begin_list, char data)
{
	t_list *new_list;

	new_list = stack_create_elem(data);
	new_list->next = *begin_list;
	*begin_list = new_list;
}

char		stack_pop_front(t_list **begin_list)
{
	t_list	*next_node;
	char	value;

	if (*begin_list == NULL)
		return (0);
	next_node = (*begin_list)->next;
	value = (*begin_list)->data;
	free(*begin_list);
	*begin_list = next_node;
	return (value);
}
