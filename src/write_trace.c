/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_trace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 15:02:49 by wanton            #+#    #+#             */
/*   Updated: 2020/08/08 13:10:51 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**Function open or create file "trace"
 * 					Returned: FILE object if successful | NULL if file not
 * 					created
*/

FILE	*open_file()
{
	FILE	*fp;
	char	*name;

	name = "trace";
	fp = fopen(name, "wb	");
	if (!fp)
	{
		ft_putstr("Error: can't open file: ");
		ft_putendl(name);
		return (NULL);
	}
	return (fp);
}

/*
**This function (write_trace) write text into file.
 *
**!!! And also this function add '\n' to END to text !!!
 *
**					Returned: 0 if successful | 0 if error with malloc
*/

int		write_trace(FILE *fp, char *str)
{
	char	*res;
	int		len;

	len = (int)ft_strlen(str) + 1;
	if (!(res = ft_strnew(len)))
		return (-1);
	res = ft_strcat(res, str);
	res = ft_strcat(res, "\n");
	fwrite(res, sizeof(char), len, fp);
	free(res);
	return (0);
}

/*
**Just close file File
 *
** I don't know why i created this function
*/

void	close_file(FILE *fp)
{
	fclose(fp);
}

/*
**Just write traces for hot_map
*/

void		write_trace_hot_map(t_filler *filler, FILE *fp)
{
	int		i;
	int 	j;
	int		len;
	char	*str;

	i = -1;
	while (++i < filler->map->y)
	{
		j = -1;
		while (++j < filler->map->x)
		{
			str = ft_itoa(filler->hot_map[i][j]);
			len = ft_strlen(str);
			fwrite(str, sizeof(char), len, fp);
			free(str);
		}
		fwrite("\n", sizeof(char), 1, fp);
	}
}
