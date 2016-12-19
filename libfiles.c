/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfiles.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrumm <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/30 19:41:33 by kdrumm            #+#    #+#             */
/*   Updated: 2016/07/30 19:41:34 by kdrumm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	print_board(char **board)
{
	int		i;

	i = 0;
	while (i < g_size)
	{
		write(1, board[i], g_width);
		ft_putchar('\n');
		i++;
	}
}

int		min(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	else if (b <= a && b <= c)
		return (b);
	else if (c <= b && c <= a)
		return (c);
	else
	{
		error("bad math\n");
		return (0);
	}
}

void	ft_realloc(char **str, int *len)
{
	char	*str2;
	int		i;

	str2 = (char *)malloc(sizeof(char) * *len * 2 + 1);
	if (!str2)
		error("Realloc error\n");
	i = 0;
	while (i <= *len)
	{
		str2[i] = str[0][i];
		i++;
	}
	str2[i] = '\0';
	*str = str2;
	*len = *len * 2;
}
