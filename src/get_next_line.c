/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 14:29:25 by wanton            #+#    #+#             */
/*   Updated: 2020/08/16 14:29:25 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** Находит \н в главном массиве
** если нет возвращает 0
** все что до отправляем в лайн, все что после записываем в массив
*/

static int		ft_get_line(char **array, char **line)
{
	char		*temp;
	char		*str;

	str = *array;
	if (!(temp = ft_strchr(str, '\n')))
		return (0);
	*temp = '\0';
	*line = ft_strdup(*array);
	*array = ft_strdup(temp + 1);
	free(str);
	return (1);
}

/*
** Читаем в буф из файла
** если в основном массиве уже что-то есть делаем конкатенацию
** если нет просто добавляем буф в масив
** если найдем в массиве \н то завершвем считывание
*/

static int		ft_read(int fd, char *buf, char **array, char **line)
{
	int			r;
	char		*temp;

	while ((r = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[r] = '\0';
		if (*array)
		{
			temp = *array;
			if (!(*array = ft_strjoin(*array, buf)))
				return (-1);
			free(temp);
		}
		else
		{
			*array = ft_strdup(buf);
		}
		if (ft_get_line(array, line))
			break ;
	}
	if (r > 0)
		return (1);
	else
		return (r);
}

/*
** основная функция, делаем проверки,
** если в массиве уже что то отправляем в гетлайн
** освобождаем буф и все ненужное
*/

int				get_next_line(const int fd, char **line)
{
	static char *array[MAX_FD];
	char		*buf;
	int			r;

	if (fd < 0 || fd >= MAX_FD || !line || (BUFF_SIZE < 0)
			|| (read(fd, array[fd], 0) < 0) || !(buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	if (array[fd])
		if (ft_get_line(&array[fd], line))
		{
			free(buf);
			return (1);
		}
	ft_bzero(buf, BUFF_SIZE + 1);
	r = ft_read(fd, buf, &array[fd], line);
	free(buf);
	if (r || array[fd] == NULL || array[fd][0] == '\0')
	{
		if (!r && *line)
			*line = NULL;
		return (r);
	}
	*line = array[fd];
	array[fd] = NULL;
	return (1);
}
