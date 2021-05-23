#include "../includes/cube.h"
#include "../includes/libft.h"

void    lodev(t_params *p)
{
    int x;

  while(!done())
  {
    x = 0;
    while (x < p->width)
    {
      //calculate ray position and direction
      p->camerax = 2 * x / (double)p->width - 1; //x-coordinate in camera space
      p->raydirx = p->dirx + p->planex * p->camerax;
      p->raydiry = p->diry + p->planey * p->camerax;

      //which box of the map we're in
      p->mapx = int(p->posx);
      p->mapy = int(p->posy);

      //length of ray from current position to next x or y-side
      //double sideDistX;
      //double sideDistY;

      //length of ray from one x or y-side to next x or y-side
      p->deltadistx = std::abs(1 / p->raydirx);
      p->deltadisty = std::abs(1 / p->raydiry);
      //double perpWallDist;

      //what direction to step in x or y-direction (either +1 or -1)
      //int stepX;
      //int stepY;

      p->hit = 0; //was there a wall hit?
      //int side; //was a NS or a EW wall hit?

      //calculate step and initial sideDist
      if(p->raydirx < 0)
      {
        p->stepX = -1;
        p->sidedistx = (p->posx - p->mapx) * p->deltadistx;
      }
      else
      {
        p->stepx = 1;
        p->sidedistx = (p->mapx + 1.0 - p->posx) * p->deltadistx;
      }
      if(p->raydiry < 0)
      {
        p->stepy = -1;
        p->sidedisty = (p->posy - p->mapy) * p->deltadisty;
      }
      else
      {
        p->stepy = 1;
        p->sidedisty = (p->mapy + 1.0 - p->posy) * p->deltadisty;
      }
      //perform DDA
      while (p->hit == 0)
      {
        //jump to next map square, OR in x-direction, OR in y-direction
        if(p->sidedistx < p->sidedisty)
        {
          p->sidedistx += p->deltadistx;
          p->mapx += p->stepx;
          p->side = 0;
        }
        else
        {
          p->sidedisty += p->deltadisty;
          p->mapy += p->stepy;
          p->side = 1;
        }
        //Check if ray has hit a wall
        if(p->map[p->mapx][p->mapy] > 0)
            p->hit = 1;
      }

      //Calculate distance of perpendicular ray (Euclidean distance will give fisheye effect!)
      if(p->side == 0)
        p->perpwalldist = (p->mapx - p->posx + (1 - p->stepx) / 2) / p->raydirx;
      else
        p->perpwalldist = (p->mapy - p->posy + (1 - p->stepy) / 2) / p->raydiry;

      //Calculate height of line to draw on screen
      p->lineheight = (int)(p->hight / p->perpwalldist);

      //calculate lowest and highest pixel to fill in current stripe
      p->drawstart = -(p->lineheight) / 2 + p->hight / 2;
      if(p->drawstart < 0)
        p->drawstart = 0;
      p->drawend = p->lineheight / 2 + p->hight / 2;
      if(p->drawend >= p->hight)
        p->drawend = p->hight - 1;

      //texturing calculations
      int texNum = worldMap[p->mapx][p->mapy] - 1; //1 subtracted from it so that texture 0 can be used!

      //calculate value of wallX
      double wallX; //where exactly the wall was hit
      if(p->side == 0) wallX = p->posy + p->perpwalldist * p->raydiry;
      else          wallX = p->posx + p->perpwalldist * p->raydirx;
      wallX -= floor((wallX));

      //x coordinate on the texture
      int texX = int(wallX * double(texWidth));
      if(p->side == 0 && p->raydirx > 0) texX = texWidth - texX - 1;
      if(p->side == 1 && p->raydiry < 0) texX = texWidth - texX - 1;

      // TODO: an integer-only bresenham or DDA like algorithm could make the texture coordinate stepping faster
      // How much to increase the texture coordinate per screen pixel
      double step = 1.0 * texHeight / p->lineheight;
      // Starting texture coordinate
      double texPos = (p->drawstart - p->hight / 2 + p->lineheight / 2) * step;
      for(int y = p->drawstart; y < p->drawend; y++)
      {
        // Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
        int texY = (int)texPos & (texHeight - 1);
        texPos += step;
        Uint32 color = texture[texNum][texHeight * texY + texX];
        //make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
        if(p->side == 1) color = (color >> 1) & 8355711;
        buffer[y][x] = color;
	x++;
      }
    }

    drawBuffer(buffer[0]);
    for(int y = 0; y < p->hight; y++) for(int x = 0; x < w; x++) buffer[y][x] = 0; //clear the buffer instead of cls()
    //timing for input and FPS counter
    oldTime = time;
    time = getTicks();
    double frameTime = (time - oldTime) / 1000.0; //frametime is the time this frame has taken, in seconds
    print(1.0 / frameTime); //FPS counter
    redraw();

    //speed modifiers
    double moveSpeed = frameTime * 5.0; //the constant value is in squares/second
    double rotSpeed = frameTime * 3.0; //the constant value is in radians/second

    readKeys();
    //move forward if no wall in front of you
    if(keyDown(SDLK_UP))
    {
      if(worldMap[int(p->posx + p->dirx * moveSpeed)][int(p->posy)] == false) p->posx += p->dirx * moveSpeed;
      if(worldMap[int(p->posx)][int(p->posy + p->diry * moveSpeed)] == false) p->posy += p->diry * moveSpeed;
    }
    //move backwards if no wall behind you
    if(keyDown(SDLK_DOWN))
    {
      if(worldMap[int(p->posx - p->dirx * moveSpeed)][int(p->posy)] == false) p->posx -= p->dirx * moveSpeed;
      if(worldMap[int(p->posx)][int(p->posy - p->diry * moveSpeed)] == false) p->posy -= p->diry * moveSpeed;
    }
    //rotate to the right
    if(keyDown(SDLK_RIGHT))
    {
      //both camera direction and camera plane must be rotated
      double oldDirX = p->dirx;
      p->dirx = p->dirx * cos(-rotSpeed) - p->diry * sin(-rotSpeed);
      p->diry = oldDirX * sin(-rotSpeed) + p->diry * cos(-rotSpeed);
      double oldPlaneX = p->planex;
      p->planex = p->planex * cos(-rotSpeed) - p->planey * sin(-rotSpeed);
      p->planey = oldPlaneX * sin(-rotSpeed) + p->planey * cos(-rotSpeed);
    }
    //rotate to the left
    if(keyDown(SDLK_LEFT))
    {
      //both camera direction and camera plane must be rotated
      double oldDirX = p->dirx;
      p->dirx = p->dirx * cos(rotSpeed) - p->diry * sin(rotSpeed);
      p->diry = oldDirX * sin(rotSpeed) + p->diry * cos(rotSpeed);
      double oldPlaneX = p->planex;
      p->planex = p->planex * cos(rotSpeed) - p->planey * sin(rotSpeed);
      p->planey = oldPlaneX * sin(rotSpeed) + p->planey * cos(rotSpeed);
    }
    if(keyDown(SDLK_ESCAPE))
    {
      break;
    }
  }
}