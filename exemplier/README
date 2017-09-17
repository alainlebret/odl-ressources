--------------------------------------------------------------------------------
                                   ENSICAEN
                           6 Boulevard Maréchal Juin
                              F-14050 Caen Cedex

              Examples from the course "Software development tools"
           Exemplier du cours "Outils de développement logiciel" (ODL)

              Chapter "The make command" / Chapitre "Commande make"
 
        Copyright (C) 1995-2017 Alain Lebret (alain.lebret@ensicaen.fr)
--------------------------------------------------------------------------------
							   
## v1
--------------------------------------------------------------------------------
In this version, the program is concentrate in a single file called
`magic_square.c` that you can compile as follows:

    $ gcc -Wall -Wextra -ansi -pedantic magic_square.c -o magic_square

## v2
--------------------------------------------------------------------------------
In this second version, the program is divided into three files:
`magic_square.c` that contains the main () function, and files `matrix.h` and
`matrix.c`, which respectively contain prototypes and definitions of functions
doing some matrix stuff.

Compile files as follows:

1. Compilation of different object files

    $ gcc -Wall -c -Wextra -ansi -pedantic magic_square.c matrix.c

2. Link object files together and product an output executable file

    $ gcc -o magic_square.o matrix.o magic_square

Note :

By compiling with the `-I.` option, you add the current directory ( `.`) to
the list of paths where the precompiler can find header files. The inclusion
of `matrix.h` can then be achieved by:

    #include <matrix.h>

instead of:

    #include "matrix.h"

## v3
--------------------------------------------------------------------------------
In this third version, we create a Makefile to compile the program using three
rules:

* Two rules to produce object files from source ones
* A rule called `magic_square` that depends on previous targets to create
  the output executable file

The program generation is obtained by running the command:

    $ make magic_square

## v4
--------------------------------------------------------------------------------
In this fourth version we create a file named `Makefile.tralala` to compile
the program using the three previous rules.

We added a comment and a rule called `clean` (without dependencies) that
eliminates all intermediate object files as the executable one.

The program generation is obtained by running the command:

    $ make -f Makefile.tralala magic_square

The `-f` option specifies the name of the Makefile if the name is not
conventional.

The rule to produce the executable file is moved at the beginning of all the
rules, so it will be run by default:

    $ make -f Makefile.tralala

## v5
--------------------------------------------------------------------------------
In this fifth version, we implement variables in the file `Makefile.mieux`.

The program generation is obtained by running the command:

    $ make -f Makefile.mieux

The `.PHONY` target indicates to `make` that the `clean` target should not be
considered as a file.

## v6
--------------------------------------------------------------------------------
In this sixth version, we add a rule to produce documentation using the doxygen
program. This is obtained by running the command:

    $ make doc

The `.PHONY` target also indicates that the target `doc` should not be considered
as a file.

## v7
--------------------------------------------------------------------------------
In this seventh version, we use `make` to compile Java files. You just have to
execute the following command:

    $ make all

Then, to run the Java program, just enter:

    $ java -jar v7.jar TestingFrame

## v8
------
In this eighth version, we consider a more complex project with several
subdirectories as below:

    ./
    | Makefile
    |
    ./bin
    |
    ./include --
    |           ./l ------
    |           |         | l.h
    |           ./m ------
    |		|         | m.h
    |
    ./src ------
    |           | main.c
    |           ./l ------
    |           |         | l.c
    |           |
    |           ./m ------
    |           |         | m.c
    |           |

Object files are generated in the subdirectories containing `.c` files and the
executable will be produced in the `bin` subdirectory.

## v9
--------------------------------------------------------------------------------
In this ninth version, we use the predefined macros `$@` and `$^` which
respectively correspond to the target name and the list of dependency files.
