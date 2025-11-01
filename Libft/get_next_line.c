/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakhoury <gakhoury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:53:34 by gakhoury          #+#    #+#             */
/*   Updated: 2024/08/14 17:42:20 by gakhoury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static ssize_t	read_to_buffer(int fd, char *buffer,
						int *buf_pos, int *bytes_read)
{
	*bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (*bytes_read < 0)
		return (-1);
	if (*bytes_read == 0)
	{
		*buf_pos = 0;
		return (*bytes_read);
	}
	*buf_pos = 0;
	return (*bytes_read);
}

static int	process_char(t_list_gnl **head, char current_char)
{
	t_list_gnl	*node;

	node = ft_lst_new_char(current_char);
	if (!node)
	{
		ft_lstclear_gnl(head);
		return (-1);
	}
	ft_lstadd_back_gnl(head, node);
	if (current_char == '\n' || current_char == '\0')
		return (1);
	else
		return (0);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static int	buf_pos = 0;
	static int	bytes_read = 0;
	t_list_gnl	*head;
	int			status;

	head = NULL;
	while (1)
	{
		if (buf_pos >= bytes_read)
		{
			if (read_to_buffer(fd, buffer, &buf_pos, &bytes_read) < 0)
				return (NULL);
		}
		if (bytes_read == 0)
			return (lst_to_str(&head, ft_lstsize_gnl(head)));
		status = process_char(&head, buffer[buf_pos++]);
		if (status < 0)
			return (NULL);
		if (status > 0)
			return (lst_to_str(&head, ft_lstsize_gnl(head)));
	}
}
