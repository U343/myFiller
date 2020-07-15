/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 12:20:25 by wanton            #+#    #+#             */
/*   Updated: 2019/10/17 13:55:51 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	t_list		*ft_lstnew_gnl(void const *con, size_t con_size)
{
	t_list	*res;

	if (!(res = (t_list *)malloc(sizeof(t_list))))
		return ((t_list *)NULL);
	if (!con)
	{
		res->content = NULL;
		res->content_size = 0;
		res->next = NULL;
		return (res);
	}
	res->content = (void *)con;
	res->content_size = con_size;
	res->next = NULL;
	return (res);
}

static	t_list		*determine_fd(int fd, t_list **st)
{
	t_list	*p;

	p = *st;
	while (p)
	{
		if ((int)p->content_size == fd)
			return (p);
		p = p->next;
	}
	if ((p = ft_lstnew_gnl("", fd)))
	{
		ft_lstadd(st, p);
		return (p);
	}
	return (NULL);
}

static	int			read_n(int fd, char **tmp)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*tr;

	tr = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		tr = *tmp;
		buf[ret] = '\0';
		if (!(*tmp = ft_strjoin(*tmp, buf)))
		{
			return (-1);
		}
		if (*tr)
			free(tr);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (ret);
}

int					get_next_line(const int fd, char **line)
{
	static	t_list	*storage_fd;
	t_list			*p;
	char			*tmp;
	int				res;

	if (fd < 0 || !line || BUFF_SIZE <= 0 || read(fd, NULL, 0) < 0 ||
			!(p = determine_fd(fd, &storage_fd)))
		return (-1);
	tmp = (char *)p->content;
	if ((res = read_n(fd, &tmp) <= 0) && (!tmp || !*tmp))
	{
		return ((res < 0) ? -1 : 0);
	}
	res = ft_strlen(tmp);
	if ((p->content = ft_strchr(tmp, '\n')))
	{
		res = (int)((char *)p->content - tmp);
		*(char *)p->content == '\n' ? p->content++ : p->content;
		p->content = ft_strdup(p->content);
	}
	if (!(*line = ft_strsub(tmp, 0, res)))
		return (-1);
	free(tmp);
	return (1);
}
