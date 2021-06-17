
#ifndef CLOTH_HPP
#define CLOTH_HPP

//#include "dde.hpp"
#include "mesh.h"

struct Cloth {
    Mesh mesh;
    struct Material {
        double density; // area density
        StretchingSamples stretching;   // 拉伸
        BendingData bending;                //弯折
        double damping; // stiffness-proportional damping coefficient 刚度比例阻尼系数?
        double strain_min, strain_max; // strain limits 屈服极限
        double yield_curv, weakening; // plasticity parameters
    };
    std::vector<Material*> materials;
    struct Remeshing {
        double refine_angle, refine_compression, refine_velocity;
        double size_min, size_max; // size limits
        double aspect_min; // aspect ratio control
    } remeshing;
};

void compute_masses(Cloth& cloth);

#endif
