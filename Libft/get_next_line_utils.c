/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakhoury <gakhoury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:53:52 by gakhoury          #+#    #+#             */
/*   Updated: 2024/08/20 09:03:22 by gakhoury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list_gnl	*ft_lst_new_char(char content)
{
	t_list_gnl	*node;

	node = (t_list_gnl *)malloc(sizeof(t_list_gnl));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_back_gnl(t_list_gnl **lst, t_list_gnl *new_node)
{
	t_list_gnl	*last;

	if (!lst || !new_node)
		return ;
	if (!*lst)
		*lst = new_node;
	else
	{
		last = *lst;
		while (last->next)
			last = last->next;
		last->next = new_node;
	}
}

int	ft_lstsize_gnl(t_list_gnl *lst)
{
	int	size;

	size = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

void	ft_lstclear_gnl(t_list_gnl **lst)
{
	t_list_gnl	*current;
	t_list_gnl	*next;

	if (!lst || !*lst)
		return ;
	current = *lst;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*lst = (NULL);
}

char	*lst_to_str(t_list_gnl **lst, size_t size)
{
	t_list_gnl	*current;
	char		*str;
	size_t		i;

	i = 0;
	if (ft_lstsize_gnl(*lst) <= 0 || !*lst || !size)
		return (NULL);
	current = *lst;
	str = (char *)malloc(size + 1);
	if (!str)
		return (NULL);
	while (i < size)
	{
		str[i] = current->content;
		current = current->next;
		i++;
	}
	str[size] = '\0';
	ft_lstclear_gnl(lst);
	return (str);
}
