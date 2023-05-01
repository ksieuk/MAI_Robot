#!/bin/sh

cd /home/sergh/

mkdir build

cd build

cmake ../.

make

tail -f /dev/null