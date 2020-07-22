/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 15:28:41 by wanton            #+#    #+#             */
/*   Updated: 2020/07/22 14:18:29 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	free_buff(char **buff)
{
	int i;

	i = 0;
	while (buff[i])
		free(buff[i++]);
	free(buff);
}

void	read_start(char **line)
{
	get_next_line(0, line);
}

void	read_map_size(char **line)
{
	get_next_line(0, line);
}

int		main(void) 
{
	FILE	*fp;
	char	*str;
	char 	*size;
	char	**buff;

	fp = open_file();
	str = ft_strdup("Player number:");
	write_trace(fp, str);
	free(str);
	read_start(&str);
	write_trace(fp, str);
	free(str);
	
	str = ft_strdup("Map size:");
	write_trace(fp, str);
	free(str);
	read_start(&str);
	buff = ft_strsplit(str, ' ');
	size = ft_strdup(buff[1]);
	free_buff(buff);
	write_trace(fp, str);
	free(str);
	write_trace(fp, size);
	free(size);
	
	read_map(ft_atoi(size), fp);
	
	close_file(fp);
	ft_putstr("1 1\n");
	ft_putstr("1 1\n");
	return (0);
}

