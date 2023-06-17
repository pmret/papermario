#include "area.h"

#define NAMESPACE A(monstar)

extern Vtx monstar_bubbles[66];

Gfx N(dlist)[] = {
    gsSPVertex(&monstar_bubbles[0], 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
    gsSP2Triangles(20, 21, 22, 0, 20, 22, 23, 0),
    gsSP2Triangles(24, 25, 26, 0, 24, 26, 27, 0),
    gsSP2Triangles(28, 29, 30, 0, 28, 30, 31, 0),
    gsSPVertex(&monstar_bubbles[32], 32, 0),
    gsSP2Triangles(0, 8, 9, 0, 0, 9, 10, 0),
    gsSP2Triangles(1, 11, 12, 0, 1, 12, 13, 0),
    gsSP2Triangles(2, 14, 15, 0, 2, 15, 16, 0),
    gsSP2Triangles(3, 17, 18, 0, 3, 18, 19, 0),
    gsSP2Triangles(4, 20, 21, 0, 4, 21, 22, 0),
    gsSP2Triangles(5, 23, 24, 0, 5, 24, 25, 0),
    gsSP2Triangles(6, 26, 27, 0, 6, 27, 28, 0),
    gsSP2Triangles(7, 29, 30, 0, 7, 30, 31, 0),
    gsSPVertex(&monstar_bubbles[8], 1, 0),
    gsSPVertex(&monstar_bubbles[11], 2, 1),
    gsSPVertex(&monstar_bubbles[15], 2, 3),
    gsSPVertex(&monstar_bubbles[19], 1, 5),
    gsSPVertex(&monstar_bubbles[35], 5, 6),
    gsSPVertex(&monstar_bubbles[51], 1, 11),
    gsSPVertex(&monstar_bubbles[54], 1, 12),
    gsSPVertex(&monstar_bubbles[57], 1, 13),
    gsSPVertex(&monstar_bubbles[60], 1, 14),
    gsSPVertex(&monstar_bubbles[63], 3, 15),
    gsSP2Triangles(1, 16, 0, 0, 3, 16, 2, 0),
    gsSP2Triangles(5, 16, 4, 0, 11, 16, 6, 0),
    gsSP2Triangles(12, 17, 7, 0, 13, 16, 8, 0),
    gsSP2Triangles(14, 16, 9, 0, 15, 16, 10, 0),
    gsSPEndDisplayList(),
};

