#!/bin/bash
# Compile and install rgwc library globally to /usr/local/include and /usr/local/lib
# Exit on any error
set -e
# Compile source files to object files
echo "Compiling main.c..."
cc -c main.c -o main.o -std=c99 -Wno-format-truncation
echo "Compiling text_formatting.c..."
cc -c modules/text_formatting.c -o text_formatting.o -std=c99 -Wno-format-truncation
echo "Compiling vector_physics.c..."
cc -c modules/vector_physics.c -o vector_physics.o -std=c99
# Create static library
echo "Creating librgwc.a..."
ar rcs librgwc.a main.o text_formatting.o vector_physics.o
# Install headers to system paths
echo "Installing rgwc.h to /usr/local/include/..."
sudo cp modules/rgwc.h /usr/local/include/
echo "Installing text_formatting.h to /usr/local/include/..."
sudo cp modules/text_formatting.h /usr/local/include/
echo "Installing vector_physics.h to /usr/local/include/..."
sudo cp modules/vector_physics.h /usr/local/include/
# Install library to system path
echo "Installing librgwc.a to /usr/local/lib/..."
sudo cp librgwc.a /usr/local/lib/
# Remove object files and static library
echo "Cleaning up object files and static library..."
rm main.o text_formatting.o vector_physics.o librgwc.a
# Update linker cache
echo "Updating linker cache..."
sudo ldconfig
echo "Installation complete. You can now use '#include <rgwc.h>' and link with '-lrgwc -lm'."
