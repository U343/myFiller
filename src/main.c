/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 15:28:41 by wanton            #+#    #+#             */
/*   Updated: 2020/07/18 15:52:20 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/filler.h"

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

	fp = open_file();
	str = ft_strdup("Player number:");
	write_trace(fp, str);
	read_start(&str);
	write_trace(fp, str);
	
	str = ft_strdup("Map size:");
	write_trace(fp, str);
	read_start(&str);
	write_trace(fp, str);
	
	close_file(fp);
	ft_putstr("1 1\n");
	ft_putstr("1 1\n");
	return (0);
}

