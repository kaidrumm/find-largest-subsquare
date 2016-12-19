/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asosnov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/01 22:16:43 by asosnov           #+#    #+#             */
/*   Updated: 2016/08/01 22:16:44 by asosnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		set_global_var(t_list **args)
{
	int mag;

	mag = 1;
	g_full = stack_pop_front(args);
	g_obstacle = stack_pop_front(args);
	g_empty = stack_pop_front(args);
	if (stack_check_ifempty(*args))
		return (0);
	while (!stack_check_ifempty(*args))
	{
		g_size = g_size + mag * (stack_pop_front(args) - 48);
		mag *= 10;
	}
	return (1);
}

int		fill_board(char **board, char *first_row, int *id, int *bytes)
{
	int		i;
	int		j;
	char	buff[1];

	i = 1;
	buff[0] = 0;
	board[0] = redo_first_row(first_row);
	while (i < g_size)
	{
		j = 0;
		board[i] = allocate_string(g_width + 1);
		while (j < g_width)
		{
			*bytes = read(*id, &buff, 1);
			if (*bytes != 1 || buff[0] == '\n' || INVALID(buff[0]))
				return (0);
			board[i][j] = buff[0];
			j++;
		}
		*bytes = read(*id, &buff, 1);
		board[i][g_width] = '\0';
		i++;
	}
	start_search(board);
	return (1);
}

int		init_board(int *id, int *bytes)
{
	char	**board;
	char	buff[1];
	int		temp_width;
	char	*first_row;

	buff[0] = 0;
	temp_width = 2;
	board = (char **)malloc(sizeof(char *) * g_size);
	if (!board)
		return (0);
	first_row = allocate_string(temp_width + 1);
	while (*bytes == 1 && buff[0] != '\n')
	{
		*bytes = read(*id, &buff, 1);
		if (*bytes != 1 || INVALID(buff[0]))
			return (0);
		if (buff[0] != '\n')
		{
			first_row[g_width] = buff[0];
			if (g_width++ >= temp_width)
				ft_realloc(&first_row, &temp_width);
		}
	}
	return (fill_board(board, first_row, id, bytes));
}

int		read_symbols(char *filename)
{
	int		id;
	int		bytes;
	t_list	*symbols;
	char	buff[1];

	symbols = NULL;
	if (filename[0] == '\0')
		id = 0;
	else
	{
		id = open(filename, O_RDONLY);
		if (id == -1)
			error("error opening file\n");
	}
	buff[0] = 0;
	bytes = 1;
	while (bytes == 1 && buff[0] != '\n')
	{
		bytes = read(id, &buff, 1);
		if (buff[0] != '\n')
			stack_push_front(&symbols, buff[0]);
	}
	if (!set_global_var(&symbols) || !init_board(&id, &bytes))
		return (0);
	return (1);
}

int		main(int argc, char *argv[])
{
	int		i;

	i = 1;
	if (argc < 2)
	{
		read_symbols("\0");
		return (1);
	}
	while (i < argc)
	{
		g_size = 0;
		g_empty = 0;
		g_obstacle = 0;
		g_full = 0;
		g_width = 0;
		g_max = 0;
		g_maxi = 0;
		g_maxj = 0;
		if (!read_symbols(argv[i]))
			ft_putstr("map error\n");
		i++;
	}
	return (0);
}
