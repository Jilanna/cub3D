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
    char        **map;
}				t_params;

#endif

/*
INIT:
params->sizex = -1;
params->sizey = -1;
params->no = NULL;
params->so = NULL;
params->we = NULL;
params->ea = NULL;
params->s = NULL;
params->f[0] = -1;
params->f[1] = -1;
params->f[2] = -1;
params->c[0] = -1;
params->c[1] = -1;
params->c[2] = -1;

R 1920 1080
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture
S ./path_to_the_sprite_texture
F 220,100,0
C 225,30,0
*/