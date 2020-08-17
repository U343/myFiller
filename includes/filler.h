/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 12:19:49 by wanton            #+#    #+#             */
/*   Updated: 2020/08/17 12:28:29 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdio.h>

# include "../libft/libft.h"
# include "get_next_line.h"
# include "constants.h"

/*
**-----------------------------------Structs------------------------------------
*/

typedef struct		s_map
{
	int				x;
	int				y;
	int				start_x;
	int				start_y;
	int				end_x;
	int				end_y;
	char			**map;
}					t_map;

typedef struct		s_filler
{
	char			player;
	char			enemy;
	t_map			*map;
	t_map			*token;
	int				**hot_map;
}					t_filler;

/*
**----------------------------------Functions-----------------------------------
**Init functions
*/

t_filler			*init_struct();
int					init_hot_map(t_filler *filler);

/*
**Functions for free memory
*/

void				free_buff(t_map *map, int identifier);
void				free_int_buff(int **buff, t_map *map);
void				free_filler(t_filler *filler);

/*
**Parse functions
*/

int					read_map(t_map *map, int offset, char *line);
int					read_start(t_filler *map);

/*
**Main functions
*/

int					cut_dot(t_map *token);
int					find_place(t_filler *filler, int coords[3]);
void				create_hot_map(t_filler *filler);

#endif
