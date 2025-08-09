#include "vector_physics.h"

// 2D Vector Operations
Vector2D vec2d_add(Vector2D a, Vector2D b) {
    Vector2D result = {a.x + b.x, a.y + b.y};
    return result;
}

Vector2D vec2d_sub(Vector2D a, Vector2D b) {
    Vector2D result = {a.x - b.x, a.y - b.y};
    return result;
}

Vector2D vec2d_scale(Vector2D v, double scalar) {
    Vector2D result = {v.x * scalar, v.y * scalar};
    return result;
}

double vec2d_dot(Vector2D a, Vector2D b) {
    return a.x * b.x + a.y * b.y;
}

double vec2d_magnitude(Vector2D v) {
    return sqrt(v.x * v.x + v.y * v.y);
}

Vector2D vec2d_normalize(Vector2D v) {
    double mag = vec2d_magnitude(v);
    if (mag == 0) return vec2d_zero(); // Avoid division by zero
    Vector2D result = {v.x / mag, v.y / mag};
    return result;
}

Vector2D vec2d_zero(void) {
    Vector2D result = {0.0, 0.0};
    return result;
}

// 3D Vector Operations
Vector3D vec3d_add(Vector3D a, Vector3D b) {
    Vector3D result = {a.x + b.x, a.y + b.y, a.z + b.z};
    return result;
}

Vector3D vec3d_sub(Vector3D a, Vector3D b) {
    Vector3D result = {a.x - b.x, a.y - b.y, a.z - b.z};
    return result;
}

Vector3D vec3d_scale(Vector3D v, double scalar) {
    Vector3D result = {v.x * scalar, v.y * scalar, v.z * scalar};
    return result;
}

double vec3d_dot(Vector3D a, Vector3D b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vector3D vec3d_cross(Vector3D a, Vector3D b) {
    Vector3D result = {
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    };
    return result;
}

double vec3d_magnitude(Vector3D v) {
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

Vector3D vec3d_normalize(Vector3D v) {
    double mag = vec3d_magnitude(v);
    if (mag == 0) return vec3d_zero(); // Avoid division by zero
    Vector3D result = {v.x / mag, v.y / mag, v.z / mag};
    return result;
}

Vector3D vec3d_zero(void) {
    Vector3D result = {0.0, 0.0, 0.0};
    return result;
}
