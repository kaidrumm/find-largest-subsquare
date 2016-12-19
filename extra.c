/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrumm <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 22:43:43 by kdrumm            #+#    #+#             */
/*   Updated: 2016/08/03 22:43:45 by kdrumm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void		release_rows(char **board)
{
	int		i;

	i = 0;
	while (i < g_size)
	{
		free(board[i]);
		i++;
	}
}

char		*redo_first_row(char *row)
{
	char	*tmp;
	int		i;

	tmp = (char *)malloc(sizeof(char) * g_width);
	i = 0;
	while (i < g_width)
	{
		tmp[i] = row[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char		*allocate_string(int size)
{
	char	*string;

	string = (char *)malloc(sizeof(char) * size);
	if (!string)
		error("Out of Memory\n");
	return (string);
}

void		error(char *msg)
{
	ft_putstr(msg);
	exit(0);
}