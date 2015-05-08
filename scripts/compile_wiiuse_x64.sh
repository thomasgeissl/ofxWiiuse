#!/bin/sh
mkdir -p ../wiiuse/build
cd ../wiiuse/build
cmake .. 
make
sudo make install
