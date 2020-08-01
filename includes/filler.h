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
	char				player;
	char				enemy;
	char				**map;
	int					**hot_map;
}						t_map;

typedef struct			s_token
{
	int					m;
	int 				n;
	char				**token;
}						t_token;

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

t_map					*init_map();
t_token					*init_token();
int						init_hot_map(t_map *map);

/*
**Functions for free memory
*/

void					free_buff(char **buff);
void					free_token(t_token *token);
void					free_map(t_map *map);

/*
**Parse functions
*/

int						read_map(t_map *map, FILE *fp);
int 					read_token(t_token *token, FILE *fp);
int						create_hot_map(t_map *map, FILE *fp);

#endif
