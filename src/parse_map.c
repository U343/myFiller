/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 14:05:46 by wanton            #+#    #+#             */
/*   Updated: 2020/07/22 14:43:23 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
**This function read map.
**					Returned: 0 if successful | -1 if error with malloc
*/

int		read_map(int row, FILE *fp) // fp для треймсов потом надо УДАЛИТЬ
{
	int 	i;
	char	*str;
	char	**map;
	
	str = ft_strdup("Map:"); // trace. DELETE later
	write_trace(fp, str);
	free(str);
	
	i = 0;
	if (!(map = (char **)malloc(sizeof(char *) * row + 1)))
		return (-1);
	get_next_line(0, &str); // Считываю строку с цифрами
	free(str);
	while (i < row)
	{
		if (get_next_line(0, &str) == -1)
			return (-1);
		map[i++] = ft_strdup(str + 4); // Пропускаю первые три цифры разметки и пробел
		free(str);
	}
	// trace. DELETE later
	i = 0;
	while (i < row)
		write_trace(fp, map[i++]);
	return (0);
}