
#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include "simulation.h"
//#include "timer.hpp"

extern Simulation sim;
//extern Timer fps;
extern int frame;

extern int subwindows[3];

struct GlutCallbacks {
    void (*idle) ();
    void (*keyboard) (unsigned char, int, int);
    void (*special) (int, int, int);
    GlutCallbacks() : idle(NULL), keyboard(NULL), special(NULL) {}
};

void run_glut(const GlutCallbacks&);

void redisplay();

#endif
