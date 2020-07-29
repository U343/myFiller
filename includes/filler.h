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
	char				**map;
}						t_map;

typedef struct			s_token
{
	int					n;
	int 				m;
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

/*
**Init functions
*/

t_map					*init_map();

/*
**Parse functions
*/

int						read_map(t_map *map, FILE *fp);

#endif
