

#ifndef BAH_HPP
#define BAH_HPP

// Bounding area hierarchy for triangles in 2D
// based on bvh.hpp

#include "mesh.h"
#include "util.h"

struct Box {
    Vec2 umin, umax;
    Box() : umin(Vec2(infinity)), umax(Vec2(-infinity)) {}
    Box(const Vec2& u) : umin(u), umax(u) {}
    Box& operator+= (const Vec2& u);
    Box& operator+= (const Box& box);
    bool overlaps(const Box& box) const;
    Vec2 size() const;
    Vec2 center() const;
};

struct BahNode {
    Box box;
    Face* face;
    BahNode* parent;
    BahNode* left;
    BahNode* right;
    BahNode();
    BahNode(BahNode*, Face*, const Box&);
    BahNode(BahNode*, Face**, unsigned int, Box*, Vec2*);
    ~BahNode();
};

BahNode* new_bah_tree(const Mesh& mesh);
void delete_bah_tree(BahNode* root);

typedef void (*BahCallback) (Face* face0, const Face* face1);
void for_overlapping_faces(Face* face, const BahNode* node,
    BahCallback callback);

#endif
