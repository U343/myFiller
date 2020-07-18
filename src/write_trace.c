/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_trace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 15:02:49 by wanton            #+#    #+#             */
/*   Updated: 2020/07/18 15:51:06 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

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
**Function to free memory allocated for str
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
		return (0);
	res = ft_strcat(res, str);
	res = ft_strcat(res, "\n");
	fwrite(res, sizeof(char), len, fp);
	free(str);
	free(res);
	return (1);
}

void	close_file(FILE *fp)
{
	fclose(fp);
}
