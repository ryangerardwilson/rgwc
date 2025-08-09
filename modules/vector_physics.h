#ifndef VECTOR_PHYSICS_H
#define VECTOR_PHYSICS_H

#include <math.h> // Required for sqrt

/* 2D Vector: Represents a vector with x, y components */
typedef struct {
    double x;
    double y;
} Vector2D;

/* 3D Vector: Represents a vector with x, y, z components */
typedef struct {
    double x;
    double y;
    double z;
} Vector3D;

/* 2D Vector Operations */
/* Add two 2D vectors: result = a + b */
Vector2D vec2d_add(Vector2D a, Vector2D b);
/* Subtract two 2D vectors: result = a - b */
Vector2D vec2d_sub(Vector2D a, Vector2D b);
/* Scale a 2D vector: result = v * scalar */
Vector2D vec2d_scale(Vector2D v, double scalar);
/* Compute dot product of two 2D vectors: a · b */
double vec2d_dot(Vector2D a, Vector2D b);
/* Compute magnitude of a 2D vector: |v| */
double vec2d_magnitude(Vector2D v);
/* Normalize a 2D vector: v / |v| (returns zero vector if |v| = 0) */
Vector2D vec2d_normalize(Vector2D v);
/* Return a zero 2D vector: (0, 0) */
Vector2D vec2d_zero(void);

/* 3D Vector Operations */
/* Add two 3D vectors: result = a + b */
Vector3D vec3d_add(Vector3D a, Vector3D b);
/* Subtract two 3D vectors: result = a - b */
Vector3D vec3d_sub(Vector3D a, Vector3D b);
/* Scale a 3D vector: result = v * scalar */
Vector3D vec3d_scale(Vector3D v, double scalar);
/* Compute dot product of two 3D vectors: a · b */
double vec3d_dot(Vector3D a, Vector3D b);
/* Compute cross product of two 3D vectors: a × b */
Vector3D vec3d_cross(Vector3D a, Vector3D b);
/* Compute magnitude of a 3D vector: |v| */
double vec3d_magnitude(Vector3D v);
/* Normalize a 3D vector: v / |v| (returns zero vector if |v| = 0) */
Vector3D vec3d_normalize(Vector3D v);
/* Return a zero 3D vector: (0, 0, 0) */
Vector3D vec3d_zero(void);

#endif
