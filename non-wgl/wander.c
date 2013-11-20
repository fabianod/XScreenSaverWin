/* wander, by Rick Campbell <rick@campbellcentral.org>, 19 December 1998.
 *
 * Permission to use, copy, modify, distribute, and sell this software and its
 * documentation for any purpose is hereby granted without fee, provided that
 * the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation.  No representations are made about the suitability of this
 * software for any purpose.  It is provided "as is" without express or 
 * implied warranty.
 */

#include "screenhack.h"
#include <stdio.h>

#include "colors.h"
#include "erase.h"

#define MAXIMUM_COLOR_COUNT (256)

float eraseSeconds = 0;
char *eraseMode = NULL;

char *background = "black";
char *foreground = "white";
int advance = 1;
int density = 2;
int length = 25000;
int delay = 20000;
int reset = 2500000;
Bool circles = False;
int size = 1;


static argtype vars[] = 
{
    {&background, "background", NULL, "black", t_String},
    {&foreground, "foreground", NULL, "white", t_String},
    {&advance, "advance", NULL, "1", t_Int},
    {&density, "density", NULL, "2", t_Int},
    {&length, "length", NULL, "25000", t_Int},
    {&delay, "delay", NULL, "20000", t_Int},
    {&reset, "reset", NULL, "2500000", t_Int},
    {&circles, "circles", NULL, "False", t_Bool},
    {&size, "size", NULL, "1", t_Int},
};

struct state {
  Display *dpy;
  Window window;

   unsigned int advance;
   Bool         circles;
   Colormap     color_map;
   int          color_count;
   int          color_index;
   XColor       colors      [MAXIMUM_COLOR_COUNT];
   GC           context;
   unsigned int density;
   int          depth;
   int          height;
   unsigned int length;
   unsigned int reset;
   unsigned int size;
   int          width;
   int delay;

  int x, y, last_x, last_y, width_1, height_1, length_limit, reset_limit;
  unsigned long color;
  Pixmap pixmap;

  eraser_state *eraser;
};


static void *
wander_init (Display *dpy, Window window)
{
    struct state *st = (struct state *) calloc (1, sizeof(*st));
    XGCValues values;
    XWindowAttributes attributes;

    st->dpy = dpy;
    st->window = window;
    //st->delay = get_integer_resource (st->dpy, "delay", "Integer");
    st->delay = delay;

    XClearWindow (st->dpy, st->window);
    XGetWindowAttributes (st->dpy, st->window, &attributes);
    st->width = attributes.width;
    st->height = attributes.height;
    st->depth = attributes.depth;
    st->color_map = attributes.colormap;
    if (st->color_count)
    {
        free_colors (attributes.screen, st->color_map,
                     st->colors, st->color_count);
        st->color_count = 0;
    }
    st->context = XCreateGC (st->dpy, st->window, 0, &values);
    st->color_count = MAXIMUM_COLOR_COUNT;
    make_color_loop (attributes.screen, attributes.visual, st->color_map,
                    0,   1, 1,
                    120, 1, 1,
                    240, 1, 1,
                    st->colors, &st->color_count, True, False);
    if (st->color_count <= 0)
    {
        st->color_count = 2;
        st->colors [0].red = st->colors [0].green = st->colors [0].blue = 0;
        st->colors [1].red = st->colors [1].green = st->colors [1].blue = 0xFFFF;
        XAllocColor (st->dpy, st->color_map, &st->colors [0]);
        XAllocColor (st->dpy, st->color_map, &st->colors [1]);
    }
    st->color_index = random () % st->color_count;
    
    //st->advance = get_integer_resource (st->dpy, "advance", "Integer");
    //st->density = get_integer_resource (st->dpy, "density", "Integer");
    st->advance = advance;
    st->density = density;
    if (st->density < 1) st->density = 1;
    //st->reset = get_integer_resource (st->dpy, "reset", "Integer");
    st->reset = reset;
    if (st->reset < 100) st->reset = 100;
    //st->circles = get_boolean_resource (st->dpy, "circles", "Boolean");
    //st->size = get_integer_resource (st->dpy, "size", "Integer");
    st->circles = circles;
    st->size = size;
    if (st->size < 1) st->size = 1;
    st->width = st->width / st->size;
    st->height = st->height / st->size;
    //st->length = get_integer_resource (st->dpy, "length", "Integer");
    st->length = length;
    if (st->length < 1) st->length = 1;
    XSetForeground (st->dpy, st->context, st->colors [st->color_index].pixel);


    st->x = random () % st->width;
    st->y = random () % st->height;
    st->last_x = st->x;
    st->last_y = st->y;
    st->width_1 = st->width - 1;
    st->height_1 = st->height - 1;
    st->length_limit = st->length;
    st->reset_limit = st->reset;
    st->color_index = random () % st->color_count;
    st->color = st->colors [random () % st->color_count].pixel;
    st->pixmap = XCreatePixmap (st->dpy, window, st->size,
                            st->size, st->depth);

    XSetForeground (st->dpy, st->context,
		    BlackPixel (st->dpy, DefaultScreen (st->dpy)));
    XFillRectangle (st->dpy, st->pixmap, st->context, 0, 0,
		    st->width * st->size, st->height * st->size);
    XSetForeground (st->dpy, st->context, st->color);
    XFillArc (st->dpy, st->pixmap, st->context, 0, 0, st->size, st->size, 0, 360*64);

    return st;
}


static unsigned long
wander_draw (Display *dpy, Window window, void *closure)
{
  struct state *st = (struct state *) closure;
  int i;

  if (st->eraser) {
    st->eraser = erase_window (st->dpy, st->window, st->eraser);
    goto END;
  }

  for (i = 0; i < 2000; i++)
    {
      if (random () % st->density)
        {
          st->x = st->last_x;
          st->y = st->last_y;
        }
      else
        {
          st->last_x = st->x;
          st->last_y = st->y;
          st->x = (st->x + st->width_1  + (random () % 3)) % st->width;
          st->y = (st->y + st->height_1 + (random () % 3)) % st->height;
        }

      if ((random () % st->length_limit) == 0)
        {
          if (st->advance == 0)
            {
              st->color_index = random () % st->color_count;
            }
          else
            {
              st->color_index = (st->color_index + st->advance) % st->color_count;
            }
          st->color = st->colors [st->color_index].pixel;
          XSetForeground (st->dpy, st->context, st->color);
          if (st->circles)
            {
              XFillArc (st->dpy, st->pixmap, st->context,
                        0, 0, st->size, st->size, 0, 360 * 64);
            }
        }

      if ((random () % st->reset_limit) == 0)
        {
          st->eraser = erase_window (st->dpy, st->window, st->eraser);
          st->color = st->colors [random () % st->color_count].pixel;
          st->x = random () % st->width;
          st->y = random () % st->height;
          st->last_x = st->x;
          st->last_y = st->y;
          if (st->circles)
            {
              XFillArc (st->dpy, st->pixmap, st->context, 0, 0, st->size, st->size, 0, 360*64);
            }
        }

      if (st->size == 1)
        {
          XDrawPoint (st->dpy, st->window, st->context, st->x, st->y);
        }
      else
        {
          if (st->circles)
            {
              XCopyArea (st->dpy, st->pixmap, st->window, st->context, 0, 0, st->size, st->size,
                         st->x * st->size, st->y * st->size);
            }
          else
            {
              XFillRectangle (st->dpy, st->window, st->context, st->x * st->size, st->y * st->size,
                              st->size, st->size);
            }
        }
    }

 END:
  return st->delay;
}


static void
wander_reshape (Display *dpy, Window window, void *closure, 
                 unsigned int w, unsigned int h)
{
  struct state *st = (struct state *) closure;
  st->width  = w / st->size;
  st->height = h / st->size;
  st->width_1  = st->width - 1;
  st->height_1 = st->height - 1;
}

#if 0
	static Bool
	wander_event (Display *dpy, Window window, void *closure, XEvent *event)
	{
	  return False;
	}
#endif

static void
wander_free (Display *dpy, Window window, void *closure)
{
}

static const char *wander_defaults [] =
{
    ".background: black",
    ".foreground: white",
    ".fpsSolid:	  true",
    ".advance:    1",
    ".density:    2",
    ".length:     25000",
    ".delay:      20000",
    ".reset:      2500000",
    ".circles:    False",
    ".size:       1",
#ifdef USE_IPHONE
  "*ignoreRotation: True",
#endif
    0
};

static XrmOptionDescRec wander_options [] =
{
    { "-advance", ".advance", XrmoptionSepArg, 0 },
    { "-circles", ".circles",   XrmoptionNoArg, "True" },
    { "-no-circles",".circles", XrmoptionNoArg, "False" },
    { "-density", ".density", XrmoptionSepArg, 0 },
    { "-length",  ".length",  XrmoptionSepArg, 0 },
    { "-delay",   ".delay",   XrmoptionSepArg, 0 },
    { "-reset",   ".reset",   XrmoptionSepArg, 0 },
    { "-size",    ".size",    XrmoptionSepArg, 0 },
    { 0, 0, 0, 0 }
};


XSCREENSAVER_MODULE ("Wander", wander)
