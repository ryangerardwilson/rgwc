# rgwc

`rgwc` is a simple C library that provides modules for text formatting and vector physics calculations.

## Installation

To install the library, clone this repository, and run the `install.sh` script:

```bash
./install.sh
```

This will compile the source files, create a static library `librgwc.a`, and install the library and header files to `/usr/local/lib/` and `/usr/local/include/` respectively.

## Usage

To use the library in your C project, include the main header file `rgwc.h`:

```c
#include <rgwc.h>
#include <stdio.h>

int main() {
    // Text Formatting Example
    heading("Text Formatting");
    sub_heading("Sub-heading example");

    // Vector Physics Example
    heading("Vector Physics");
    Vector2D v1 = {3.0, 4.0};
    Vector2D v2 = {1.0, 2.0};

    printf("Vector v1: (%.2f, %.2f)\n", v1.x, v1.y);
    printf("Magnitude of v1: %.2f\n", vec2d_magnitude(v1));

    Vector2D sum = vec2d_add(v1, v2);
    printf("v1 + v2: (%.2f, %.2f)\n", sum.x, sum.y);

    return 0;
}
```

When compiling, you need to link against the `rgwc` library and the math library (`-lm`):

```bash
cc your_program.c -o your_program -lrgwc -lm
```

## Modules

The library is organized into the following modules:

### Text Formatting

The `text_formatting` module provides functions for printing formatted headings and sub-headings to the console.

### Vector Physics

The `vector_physics` module provides data structures and functions for 2D and 3D vector operations, including addition, subtraction, scaling, dot product, cross product, magnitude, and normalization.

## API Reference

### Text Formatting

- `void heading(const char *text)`: Prints a formatted main heading.
- `int sub_heading(const char *text)`: Prints a formatted sub-heading.

### Vector Physics

**2D Vectors**

- `Vector2D vec2d_add(Vector2D a, Vector2D b)`: Adds two 2D vectors.
- `Vector2D vec2d_sub(Vector2D a, Vector2D b)`: Subtracts two 2D vectors.
- `Vector2D vec2d_scale(Vector2D v, double scalar)`: Scales a 2D vector.
- `double vec2d_dot(Vector2D a, Vector2D b)`: Computes the dot product of two 2D vectors.
- `double vec2d_magnitude(Vector2D v)`: Computes the magnitude of a 2D vector.
- `Vector2D vec2d_normalize(Vector2D v)`: Normalizes a 2D vector.
- `Vector2D vec2d_zero(void)`: Returns a zero 2D vector.

**3D Vectors**

- `Vector3D vec3d_add(Vector3D a, Vector3D b)`: Adds two 3D vectors.
- `Vector3D vec3d_sub(Vector3D a, Vector3D b)`: Subtracts two 3D vectors.
- `Vector3D vec3d_scale(Vector3D v, double scalar)`: Scales a 3D vector.
- `double vec3d_dot(Vector3D a, Vector3D b)`: Computes the dot product of two 3D vectors.
- `Vector3D vec3d_cross(Vector3D a, Vector3D b)`: Computes the cross product of two 3D vectors.
- `double vec3d_magnitude(Vector3D v)`: Computes the magnitude of a 3D vector.
- `Vector3D vec3d_normalize(Vector3D v)`: Normalizes a 3D vector.
- `Vector3D vec3d_zero(void)`: Returns a zero 3D vector.

## Contributing

Contributions are welcome! Please feel free to submit a pull request.

## License

This project is licensed under the MIT License.
