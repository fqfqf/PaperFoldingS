
#include "displayphysics.h"

//#include "display.hpp"
//#include "io.hpp"
//#include "opengl.hpp"
//#include "misc.hpp"
//#include "runphysics.hpp"
//#include "simulation.hpp"
//#include "timer.hpp"
//#include "util.hpp"

#include <assert.h>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <sstream>
using namespace std;

#ifndef NO_OPENGL

extern string outprefix;
extern fstream timingfile;

static bool running = false;

static void idle() {
    if (!::running)
        return;
    //sim_step();
    //redisplay();
}

extern void zoom(bool in);

static void keyboard(unsigned char key, int x, int y) {
    unsigned char esc = 27, space = ' ';
    if (key == esc) {
        exit(EXIT_SUCCESS);
    }
    else if (key == space) {
        ::running = !::running;
    }
    else if (key == 's') {
        ::running = !::running;
        idle();
        ::running = !::running;
    }
    else if (key == 'z') {
        zoom(true);
    }
    else if (key == 'x') {
        zoom(false);
    }
}

void display_physics(const vector<string>& args) {
    //if (args.size() != 1 && args.size() != 2) {
    //    cout << "Runs the simulation with an OpenGL display." << endl;
    //    cout << "Arguments:" << endl;
    //    cout << "    <scene-file>: JSON file describing the simulation setup"
    //        << endl;
    //    cout << "    <out-dir> (optional): Directory to save output in" << endl;
    //    exit(EXIT_FAILURE);
    //}
    //string json_file = args[0];
    //string outprefix = args.size() > 1 ? args[1] : "";
    //if (!outprefix.empty())
    //    ensure_existing_directory(outprefix);
    //init_physics(json_file, outprefix, false);
    //if (!outprefix.empty())
    //    save(sim, 0);
    //GlutCallbacks cb;
    //cb.idle = idle;
    //cb.keyboard = keyboard;
    //run_glut(cb);
}

void display_resume(const vector<string>& args) {
    //if (args.size() != 2) {
    //    cout << "Resumes an incomplete simulation." << endl;
    //    cout << "Arguments:" << endl;
    //    cout << "    <out-dir>: Directory containing simulation output files"
    //        << endl;
    //    cout << "    <resume-frame>: Frame number to resume from" << endl;
    //    exit(EXIT_FAILURE);
    //}
    //init_resume(args);
    //GlutCallbacks cb;
    //cb.idle = idle;
    //cb.keyboard = keyboard;
    //run_glut(cb);
}

#else

void display_physics(const vector<string>& args) { opengl_fail(); }

void display_resume(const vector<string>& args) { opengl_fail(); }

#endif // NO_OPENGL
