#include "Vector.h"

float scaleGeom::crossProduct2D(Vector2f v1, Vector2f v2)
{
    return v1[X] * v2[Y] - v1[Y] * v2[X];
}

scaleGeom::Vector3f scaleGeom::crossProduct3D(Vector3f v1, Vector3f v2)
{
    float x = v1[Y] * v2[Z] - v1[Z] * v2[Y];
    float y = v1[Z] * v2[X] - v1[X] * v2[Z];
    float z = v1[X] * v2[Y] - v1[Y] * v2[X];

    return Vector3f(x, y, z);
}
