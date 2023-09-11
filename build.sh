#!/bin/sh

CFLAGS="$(cat compile_flags.txt)"

clang++ $CFLAGS -o mirim Sources/main.cpp
