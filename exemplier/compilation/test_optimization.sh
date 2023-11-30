#!/bin/sh

#
# ENSICAEN
# 6 Boulevard Maréchal Juin
# F-14050 Caen Cedex
#
# Examples from the course "Software development tools"
# Exemplier du cours "Outils de développement logiciel" (ODL)
#
# Chapter "Compilation" / Chapitre "Compilation"
#
# Copyright (C) 1995-2023 Alain Lebret (alain.lebret@ensicaen.fr)
#

# Script to compile and test C programs with various optimization levels

compile_and_test() {
    local program_name=$1

    echo "Testing optimization options for $program_name"
    for opt in 0 1 2 3 s; do
        if ! gcc -O$opt "$program_name.c" -o "${program_name}_O$opt"; then
            echo "Compilation failed for optimization level O$opt."
            return 1
        fi
        echo "${program_name}_O$opt"
        time ./"${program_name}_O$opt"
        read -p "Press any key to continue..." -n 1 -s
    done
}

# Compile and test 'small' and 'bubbles' programs
if [ -f "small.c" ] && [ -f "bubbles.c" ]; then
    compile_and_test "small"
    compile_and_test "bubbles"
else
    echo "Error: Required source files not found."
    exit 1
fi

echo "Suppressing unwanted files..."
read -p "Are you sure you want to delete compiled files? (y/n) " confirm
if [ "$confirm" = "y" ]; then
    rm small_O0 small_O1 small_O2 small_O3 small_Os bubbles_O0 bubbles_O1 bubbles_O2 bubbles_O3 bubbles_Os a.out *.a *.s *.i *.o *.txt
fi
