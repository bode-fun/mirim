#!/bin/sh

CFLAGS="$(cat compile_flags.txt)"

echo "Building Mirim's source"

clang++ $CFLAGS -o mirim Sources/main.cpp
