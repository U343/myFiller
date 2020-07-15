#include "../includes/filler.h"

char	read_start()
{
	char *line;
	
	get_next_line(0, &line);
	free(line);
	get_next_line(0, &line);
	if (ft_strequ(line, "$$$ exec p2 : [players/filler.filler")) {
		free(line);
		return ('X');
	}
	else
	{
		free(line);
		return ('O');
	}
}

char	*read_map_size()
{
	char *size;
	
	get_next_line(0, &size);
	return (size);
}

int		main(void) 
{
	//read_start();
	//read_map_size();
	ft_putstr("<got (X): [1, 1]");
	ft_putstr("<got (X): [1, 1]");
	return (0);
}
