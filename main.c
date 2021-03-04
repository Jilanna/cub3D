#include "cube.h"

int input(int ac, char **av)
{
    t_map   *map;

    if (ac < 2)
        return (-1);
    map = malloc(sizeof(t_map));
    if (map == NULL)
        return (-1);
    ft_init(map);
    if (ac >= 3 && ft_strcmp("--save", av[2]) == 0)
        map->save = 1;

    
    return (0);
}

void    init(t_map *map)
{
    map->save = 0;
    map->taillex = 0;
    map->tailley = 0;
    map->no = NULL;
    map->so = NULL;
    map->we = NULL;
    map->ea = NULL;
    map->s = NULL;
    map->f[0] = -1;
    map->f[1] = -1;
    map->f[2] = -1;
    map->c[0] = -1;
    map->c[1] = -1;
    map->c[2] = -1;
}

int main(int ac, char **av)
{
    int     out;

    out = input(ac, av);
    return (0);
}