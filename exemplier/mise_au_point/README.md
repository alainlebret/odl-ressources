# Debugging Examples (Mise au Point)

## Introduction
The `mise_au_point` directory offers a collection of examples and exercises focused on debugging techniques in software development. These resources are part of the Software Development Tools course at ENSICAEN and are designed to help students understand and apply various debugging strategies.

## Contents
This directory includes practical examples that demonstrate common debugging scenarios, the use of debugging tools, and techniques to identify and resolve software bugs. The examples cover a range of programming languages and environments.

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

## How to Use
To engage with these debugging examples:
1. Clone the repository: `git clone https://github.com/alainlebret/odl.git`
2. Navigate to the `mise_au_point` directory: `cd odl/exemplier/mise_au_point`
3. Review each example, focusing on the techniques and tools used for debugging.

## Prerequisites
- Familiarity with programming concepts and languages used in the examples (e.g., C, Bash).
- Basic knowledge of debugging tools and environments.

## License
The materials in this directory are provided under the Apache 2.0 license. For more details, see the LICENSE file in the root directory.

