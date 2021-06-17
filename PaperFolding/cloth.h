
#ifndef CLOTH_HPP
#define CLOTH_HPP

//#include "dde.hpp"
#include "mesh.h"

struct Cloth {
    Mesh mesh;
    struct Material {
        double density; // area density
        StretchingSamples stretching;   // ����
        BendingData bending;                //����
        double damping; // stiffness-proportional damping coefficient �նȱ�������ϵ��?
        double strain_min, strain_max; // strain limits ��������
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
