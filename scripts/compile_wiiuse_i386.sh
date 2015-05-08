#!/bin/sh
mkdir -p ../wiiuse/build
cd ../wiiuse/build
cmake .. -DCMAKE_CXX_FLAGS=-m32 -DCMAKE_C_FLAGS=-m32
make
sudo make install
