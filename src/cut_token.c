/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 15:25:34 by wanton            #+#    #+#             */
/*   Updated: 2020/08/16 15:29:32 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	check_size(t_map *token)
{
	int		i;
	int		j;

	i = -1;
	while (++i < token->y)
	{
		j = -1;
		while (++j < token->x)
		{
			if (token->map[i][j] == TOKEN_FILLED_SYMBOL)
			{
				token->start_x = (j < token->start_x ? j : token->start_x);
				token->start_y = (i < token->start_y ? i : token->start_y);
				token->end_x = (j > token->end_x ? j : token->end_x);
				token->end_y = (i > token->end_y ? i : token->end_y);
			}
		}
	}
}

static int	filler_new_token(t_map *token, char ***res)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = token->start_y - 1;
	y = 0;
	while (++i <= token->end_y)
	{
		j = token->start_x - 1;
		x = 0;
		if (!((*res)[y] = (char *)malloc(sizeof(char) * (token->end_x - j))))
			return (-1);
		while (++j <= token->end_x)
			(*res)[y][x++] = token->map[i][j];
		y++;
	}
	return (0);
}

int			cut_dot(t_map *token)
{
	int		size;
	char	**res;

	token->start_x = token->x;
	token->start_y = token->y;
	token->end_x = 0;
	token->end_y = 0;
	check_size(token);
	size = token->end_y - token->start_y + 1;
	if (!(res = (char **)malloc(sizeof(char *) * size)))
		return (-1);
	if (filler_new_token(token, &res) == -1)
		return (-1);
	free_buff(token, MAP_IDENTIFIER);
	token->map = res;
	res = NULL;
	return (0);
}
