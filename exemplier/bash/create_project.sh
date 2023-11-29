#!/bin/bash

#
# ENSICAEN
# 6 Boulevard Maréchal Juin
# F-14050 Caen Cedex
#
# Unix System Programming Examples / Exemplier de programmation système Unix
# "Shell bash" / "Interpréteur de commandes bash"
#
# Copyright (C) 1995-2023 Alain Lebret (alain.lebret@ensicaen.fr)
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#    http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

PROJECT_PATH=""
AUTHOR1="Jean Saigne"
AUTHOR2="Jacques Horde"
AUTHORS="$AUTHOR1 & $AUTHOR2"
ENTETE_C="/*
 * ENSICAEN
 * 6 Boulevard Marechal Juin
 * F-14050 Caen Cedex
 *
 * This file is owned by ENSICAEN students.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */"

# Used by customized_makefile()
 CC="gcc"
 CFLAGS="-Wall -Wextra -ansi -pedantic -g"
 INCLUDE_DIR="include"
 LIBS="-lm"
 EXEC="prog.exe"

# Example of a directory configuration array
# Used by initialize_rep()
DIR_STRUCTURE=("src" "include" "doc" "tests" "bin" "bin/tests" "etc" "lib")

# All errors are logged 
exec 2>>/tmp/create_project.log
 
# Usage example:
# error "Invalid project path" "create_project()"
function error() { 
    echo "Error in function $2: $1!" >&2 
    exit 1 
} 


#
# 
#
function help() { 
    echo "$(basename "$0") est un script shell pour créer des projets C."
    exit 0
} 

function initialize_rep() {
    if [ ! -e "$PROJECT_PATH" ]; then
       if ! mkdir "$PROJECT_PATH"; then
          echo "La création du dossier pour le projet a échoué."
          return 1
       fi
       for dir in "${DIR_STRUCTURE[@]}"; do
          mkdir -p "$PROJECT_PATH/$dir"
		  touch "$PROJECT_PATH/$dir/.gitkeep"
       done
       return 0
    else
       echo "Le projet existe déjà"
       return 1
 fi
}


#
# 
#
function create_README() {
   cat > "$PROJECT_PATH/README.md"<<EOF
# Projet "$PROJECT_PATH"
## Description

A complete description of the project...

## Installation

A complete description of its installation...

```
make ...
```

## Usage 

A description of its usage...

## Dependancies

List of dependances... 

## Authors

"$AUTHORS"
$(date)
EOF
}


function customize_makefile() {
    echo "Spécifiez le compilateur (par défaut : gcc) :"
    read -r input
    CC=${input:-gcc}

    echo "Spécifiez les options du compilateur (par défaut : -Wall -Wextra -ansi -pedantic -g) :"
    read -r input
    CFLAGS=${input:--Wall -Wextra -ansi -pedantic -g}

    echo "Spécifiez le dossier contenant les entêtes (par défaut : include) :"
    read -r input
    INCLUDE_DIR=${input:-include}

    echo "Spécifiez les bibliothèques utilisées (par défaut : lm) :"
    read -r input
    LIBS=${input:--lm}

    echo "Spécifiez le nom du programme exécutable (par défaut : prog.exe) :"
    read -r input
    EXEC=${input:-prog.exe}
}

#
# 
#
function create_Makefile() {
   echo "CC       = ${CC}
RM       = rm
DOC      = doxygen
CPPFLAGS = -I ${INCLUDE_DIR}
CFLAGS   = ${CFLAGS}
LDFLAGS  = -L ./lib ${LIBS}

.PHONY: all doc clean distclean

all: ./bin/${EXEC}

./bin/${EXEC}: ./src/main.o # And others .o
	\$(CC) \$< -o \$@ \$(LDFLAGS)

./src/%.o: ./src/%.c
	\$(CC) \$(CPPFLAGS) \$(${CFLAGS}) \$< -o \$@ -c

doc:
	-@\$(DOC) doc/Doxyfile

clean:
	-@\$(RM) ./src/*.o

distclean: clean
	-@\$(RM) ./bin/${EXEC}" > "$PROJECT_PATH"/Makefile
}

#
# 
#
function create_main() {
   cat > "$PROJECT_PATH/src/main.c"<<EOF
$ENTETE_C 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
   #define USAGE "Usage : %s text_file\n"

   if ((argc > 1) && (!strcasecmp("-h", argv[1]))) {
      fprintf(stderr, USAGE, argv[0]);
      return EXIT_FAILURE;
   }   
   
   /* Your code here ... */
   return EXIT_SUCCESS;
}
EOF
}

#
# 
#
function create_Doxyfile() {
   cat > "$PROJECT_PATH/doc/Doxyfile"<<EOF
PROJECT_NAME = "$PROJECT_PATH"
OUTPUT_DIRECTORY = doc
FILE_PATTERNS = include/*.h src/*.c
GENERATE_HTML = YES
GENERATE_LATEX = NO
GENERATE_RTF = NO
EOF
}

function copy_minunit() {
	wget -P "$PROJECT_PATH/include" https://raw.githubusercontent.com/siu/minunit/master/minunit.h
	wget -P "$PROJECT_PATH/src/test" https://raw.githubusercontent.com/siu/minunit/master/minunit_example.c
}

function validate_project_path() {
    if [[ -z "$1" ]]; then
        echo "Entrée invalide : le nom du projet ne peut être vide."
        return 1
    elif [[ $1 =~ [^a-zA-Z0-9_-] ]]; then
        echo "Entrée invalide : le nom du projet contient des caractères spéciaux."
        return 1
    fi
    return 0
}

function create_project() {
   echo "Entrer le nom du nouveau projet :"
   read -r PROJECT_PATH
   if ! validate_project_path "$PROJECT_PATH"; then
       return 1
   fi
   initialize_rep
   if [ "$?" == 0 ] 
   then
      create_README
      create_main
      customize_makefile
      create_Makefile
	  create_Doxyfile
	  copy_minunit
      echo "Projet $(basename "$PROJECT_PATH") créé."
   fi
}

#
# 
#
function open_project() {
   echo "Entrer le nom du projet à ouvrir :"
   read -r PROJECT_PATH
   if [ ! -e "$PROJECT_PATH" ] 
   then
      echo "Projet inexistant. Il va être créé."
      initialize_rep
      if [ "$?" == 0 ] 
      then
         create_README
         create_main
         customize_makefile
         create_Makefile
   	     create_Doxyfile
   	     copy_minunit
      fi
      echo "Projet $(basename "$PROJECT_PATH") créé."
      return 0
   else 
      if [ ! -d "$PROJECT_PATH" ] 
      then 
         echo "Un fichier porte déjà ce nom."
         PROJECT_PATH=""
         return 10
      else
         echo "Projet ouvert."	      
      fi
fi
}

#
# Creates a .TGZ compressed archive
# The archive filename indicates both authors and the current date
# using the format:
# PROJECT_DIRECTORY-NAME1-NAME2-day-month-year-hour:min.tgz
#
function create_archive() {
   author1=$( echo "$AUTHOR1" | cut -f2 -d' ' )
   author2=$( echo "$AUTHOR2" | cut -f2 -d' ' )
   currentdate=$( date +%d−%m−%Y-%H-%M )
   
   if [ -n "$PROJECT_PATH" ]; then
      cd "${PROJECT_PATH}" || return ; make distclean; cd .. ;   
      tar czf "$PROJECT_PATH-$author1-$author2-$currentdate.tgz" "$(basename "$PROJECT_PATH")"
   else
      error "Projet courant inexistant !" "create_archive()"
   fi
   echo "Archive du projet courant créée."
}

#
# Suppress the current C project
#
function suppress_project() {
   rm -R -f "$PROJECT_PATH" ;  
   echo "Projet courant supprimé."
}

#
# Compiles the current C project
#
function compile_project() {
   if [ -z "$PROJECT_PATH" ]
   then
      echo "Aucun projet ouvert."
      return 12
   fi
   cd "${PROJECT_PATH}" || return ; make ; cd .. ; 
   echo "Projet compilé."
}

#
# The main menu
#
function menu() {
   clear ; loop=y
   while [ $loop = y ]
   do
      echo "Générateur de squelette d'un projet C"  
      echo "====================================="
      echo "N|n : créer un nouveau projet"
      echo "O|o : ouvrir un projet"
      echo "S|s : supprimer le projet courant"
      echo "C|c : compiler le projet courant"
      echo "A|a : archiver le projet courant"
      echo "Q|q : quitter"
      echo
      read -s choix # silent mode with no echo
      case $choix in
         N|n) create_project ;;
         O|o) open_project ;;
         S|s) suppress_project ;;
         C|c) compile_project ;;
         A|a) create_archive ;;
         Q|q) loop=n ;;
           *) echo "Choix invalide !" ;;
      esac
      echo
   done 
}

# Début du script
if [ "$#" -gt 1 ]; then
    echo "Usage incorrect. Seule l'option '-h' est acceptée."
    exit 1
fi

if [ "$1" = "-h" ]; then
    help
fi

menu

exit 0

