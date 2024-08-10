/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamachad <vamachad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 21:52:33 by vamachad          #+#    #+#             */
/*   Updated: 2024/06/25 21:52:39 by vamachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	char			line[BUFFER_SIZE + 1];
	struct s_list	*next;
}					t_list;

char				*get_next_line(int fd);
void				sort_buf(char *buf);
char				*get_line(t_list *lst, char *line);
void				node_buf(t_list **lst, char *buf, int size);
int					line_length(t_list *lst);
t_list				*create_node(char *buf, int size);
void				append_node(t_list **lst, t_list *node);
char				*free_list(t_list **lst);
int					ft_strchr(char *str, char c);
int					ft_strlen(char *str);
char				*buff_exists(char *buf, t_list **lst);
char				*buff_incomplete(int fd, char *buf, t_list **lst);

#endif
