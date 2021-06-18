
#ifndef COLLISIONUTIL_HPP
#define COLLISIONUTIL_HPP

#include "bvh.hpp"

typedef DeformBVHNode BVHNode;
typedef DeformBVHTree BVHTree;

struct AccelStruct {
    BVHTree tree;
    BVHNode* root;
    std::vector<BVHNode*> leaves;
    AccelStruct(const Mesh& mesh, bool ccd);
};

void update_accel_struct(AccelStruct& acc);

void mark_all_inactive(AccelStruct& acc);
void mark_active(AccelStruct& acc, const Face* face);

// callback must be safe to parallelize via OpenMP
typedef void (*BVHCallback) (const Face* face0, const Face* face1);

void for_overlapping_faces(BVHNode* node, float thickness,
    BVHCallback callback);
void for_overlapping_faces(BVHNode* node0, BVHNode* node1, float thickness,
    BVHCallback callback);
void for_overlapping_faces(const std::vector<AccelStruct*>& accs,
    const std::vector<AccelStruct*>& obs_accs,
    double thickness, BVHCallback callback,
    bool parallel = true);
void for_faces_overlapping_obstacles(const std::vector<AccelStruct*>& accs,
    const std::vector<AccelStruct*>& obs_accs,
    double thickness, BVHCallback callback,
    bool parallel = true);

std::vector<AccelStruct*> create_accel_structs
(const std::vector<Mesh*>& meshes, bool ccd);
void destroy_accel_structs(std::vector<AccelStruct*>& accs);

// find index of mesh containing specified element
template <typename Prim>
int find_mesh(const Prim* p, const std::vector<Mesh*>& meshes);

extern const std::vector<Mesh*>* meshes; // to check if element is cloth or obs
extern const std::vector<Mesh*>* obs_meshes;
template <typename Primitive> bool is_free(const Primitive* p) {
    return find_mesh(p, *::meshes) != -1;
}

#endif
