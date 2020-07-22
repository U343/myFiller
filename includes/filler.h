#ifndef FILLER_H
#define FILLER_H

#include <stdio.h>

#include "../libft/libft.h"
#include "get_next_line.h"
/*
**-----------------------------------Struct-------------------------------------
*/


/*
**----------------------------------Functions-----------------------------------
*/
/*
**Trace functions
*/

FILE						*open_file();
void						close_file(FILE *fp);
int							write_trace(FILE *fp, char *str);

/*
**Parse functions
*/

int							read_map(int row, FILE *fp);

#endif
