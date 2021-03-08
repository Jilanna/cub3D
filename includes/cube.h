#ifndef CUBE_H
# define CUBE_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct	s_params
{
	int			save;
    int         sizex;
    int         sizey;
	char        *no;
    char        *so;
    char        *we;
    char        *ea;
    char        *s;
    int         f[3];
    int         c[3];
}				t_params;

#endif

/*
R 1920 1080
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture
S ./path_to_the_sprite_texture
F 220,100,0
C 225,30,0
*/