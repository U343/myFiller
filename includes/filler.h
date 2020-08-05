#ifndef FILLER_H
#define FILLER_H

#include <stdio.h>

#include "../libft/libft.h"
#include "get_next_line.h"
/*
**-----------------------------------Structs------------------------------------
*/

typedef struct			s_map
{
	int					n;
	int 				m;
	char				**map;
}						t_map;

typedef struct			s_filler
{
	char				player;
	char				enemy;
	t_map				*map;
	t_map				*token;
	int					**hot_map;
}						t_filler;

/*
**----------------------------------Functions-----------------------------------
*/
/*
**Trace functions
*/

FILE					*open_file();
void					close_file(FILE *fp);
int						write_trace(FILE *fp, char *str);
void					write_trace_hot_map(t_map *map, FILE *fp);

/*
**Init functions
*/

t_filler				*init_struct();
int						init_hot_map(t_filler *map);

/*
**Functions for free memory
*/

void					free_buff(char **buff);
void					free_map(t_map *map);
void					free_filler(t_filler *filler);

/*
**Parse functions
*/

int						read_map(t_map *map, int offset);

#endif
