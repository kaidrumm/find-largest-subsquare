/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asosnov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 14:32:29 by asosnov           #+#    #+#             */
/*   Updated: 2016/08/02 14:32:31 by asosnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void		print_result(char **symboard)
{
	int		i;
	int		j;

	i = g_maxi - g_max + 1;
	while (i <= g_maxi)
	{
		j = g_maxj - g_max + 1;
		while (j <= g_maxj)
		{
			symboard[i][j] = g_full;
			j++;
		}
		i++;
	}
	print_board(symboard);
}

void		calc2(int **bd, int i, int j)
{
	if (bd[i][j] != 0)
	{
		if (i == 0 || j == 0)
			bd[i][j] = 1;
		else
			bd[i][j] = 1 + min(bd[i - 1][j], bd[i][j - 1], bd[i - 1][j - 1]);
		if (bd[i][j] > g_max)
		{
			g_max = bd[i][j];
			g_maxi = i;
			g_maxj = j;
		}
	}
}

void		calculate(int **board, char **symboard)
{
	int	i;
	int	j;

	g_max = 0;
	g_maxi = 0;
	g_maxj = 0;
	i = 0;
	while (i < g_size)
	{
		j = 0;
		while (j < g_width)
		{
			calc2(board, i, j);
			j++;
		}
		i++;
	}
	print_result(symboard);
	free(board);
}

void		start_search(char **symboard)
{
	int		**numboard;
	int		i;
	int		j;

	numboard = (int **)malloc(sizeof(int *) * g_size);
	if (!numboard)
		error("Out of memory\n");
	i = 0;
	while (i < g_size)
	{
		j = 0;
		numboard[i] = (int *)malloc(sizeof(int) * g_width);
		if (!numboard[i])
			error("Out of memory\n");
		while (j < g_width)
		{
			if (symboard[i][j] == g_obstacle)
				numboard[i][j] = 0;
			else if (symboard[i][j] == g_empty)
				numboard[i][j] = 1;
			j++;
		}
		i++;
	}
	calculate(numboard, symboard);
	release_rows(symboard);
}
