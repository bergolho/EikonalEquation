#!/bin/bash
PNAME="./bin/HeatEquation"

if [ ! -f $PNAME ]; then
	./recompile_project.sh
fi

valgrind --leak-check=full --show-leak-kinds=all $PNAME 50 1 10 1 2 10
