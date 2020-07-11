#include <unistd.h>
#include "libft.h"

int		main(void) 
{
	write(1, "hello\n", 6);
	ft_putstr("ok\n");
	return (0);	
}
