#ifndef CUBE_H
# define CUBE_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct	s_map
{
	int			save;
    int         taillex;
    int         tailley;
	char        *no;
    char        *so;
    char        *we;
    char        *ea;
    char        *s;
    int         f[3];
    int         c[3];
}				t_map;

#endif