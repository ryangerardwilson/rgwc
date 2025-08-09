#!/bin/bash

# Compile and install rgwc library globally to /usr/local/include and /usr/local/lib

# Exit on any error
set -e

# Compile rgwc.c to object file
echo "Compiling rgwc.c..."
cc -c rgwc.c -o rgwc.o -std=c99 -Wno-format-truncation

# Create static library
echo "Creating librgwc.a..."
ar rcs librgwc.a rgwc.o

# Install header and library to system paths
echo "Installing rgwc.h to /usr/local/include/..."
sudo cp rgwc.h /usr/local/include/
echo "Installing librgwc.a to /usr/local/lib/..."
sudo cp librgwc.a /usr/local/lib/

# Update linker cache
echo "Updating linker cache..."
sudo ldconfig

echo "Installation complete. You can now use '#include <rgwc.h>' and link with '-lrgwc'."
