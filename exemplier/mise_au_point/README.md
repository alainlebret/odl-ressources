[//]: # (----------------------------------------------------------------------)

[//]: # (------------------ Outils de développement logiciel ------------------)

[//]: # (--------------- Cours Ingénieur Informatique 1e année ----------------)

[//]: # (------------------------- E N S I C A E N ----------------------------)

[//]: # (----------------------- Alain Lebret, 2023 ---------------------------)

[//]: # (----------------------------------------------------------------------)

--------------------------------------------------------------------------------
                                   ENSICAEN
                           6 Boulevard Maréchal Juin
                              F-14050 Caen Cedex

                Examples from the course "Software development tools"
             Exemplier du cours "Outils de développement logiciel" (ODL)

         Chapter "Debugging, testing, profiling" / Chapitre "Mise au point"

           Copyright (C) 1995-2023 Alain Lebret (alain.lebret@ensicaen.fr)
--------------------------------------------------------------------------------
							   
These examples show how to:

- use the GNU debugger (_gdb_);
- put traces;
- use `assert()` function;
- identify memory leaks using `valgrind` command;
- use the GNU profiler (`gprof`);
- measure time (using `time` command or `clock()` function);
- use random numbers to test programs.

To compile the examples, just run the command:

```default
$ make
```

To remove them:

```default
$ make clean
```
