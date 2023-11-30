#!/bin/bash

# Check if necessary commands are available
for cmd in doxygen vim firefox; do
    if ! command -v "$cmd" &> /dev/null; then
        echo "Error: $cmd is not installed."
        exit 1
    fi
done

# Generate a default Doxyfile
doxygen -g || { echo "Failed to generate Doxyfile"; exit 1; }

# Edit the Doxyfile - consider automating this step based on typical needs
vim Doxyfile || { echo "Failed to edit Doxyfile"; exit 1; }

# Rename Doxyfile to maconfig
mv Doxyfile maconfig || { echo "Failed to rename Doxyfile"; exit 1; }

# Run Doxygen with the new configuration
doxygen maconfig || { echo "Failed to run Doxygen"; exit 1; }

# Open the generated index.html in Firefox
# Path to index.html should be adjusted based on the actual output directory
firefox index.html &
