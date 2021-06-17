
#ifndef SIMULATION_HPP
#define SIMULATION_HPP

//#include "cloth.hpp"
//#include "constraint.hpp"
//#include "handle.hpp"
//#include "morph.hpp"
//#include "obstacle.hpp"
//#include "spline.hpp"
//#include "timer.hpp"
#include <string>
#include <vector>

// why paper simulation need wind??
//struct Wind {
//    double density;
//    Vec3 velocity;
//    double drag;
//};

struct Simulation {
    // variables
    double time;
    int frame, step;
    //std::vector<Cloth> cloths;
    // constants
    int frame_steps;
    double frame_time, step_time;
    double end_time, end_frame;

    std::vector<Motion> motions;
    std::vector<Handle*> handles;
    std::vector<Obstacle> obstacles;
    std::vector<Morph> morphs;

    Vec3 gravity;
    //Wind wind;    // why wind?
    double friction, obs_friction;

    enum {
        Proximity, Physics, StrainLimiting, Collision, Remeshing, Separation,
        PopFilter, Plasticity, nModules
    };

    bool enabled[nModules];
    //Timer timers[nModules];
    // handy pointers
    //std::vector<Mesh*> cloth_meshes, obstacle_meshes;
};

void prepare(Simulation& sim);

void relax_initial_state(Simulation& sim);

void advance_frame(Simulation& sim);

void advance_step(Simulation& sim);

// Helper functions

//template <typename Prim> int size(const std::vector<Mesh*>& meshes);
//template <typename Prim> int get_index(const Prim* p,
//const std::vector<Mesh*>& meshes);
//template <typename Prim> Prim* get(int i, const std::vector<Mesh*>& meshes);
//
//std::vector<Vec3> node_positions(const std::vector<Mesh*>& meshes);

#endif
