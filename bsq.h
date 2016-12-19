/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asosnov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/01 22:22:46 by asosnov           #+#    #+#             */
/*   Updated: 2016/08/01 22:22:48 by asosnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# define INVALID(x) (x != g_empty && x != g_obstacle && x != '\n')

int						g_size;
char					g_empty;
char					g_obstacle;
char					g_full;
int						g_width;
int						g_max;
int						g_maxi;
int						g_maxj;

typedef struct			s_list
{
	struct s_list		*next;
	char				data;
}						t_list;

void					ft_putchar(char c);
void					ft_putstr(char *str);
void					error(char *msg);
char					*allocate_string(int size);
int						min(int a, int b, int c);
void					print_board(char **board);
void					skip_firstline(int *id);
void					ft_realloc(char **str, int *len);
char					*redo_first_row(char *board);
int						stack_check_ifempty(t_list *begin_list);
t_list					*stack_create_elem(char data);
void					stack_push_front(t_list **begin_list, char data);
char					stack_pop_front(t_list **begin_list);
void					print_stack(t_list *head);
void					release_rows(char **board);
void					start_search(char **str);

#endif
